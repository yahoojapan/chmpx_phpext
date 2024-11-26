/*
 * CHMPX PHP Extension library
 *
 * Copyright 2015 Yahoo Japan corporation.
 *
 * CHMPX is inprocess data exchange by MQ with consistent hashing.
 * CHMPX is made for the purpose of the construction of
 * original messaging system and the offer of the client
 * library.
 * CHMPX transfers messages between the client and the server/
 * slave. CHMPX based servers are dispersed by consistent
 * hashing and are automatically layouted. As a result, it
 * provides a high performance, a high scalability.
 *
 * For the full copyright and license information, please view
 * the LICENSE file that was distributed with this source code.
 *
 * AUTHOR:   nakatani@yahoo-corp.jp
 * CREATE:   Mon Mar 16 2015
 * REVISION:
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

// cppcheck-suppress missingInclude
#include "php.h"
// cppcheck-suppress missingInclude
#include "ext/standard/info.h"
#include "php_chmpxpx.h"
#include "chmpxpx_arginfo.h"

// class entries
zend_class_entry* chmpx_class_entry;
zend_class_entry* chmpx_server_class_entry;
zend_class_entry* chmpx_slave_class_entry;

zval* chmpxpx_read_property_resource(zend_class_entry* scope, zval* object, const char* name) {
	zval* pzval, tmp;
#if PHP_VERSION_ID < 80000
	pzval = zend_read_property(scope, object, name, strlen(name), 1, &tmp);
#else
	pzval = zend_read_property(scope, Z_OBJ_P(object), name, strlen(name), 1, &tmp);
#endif
	if(IS_RESOURCE != Z_TYPE_P(pzval)){
		php_error(E_ERROR, "The property(%s) is not a resource type.", name);
	}
	return pzval;
}

void chmpxpx_update_property_resource(zend_class_entry* scope, zval* object, const char* name, size_t name_length, zval* value) {
#if PHP_VERSION_ID < 80000
	zend_update_property(scope, object, name, name_length, value);
#else
	zend_update_property(scope, Z_OBJ_P(object), name, name_length, value);
#endif
}

int chmpx_handle_resource_number;
zend_resource* chmpx_handle_resource;
static void chmpx_handle_resource_dtor(zend_resource* rsrc)
{
	efree((chmpx_h*)rsrc->ptr);
}

int msgid_handle_resource_number;
zend_resource* msgid_handle_resource;
static void msgid_handle_resource_dtor(zend_resource* rsrc)
{
	efree((msgid_t*)rsrc->ptr);
}

int chmpx_pkt_handle_resource_number;
zend_resource* chmpx_pkt_handle_resource;
static void chmpx_pkt_handle_resource_dtor(zend_resource* rsrc)
{
	efree((chmpx_pkt_h*)rsrc->ptr);
}
int is_server_mode_resource_number;
zend_resource* is_server_mode_resource;
static void is_server_mode_resource_dtor(zend_resource* rsrc)
{
	efree((bool*)rsrc->ptr);
}

PHP_FUNCTION(chmpxpx_destroy)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpxpx_destroy: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	
	// call_some_functions after get_resources
	chmpx_destroy(*chmpx_handle_ptr);
	
	// return_result after call_some_functions
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_slv_receive)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL;
	zval* zval_msgid_handle_ptr = NULL;
	zval* strbinary = NULL; // Pass by Reference
	zend_long timeout_ms = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		Z_PARAM_RESOURCE(zval_msgid_handle_ptr)
		Z_PARAM_ZVAL(strbinary)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_receive: handle is empty.");
		RETURN_FALSE;
	}
	ZEND_ASSERT(Z_TYPE_P(zval_msgid_handle_ptr) == IS_RESOURCE);
	if(!zval_msgid_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_receive: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	// chmpx_handle resource
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	// msgid_handle resource
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle_resource", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	// chmpx_msg_receive
	chmpx_pkt_h chmpx_pkt_handle = 0L;
	unsigned char* pbody = NULL;
	size_t length = 0;
	bool bResult = chmpx_msg_receive(*chmpx_handle_ptr, *msgid_handle_ptr, &chmpx_pkt_handle, &pbody, &length, (int)timeout_ms);

	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_ERROR, "chmpxpx_slv_receive: could not receive data, probably there is no received data by timeout.");
		RETURN_FALSE;
	}
	if(Z_ISREF_P(strbinary)) {
		// See https://www.phpinternalsbook.com/php7/zvals/references.html
		ZVAL_DEREF(strbinary); // dereferencing
	}
	zval_ptr_dtor(strbinary); // initialize the zval(decrements to refcount=0, and destroys the string if exists)
	ZVAL_STRINGL(strbinary, (char*)pbody, length);
	if(pbody){
		free(pbody);
	}
	// chmpx_pkth_destroy
	if(0L != chmpx_pkt_handle && !chmpx_pkth_destroy(chmpx_pkt_handle)){
		php_error(E_WARNING, "chmpxpx_slv_receive: could not close chmpx packet handler.");
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_svr_receive_kv)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL;
	zval* strbinkey = NULL; // Pass by Reference
	zval* strbinval = NULL; // Pass by Reference
	zend_long timeout_ms = RCV_NO_WAIT;
	zend_bool no_giveup_rejoin = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		Z_PARAM_ZVAL(strbinkey)
		Z_PARAM_ZVAL(strbinval)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		Z_PARAM_BOOL(no_giveup_rejoin)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_svr_receive_kv: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	// chmpx_svr_receive
	chmpx_pkt_h chmpx_pkt_handle = 0L;
	unsigned char* pbody = NULL;
	size_t length = 0;
	if(!chmpx_svr_receive(*chmpx_handle_ptr, &chmpx_pkt_handle, &pbody, &length, (int)timeout_ms, 0 != no_giveup_rejoin ? true : false)){
		php_error(E_WARNING, "chmpxpx_svr_receive: could not receive data, probably there is no received data by timeout.");
		RETURN_FALSE;
	}
	if(0L == chmpx_pkt_handle){
		// no error, but no received data.
		RETURN_FALSE;
	}
	CHMKVP kvp;
	if(cvt_bin_kvp(&kvp, pbody, length)){
		// copy received data to each
		if(Z_ISREF_P(strbinkey)) {
			// See https://www.phpinternalsbook.com/php7/zvals/references.html
			ZVAL_DEREF(strbinkey);	// dereferencing
		}
		zval_ptr_dtor(strbinkey); // initialize the zval(decrements to refcount=0, and destroys the string if exists)
		ZVAL_STRINGL(strbinkey, (char*)kvp.key.byptr, kvp.key.length);

		if(Z_ISREF_P(strbinval)) {
			// See https://www.phpinternalsbook.com/php7/zvals/references.html
			ZVAL_DEREF(strbinval);	// dereferencing
		}
		zval_ptr_dtor(strbinval); // initialize the zval(decrements to refcount=0, and destroys the string if exists)
		ZVAL_STRINGL(strbinval, (char*)kvp.val.byptr, kvp.val.length);
	}
	if(pbody){
		free(pbody);
	}

	// return_result after call_some_functions
	chmpx_pkt_h* chmpx_pkt_handle_ptr; // like a file pointer
	chmpx_pkt_handle_ptr = emalloc(sizeof(long));
	if (chmpx_pkt_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*chmpx_pkt_handle_ptr = chmpx_pkt_handle;
	RETURN_RES(zend_register_resource(chmpx_pkt_handle_ptr, chmpx_pkt_handle_resource_number)); // RETVAL_RES(r) and ZVAL_RES(return_value, r)
}

PHP_FUNCTION(chmpxpx_svr_receive)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL; // chmpx_handle_resource
	zval* strbinary = NULL; // Pass by Reference
	zend_long timeout_ms = RCV_NO_WAIT;
	zend_bool no_giveup_rejoin = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		Z_PARAM_ZVAL(strbinary)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		Z_PARAM_BOOL(no_giveup_rejoin)
		ZEND_PARSE_PARAMETERS_END();
	
	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_msgid_close: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	chmpx_pkt_h chmpx_pkt_handle = 0L;
	unsigned char* pbody = NULL;
	size_t length = 0;
	bool bResult = chmpx_svr_receive(*chmpx_handle_ptr, &chmpx_pkt_handle, &pbody, &length, (int)timeout_ms, 0 != no_giveup_rejoin ? true : false);

	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_WARNING, "chmpxpx_svr_receive: could not receive data, probably there is no received data by timeout.");
		RETURN_FALSE;
	}
	if(0L == chmpx_pkt_handle){
		// no error, but no received data.
		RETURN_FALSE;
	}
	if(Z_ISREF_P(strbinary)) {	// copy received data
		// See https://www.phpinternalsbook.com/php7/zvals/references.html
		ZVAL_DEREF(strbinary);	// dereferencing
	}
	zval_ptr_dtor(strbinary); // initialize the zval(decrements to refcount=0, and destroys the string if exists)
	ZVAL_STRINGL(strbinary, (char*)pbody, length - 1);
	if(pbody){
		free(pbody);
	}
	// register the chmpx_pkt_handle to chmpx_pkt_handle_resource_number. The resource will destroy by using chmpx_pkt_handle_resource_dtor
	chmpx_pkt_h* chmpx_pkt_handle_ptr; // like a file pointer
	chmpx_pkt_handle_ptr = emalloc(sizeof(long));
	if (chmpx_pkt_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*chmpx_pkt_handle_ptr = chmpx_pkt_handle;
	RETURN_RES(zend_register_resource(chmpx_pkt_handle_ptr, chmpx_pkt_handle_resource_number)); // RETVAL_RES(r) and ZVAL_RES(return_value, r)
}

PHP_FUNCTION(chmpxpx_slv_send)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL;
	zval* zval_msgid_handle_ptr = NULL;
	char* strbinary = NULL;
	size_t strbinary_len = 0;
	zend_bool is_routing = true;
	zend_bool is_broadcast = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		Z_PARAM_RESOURCE(zval_msgid_handle_ptr)
		Z_PARAM_STRING(strbinary, strbinary_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_routing)
		Z_PARAM_BOOL(is_broadcast)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_send: handle is empty.");
		RETURN_FALSE;
	}
	ZEND_ASSERT(Z_TYPE_P(zval_msgid_handle_ptr) == IS_RESOURCE);
	if(!zval_msgid_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_send: handle is empty.");
		RETURN_FALSE;
	}

	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle_resource", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_ERROR, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	CHMBIN chmbinary;
	chmbinary.byptr = (unsigned char*)strbinary;
	chmbinary.length = (size_t)(strbinary_len + 1);
	chmhash_t hashval = make_chmbin_hash(&chmbinary);
	long rcvcnt = 0;

	// return_result after call_some_functions
	bool bResult;
	if(is_broadcast){
		// broadcast
		if(false == (bResult = chmpx_msg_broadcast(*chmpx_handle_ptr, *msgid_handle_ptr, (const unsigned char*)strbinary, (size_t)(strbinary_len + 1), hashval, &rcvcnt))){
			php_error(E_ERROR, "chmpxpx_slv_send: failed send binary data. result %d rcvcnt %ld", bResult, rcvcnt);
			RETURN_FALSE;
		}
	}else{
		if(false == (bResult = chmpx_msg_send(*chmpx_handle_ptr, *msgid_handle_ptr, (const unsigned char*)strbinary, (size_t)(strbinary_len + 1), hashval, &rcvcnt, 0 != is_routing ? true : false))){
			php_error(E_ERROR, "chmpxpx_slv_send: failed send binary data. result %d rcvcnt %ld", bResult, rcvcnt);
			RETURN_FALSE;
		}
	}

	// return_result after call_some_functions
	RETURN_LONG((long)rcvcnt); // RETVAL_LONG(l) and ZVAL_LONG(return_value, l)
}

PHP_FUNCTION(chmpxpx_msgid_open)
{
	// declare_variables
	zval* zval_zval_chmpx_handle_ptr = NULL; // userland zval
	zend_bool no_giveup_rejoin = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_RESOURCE(zval_zval_chmpx_handle_ptr)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(no_giveup_rejoin)
		ZEND_PARSE_PARAMETERS_END();
	
	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_zval_chmpx_handle_ptr) == IS_RESOURCE); /* just a check to be sure */
	if(!zval_zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "msgid_createy: handle is empty.");
		RETURN_FALSE;
	}

	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	msgid_t msgid_handle = chmpx_open(*chmpx_handle_ptr, 0 != no_giveup_rejoin ? true : false);
	if(CHM_INVALID_CHMPXHANDLE == msgid_handle) {
		php_error(E_NOTICE, "chmpxpx_open: failed to open msgid on slave CHMPX.");
		RETURN_FALSE;
	}

	// return_result after call_some_functions
	msgid_t* msgid_handle_ptr; // like a file pointer
	msgid_handle_ptr = emalloc(sizeof(long));
	if (msgid_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*msgid_handle_ptr = msgid_handle;
	RETURN_RES(zend_register_resource(msgid_handle_ptr, msgid_handle_resource_number)); // RETVAL_RES(r) and ZVAL_RES(return_value, r)
}

static void chmpx_create_opt(INTERNAL_FUNCTION_PARAMETERS, int opt)
{
	// declare_variables
	char* filepath = NULL;
	size_t filepath_len = 0;
	zend_bool is_on_server = true;
	zend_bool is_auto_rejoin = false;

	switch (opt) {
	case 0:
	case 1:
		is_on_server = true;
		break;
	case 2:
		is_on_server = false;
		break;
	default:
		RETURN_FALSE;
	}
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STRING(filepath, filepath_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_on_server)
		Z_PARAM_BOOL(is_auto_rejoin)
		ZEND_PARSE_PARAMETERS_END();
	
	// validate_after_assign
	if(!filepath || 0 == filepath_len){
		php_error(E_ERROR, "chmpxpx_create: CHMPX configuration file path is empty.");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	chmpx_h chmpx_handle = chmpx_create(filepath, 0 != is_on_server ? true : false, 0 != is_auto_rejoin ? true : false);
	if(CHM_INVALID_CHMPXHANDLE == chmpx_handle) {
		php_error(E_NOTICE, "chmpxpx_create: failed to open(join) CHMPX.");
		RETURN_FALSE;
	}
	
	// return_result after call_some_functions
	chmpx_h* chmpx_handle_ptr = emalloc(sizeof(long)); // this resource destroy by using chmpx_handle_resource_dtor
	if (chmpx_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*chmpx_handle_ptr = chmpx_handle;
	RETURN_RES(zend_register_resource(chmpx_handle_ptr, chmpx_handle_resource_number)); // RETVAL_RES(r) and ZVAL_RES(return_value, r)
}

PHP_FUNCTION(chmpxpx_create)
{
	chmpx_create_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 0);
}

PHP_FUNCTION(chmpxpx_create_server)
{
	chmpx_create_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 1);
}

PHP_FUNCTION(chmpxpx_create_slave)
{
	chmpx_create_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 2);
}

PHP_FUNCTION(chmpxpx_bump_debug_level)
{
	chmpx_bump_debug_level();
}

PHP_FUNCTION(chmpxpx_set_debug_level_silent)
{
	chmpx_set_debug_level_silent();
}

PHP_FUNCTION(chmpxpx_set_debug_level_error)
{
	chmpx_set_debug_level_error();
}

PHP_FUNCTION(chmpxpx_set_debug_level_warning)
{
	chmpx_set_debug_level_warning();
}

PHP_FUNCTION(chmpxpx_set_debug_level_message)
{
	chmpx_set_debug_level_message();
}

PHP_FUNCTION(chmpxpx_set_debug_file)
{
	// declare_variables
	char* filepath = NULL;
	size_t filepath_len = 0;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(filepath, filepath_len)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	if(!filepath || 0 == filepath_len) {
		php_error_docref(NULL, E_ERROR, "chmpx_set_debug_file: filepath is empty.");
		RETURN_FALSE;
	}
	
	// call_some_functions after get_resources
	bool bResult = chmpx_set_debug_file(filepath);
	
	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_NOTICE, "chmpxpx_set_debug_file: failed to set debugging file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_unset_debug_file)
{
	if(!chmpx_unset_debug_file()){
		php_error(E_NOTICE, "chmpxpx_unset_debug_file: failed to unset debugging file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_load_debug_env)
{
	if(!chmpx_load_debug_env()){
		php_error(E_NOTICE, "chmpxpx_load_debug_env: failed to load environment about debugging.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_load_hash_library)
{
	// declare_variables
	char* filepath = NULL;
	size_t filepath_len = 0;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(filepath, filepath_len)
		ZEND_PARSE_PARAMETERS_END();
	
	// validate_after_assign
	if(!filepath || 0 == filepath_len){
		php_error(E_ERROR, "chmpxpx_load_hash_library: filepath is empty.");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	bool bResult = chmpx_load_hash_library(filepath);

	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_NOTICE, "chmpxpx_load_hash_library: failed to set hash library file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_unload_hash_library)
{
	if(!chmpx_unload_hash_library()){
		php_error(E_NOTICE, "chmpxpx_unload_hash_library: failed to unset hash library file path.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_process_running)
{
	// declare_variables
	zval* zval_zval_chmpx_handle_ptr = NULL; // userland zval
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(zval_zval_chmpx_handle_ptr)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_zval_chmpx_handle_ptr) == IS_RESOURCE); /* just a check to be sure */
	if(!zval_zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpxpx_destroy: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	
	// call_some_functions after get_resources
	bool bResult = is_chmpx_proc_exists(*chmpx_handle_ptr);

	// return_result after call_some_functions
	if (!bResult) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_msgid_close)
{
	// declare_variables
	zval* zval_zval_chmpx_handle_ptr = NULL; // userland zval
	zval* zval_zval_msgid_handle_ptr = NULL; // userland zval
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_RESOURCE(zval_zval_chmpx_handle_ptr)
		Z_PARAM_RESOURCE(zval_zval_msgid_handle_ptr)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_zval_chmpx_handle_ptr) == IS_RESOURCE); /* just a check to be sure */
	if(!zval_zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_msgid_close: handle is empty.");
		RETURN_FALSE;
	}
	ZEND_ASSERT(Z_TYPE_P(zval_zval_msgid_handle_ptr) == IS_RESOURCE); /* just a check to be sure */
	if(!zval_zval_msgid_handle_ptr) {
		php_error(E_ERROR, "chmpx_msgid_close: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_zval_msgid_handle_ptr), "msgid_handle_resource", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}
	
	// call_some_functions after get_resources
	bool bResult = chmpx_close(*chmpx_handle_ptr, *msgid_handle_ptr);

	// return_result after call_some_functions
	if (!bResult) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_pkth_close)
{
	// declare_variables
	zval* zval_chmpx_pkt_handle_resource_ptr = NULL;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_RESOURCE(zval_chmpx_pkt_handle_resource_ptr)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_pkt_handle_resource_ptr) == IS_RESOURCE); /* just a check to be sure */
	if(!zval_chmpx_pkt_handle_resource_ptr) {
		php_error(E_ERROR, "chmpxpx_destroy: handle is empty.");
		RETURN_FALSE;
	}
	
	// get_resources
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_resource_ptr), "chmpx_pkt_handle_resource", chmpx_pkt_handle_resource_number);
	
	// call_some_functions after get_resources
	bool bResult = chmpx_pkth_destroy(*chmpx_pkt_handle_ptr);
	
	// return_result after call_some_functions
	if(0L != *chmpx_pkt_handle_ptr && !bResult) {
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_svr_reply)
{
	// declare_variables
	zval* zval_zval_chmpx_handle_ptr = NULL;
	zval* zval_chmpx_pkt_handle_resource_ptr = NULL;
	char* strbinary = NULL;
	size_t strbinary_len = 0;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_RESOURCE(zval_zval_chmpx_handle_ptr)
		Z_PARAM_RESOURCE(zval_chmpx_pkt_handle_resource_ptr)
		Z_PARAM_STRING(strbinary, strbinary_len)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_zval_chmpx_handle_ptr) == IS_RESOURCE); /* just a check to be sure */
	if(!zval_zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_svr_reply: handle is empty.");
		RETURN_FALSE;
	}
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_pkt_handle_resource_ptr) == IS_RESOURCE); /* just a check to be sure */
	if(!zval_chmpx_pkt_handle_resource_ptr) {
		php_error(E_ERROR, "chmpx_svr_reply: handle is empty.");
		RETURN_FALSE;
	}

	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_resource_ptr), "chmpx_pkt_handle_resource", chmpx_pkt_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_pkt_handle_ptr){
		php_error(E_NOTICE, "chmpx_pkt_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	bool bResult = chmpx_msg_reply(*chmpx_handle_ptr, *chmpx_pkt_handle_ptr, (const unsigned char*)strbinary, (size_t)strbinary_len);

	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_ERROR, "chmpxpx_svr_reply: failed send binary data.");
		RETURN_FALSE;
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_svr_reply_kv)
{
	// declare_variables
	zval* zval_zval_chmpx_handle_ptr = NULL; // chmpx_handle_resource
	zval* zval_chmpx_pkt_handle_resource_ptr = NULL; // chmpx_pkt_handle_resource
	char* strbinkey = NULL;
	size_t strbinkey_len = 0;
	char* strbinval = NULL;
	size_t strbinval_len = 0;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_RESOURCE(zval_zval_chmpx_handle_ptr)
		Z_PARAM_RESOURCE(zval_chmpx_pkt_handle_resource_ptr)
		Z_PARAM_STRING(strbinkey, strbinkey_len)
		Z_PARAM_STRING(strbinval, strbinval_len)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_svr_reply: handle is empty.");
		RETURN_FALSE;
	}
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_pkt_handle_resource_ptr) == IS_RESOURCE);
	if(!zval_chmpx_pkt_handle_resource_ptr) {
		php_error(E_ERROR, "chmpx_svr_reply: handle is empty.");
		RETURN_FALSE;
	}

	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_LONG(-1);
	}
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_resource_ptr), "chmpx_pkt_handle_resource", chmpx_pkt_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_pkt_handle_ptr){
		php_error(E_NOTICE, "chmpx_pkt_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	CHMKVP 	kvp;
	kvp.key.byptr	= (unsigned char*)strbinkey;
	kvp.key.length	= (size_t)strbinkey_len;
	kvp.val.byptr	= (unsigned char*)strbinval;
	kvp.val.length	= (size_t)strbinval_len;
	size_t	length	= 0;
	unsigned char*	pdata;
	if(NULL == (pdata = cvt_kvp_bin(&kvp, &length))){
		php_error(E_ERROR, "chmpxpx_svr_reply_kv: something error occurred in converting key and value to binary data.");
		RETURN_FALSE;
	}
	bool bResult = chmpx_msg_reply(*chmpx_handle_ptr, *chmpx_pkt_handle_ptr, pdata, length);

	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_ERROR, "chmpxpx_svr_reply_kv: failed send binary data.");
		if(pdata){
			free(pdata);
		}
		RETURN_FALSE;
	} else {
		if(pdata){
			free(pdata);
		}
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_slv_receive_kv)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL; // chmpx_handle_resource
	zval* zval_msgid_handle_ptr = NULL; // msgid_handle_resource
	zval* strbinkey = NULL;
	zval* strbinval = NULL;
	zend_long timeout_ms = RCV_NO_WAIT;
	
	// validate_after_assign
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		Z_PARAM_RESOURCE(zval_msgid_handle_ptr)
		Z_PARAM_ZVAL(strbinkey)
		Z_PARAM_ZVAL(strbinval)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_receive_kv: handle is empty.");
		RETURN_FALSE;
	}
	ZEND_ASSERT(Z_TYPE_P(zval_msgid_handle_ptr) == IS_RESOURCE);
	if(!zval_msgid_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_receive_kv: handle is empty.");
		RETURN_FALSE;
	}

	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle_resource", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}

	// call chmpx_msg_receive using the chmpx_h pointer and get chmpx_pkt_handle
	chmpx_pkt_h chmpx_pkt_handle = 0L;
	unsigned char* pbody = NULL;
	size_t length = 0;
	bool bResult = chmpx_msg_receive(*chmpx_handle_ptr, *msgid_handle_ptr, &chmpx_pkt_handle, &pbody, &length, (int)timeout_ms);

	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_ERROR, "chmpxpx_slv_receive_kv: could not receive data, probably there is no received data by timeout.");
		RETURN_FALSE;
	}
	CHMKVP 	kvp;	// copy received data
	if(cvt_bin_kvp(&kvp, pbody, length)){
		if(Z_ISREF_P(strbinkey)) {
			// See https://www.phpinternalsbook.com/php7/zvals/references.html
			ZVAL_DEREF(strbinkey);	// dereferencing
		}
		zval_ptr_dtor(strbinkey); // initialize the zval(decrements to refcount=0, and destroys the string if exists)
		ZVAL_STRINGL(strbinkey, (char*)kvp.key.byptr, kvp.key.length);

		if(Z_ISREF_P(strbinval)) {
			// See https://www.phpinternalsbook.com/php7/zvals/references.html
			ZVAL_DEREF(strbinval);	// dereferencing
		}
		zval_ptr_dtor(strbinval); // initialize the zval(decrements to refcount=0, and destroys the string if exists)
		ZVAL_STRINGL(strbinval, (char*)kvp.val.byptr, kvp.val.length);
	}
	if(pbody){
		free(pbody);
	}
	if(0L != chmpx_pkt_handle && !chmpx_pkth_destroy(chmpx_pkt_handle)){
		php_error(E_WARNING, "chmpxpx_slv_receive_kv: could not close chmpx packet handler.");
	}
	RETURN_TRUE;
}

PHP_FUNCTION(chmpxpx_slv_send_kv)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL;
	zval* zval_msgid_handle_ptr = NULL;
	char* strbinkey = NULL;
	size_t strbinkey_len = 0;
	char* strbinval = NULL;
	size_t strbinval_len = 0;
	zend_bool is_routing = true;
	zend_bool is_broadcast = false;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(4, 6)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		Z_PARAM_RESOURCE(zval_msgid_handle_ptr)
		Z_PARAM_STRING(strbinkey, strbinkey_len)
		Z_PARAM_STRING(strbinval, strbinval_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_routing)
		Z_PARAM_BOOL(is_broadcast)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_send_kv: handle is empty.");
		RETURN_FALSE;
	}
	ZEND_ASSERT(Z_TYPE_P(zval_msgid_handle_ptr) == IS_RESOURCE);
	if(!zval_msgid_handle_ptr) {
		php_error(E_ERROR, "chmpx_slv_send_kv: handle is empty.");
		RETURN_FALSE;
	}

	// get_resources
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle_resource", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle_resource", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	CHMKVP 	kvp;
	kvp.key.byptr	= (unsigned char*)strbinkey;
	kvp.key.length	= (size_t)(strbinkey_len);
	kvp.val.byptr	= (unsigned char*)strbinval;
	kvp.val.length	= (size_t)(strbinval_len);
	size_t			length = 0;
	unsigned char*	pdata;
	if(NULL == (pdata = cvt_kvp_bin(&kvp, &length))){
		php_error(E_ERROR, "chmpxpx_slv_send_kv: something error occurred in converting key and value to binary data.");
		RETURN_FALSE;
	}
	chmhash_t	hashval	= make_kvp_hash(&kvp);	// make hash value
	long		rcvcnt	= 0;
	bool		bResult = false;
	if(is_broadcast){
		// broadcast
		if(false == (bResult = chmpx_msg_broadcast(*chmpx_handle_ptr, *msgid_handle_ptr, pdata, length, hashval, &rcvcnt))){
			php_error(E_ERROR, "chmpxpx_slv_send_kv: failed broadcast binary data.");
			if(pdata){
				free(pdata);
			}
			RETURN_FALSE;
		} else {
			if(pdata){
				free(pdata);
			}
		}
	}else{
		if(false == (bResult = chmpx_msg_send(*chmpx_handle_ptr, *msgid_handle_ptr, pdata, length, hashval, &rcvcnt, 0 != is_routing ? true : false))){
			php_error(E_ERROR, "chmpxpx_slv_send_kv: failed send binary data.");
			if(pdata){
				free(pdata);
			}
			RETURN_FALSE;
		} else {
			if(pdata){
				free(pdata);
			}
		}
	}
	
	// return_result after call_some_functions
	RETURN_LONG((long)rcvcnt);
}

PHP_FUNCTION(chmpxpx_print_version)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		ZEND_PARSE_PARAMETERS_END();

	
	// validate_after_assign
	if(zval_chmpx_handle_ptr) {
		ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	}

	// call_some_functions after get_resources
	FILE*	fp = stderr;
	if(zval_chmpx_handle_ptr){
		php_stream* res_output = NULL;
		php_stream_from_zval(res_output, zval_chmpx_handle_ptr);
		if(FAILURE == php_stream_cast(res_output, PHP_STREAM_AS_STDIO, (void**)&fp, REPORT_ERRORS)){
			php_error(E_ERROR, "chmpxpx_print_version: failed to convert php stream to FILE.");
			RETURN_FALSE;
		}
	}
	chmpx_print_version(fp);
	
	// return_result after call_some_functions
	RETURN_TRUE;
}

//
// PHP MODULE MACROS STARTS
//
// cppcheck-suppress unknownMacro
ZEND_DECLARE_MODULE_GLOBALS(chmpxpx);

PHP_INI_BEGIN()
	STD_PHP_INI_ENTRY(
					  "chmpxpx.debug",      /* configuration directive name */
					  "silent",             /* default value */
					  PHP_INI_ALL,          /* can be  modified at any time */
					  OnUpdateString,       /* callback function to set the string value of the directive */
					  chmpxpx_debug,        /* module global variable name */
					  zend_chmpxpx_globals, /* structure name to keep module global variables */
					  chmpxpx_globals       /* global variable to keep module global variables for a non-thread-safe build */
					  )
PHP_INI_END();
	 
PHP_MINIT_FUNCTION(chmpxpx)
{
	// register destructors
	// zend_register_list_destructors_ex must be called inside a PHP_MINIT function
	//
	// chmpx_handle
	chmpx_handle_resource_number = zend_register_list_destructors_ex(chmpx_handle_resource_dtor, NULL, "chmpx_handle", module_number);

	// msgid_handle
	msgid_handle_resource_number = zend_register_list_destructors_ex(msgid_handle_resource_dtor, NULL, "msgid_handle", module_number);

	// chmpx_pkt_handle
	chmpx_pkt_handle_resource_number = zend_register_list_destructors_ex(chmpx_pkt_handle_resource_dtor, NULL, "chmpx_pkt_handle", module_number);

	// chmpx_pkt_handle
	is_server_mode_resource_number = zend_register_list_destructors_ex(is_server_mode_resource_dtor, NULL, "is_server_mode", module_number);

	// register class entries
	// Chmpx
	chmpx_class_entry = register_class_Chmpx();

	// ChmpxServer
	chmpx_server_class_entry = register_class_ChmpxServer();
	zend_declare_class_constant_long(chmpx_server_class_entry, "CHM_INVALID_HANDLE", sizeof("CHM_INVALID_HANDLE")-1, CHM_INVALID_HANDLE);

	// ChmpxSlave
	chmpx_slave_class_entry = register_class_ChmpxSlave();

#if defined(ZTS) && defined(COMPILE_DL_CHMPXPX)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	// CONST_CS case sensitive
	// CONST_PERSISTENT persistent
	REGISTER_LONG_CONSTANT("RCV_NO_WAIT", RCV_NO_WAIT, CONST_CS | CONST_PERSISTENT);

	// INI
	REGISTER_INI_ENTRIES();

	return SUCCESS;
}

PHP_MINFO_FUNCTION(chmpxpx)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "chmpxpx support", "enabled");
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(chmpxpx)
{
#if defined(COMPILE_DL_BCMATH) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	chmpxpx_globals->chmpxpx_debug = "silent";
}

PHP_RINIT_FUNCTION(chmpxpx)
{
#if defined(ZTS) && defined(COMPILE_DL_CHMPXPX)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	char* dbgmode = CHMPXPX_G(chmpxpx_debug);
	if(!dbgmode || 0 == strcmp(dbgmode, "silent")) {
		chmpx_set_debug_level_silent();
	} else if(0 == strcmp(dbgmode, "message")) {
		chmpx_set_debug_level_message();
	} else if(0 == strcmp(dbgmode, "warning")) {
		chmpx_set_debug_level_warning();
	} else if(0 == strcmp(dbgmode, "error")) {
		chmpx_set_debug_level_error();
	} else {
		chmpx_set_debug_level_silent();
	}

	return SUCCESS;
}

zend_module_entry chmpxpx_module_entry = {
	STANDARD_MODULE_HEADER,
	"chmpxpx", /* Extension name */
	ext_functions, /* zend_function_entry */
	PHP_MINIT(chmpxpx), /* PHP_MINIT - Module initialization */
	NULL, /* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(chmpxpx), /* PHP_RINIT - Request initialization */
	NULL, /* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(chmpxpx), /* PHP_MINFO - Module info */
	PHP_CHMPXPX_VERSION, /* Version */
	PHP_MODULE_GLOBALS(chmpxpx), /* Module globals */
	PHP_GINIT(chmpxpx), /* PHP_GINIT – Globals initialization */
	NULL, /* PHP_GSHUTDOWN – Globals shutdown */
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_CHMPXPX
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
	ZEND_GET_MODULE(chmpxpx)
#endif

//
// PHP MODULE MACROS ENDS
//

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
