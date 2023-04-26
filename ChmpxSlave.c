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
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_chmpxpx.h"

PHP_METHOD(ChmpxSlave, __construct)
{
	// declare_variables
	zval* zval_chmpx_handle_ptr = NULL;
	zend_bool no_giveup_rejoin = false;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_RESOURCE(zval_chmpx_handle_ptr)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(no_giveup_rejoin)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	ZEND_ASSERT(Z_TYPE_P(zval_chmpx_handle_ptr) == IS_RESOURCE);
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpxpx_destroy: handle is empty.");
		RETURN_FALSE;
	}

	// get_props
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle", strlen("chmpx_handle"), zval_chmpx_handle_ptr);
	// get_resources after get_props
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// ERROR
		RETURN_FALSE;
	}
	
	// msgid_handle
	// Firstly, create a handle
	msgid_t* msgid_handle_ptr = emalloc(sizeof(long));
	if (msgid_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	if(CHM_INVALID_CHMPXHANDLE == (*msgid_handle_ptr = chmpx_open(*chmpx_handle_ptr, 0 != no_giveup_rejoin ? true : false))){
		php_error(E_NOTICE, "failed to open msgid on slave CHMPX.");
		RETURN_FALSE;
	}
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "failed to open msgid on slave CHMPX.");
		RETURN_FALSE;
	}
	// Secondarily, create a zend_resource with the chmpx handle
	zend_resource* my_msgid_handle_ptr = zend_register_resource(msgid_handle_ptr, msgid_handle_resource_number);
	// Thirdly, create a zval with the zend_resource
	zval zval_new_msgid_handle;
	ZVAL_RES(&zval_new_msgid_handle, my_msgid_handle_ptr);
	// Finally, set the zend_resource with this object
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "msgid_handle", strlen("msgid_handle"), &zval_new_msgid_handle);

}

PHP_METHOD(ChmpxSlave, __destruct)
{
	// get_props
	// chmpx_handle property
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	// msgid_handle property
	zval* zval_msgid_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "msgid_handle");

	// get_resources after get_props
	chmpx_h* chmpx_handle_ptr = NULL;
	if(zval_chmpx_handle_ptr) {
		chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	} else {
		return;
	}
	msgid_t* msgid_handle_ptr = NULL;
	if(zval_msgid_handle_ptr) {
		msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle", msgid_handle_resource_number);
	} else {
		return;
	}

	// call_some_functions after get_resources
	if (CHM_INVALID_CHMPXHANDLE != *chmpx_handle_ptr && CHM_INVALID_MSGID != *msgid_handle_ptr) {
		// destroy handle
		if(!chmpx_close(*chmpx_handle_ptr, *msgid_handle_ptr)){
			php_error(E_ERROR, "could not msgid.");
		}
		zval_ptr_dtor(zval_msgid_handle_ptr);
	}
}

PHP_METHOD(ChmpxSlave, send)
{
	// declare_variables
	char* strbinary = NULL;
	size_t strbinary_len = 0;
	zend_bool is_routing = true;
	zend_bool is_broadcast = false;
	
	// assigne_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STRING(strbinary, strbinary_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_routing)
		Z_PARAM_BOOL(is_broadcast)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	if(!strbinary || 0 == strbinary_len){
		php_error(E_ERROR, "send binary data is empty.");
		RETURN_LONG(-1);
	}
	
	// get_props
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_ERROR, "chmpx_handle property is wrong type.");
		RETURN_LONG(-1);

	}
	zval* zval_msgid_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "msgid_handle");
	if(!zval_msgid_handle_ptr) {
		php_error(E_ERROR, "msgid_handle property is wrong type.");
		RETURN_LONG(-1);
	}
	
	// get_resources after get_props
	// chmpx_handle resource
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_ERROR, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_LONG(-1);
	}
	// msgid_handle resource
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_ERROR, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_LONG(-1);
	}

	// call_some_functions after get_resources
	CHMBIN chmbinary;
	chmbinary.byptr = (unsigned char*)strbinary;
	chmbinary.length = (size_t)strbinary_len;
	chmhash_t hashval = make_chmbin_hash(&chmbinary);
	long rcvcnt = 0;
	bool bResult;
	if(is_broadcast){
		// broadcast
		if(false == (bResult = chmpx_msg_broadcast(*chmpx_handle_ptr, *msgid_handle_ptr, (const unsigned char*)strbinary, (size_t)strbinary_len, hashval, &rcvcnt))){
			php_error(E_ERROR, "failed broadcast binary data.");
			RETURN_LONG(-1);
		}
	}else{
		// without broadcast
		if(false == (bResult = chmpx_msg_send(*chmpx_handle_ptr, *msgid_handle_ptr, (const unsigned char*)strbinary, (size_t)strbinary_len, hashval, &rcvcnt, 0 != is_routing ? true : false))){
			php_error(E_ERROR, "failed send binary data.");
			RETURN_LONG(-1);
		}
	}

	// return_result after call_some_functions
	RETURN_LONG((long)rcvcnt);
}

PHP_METHOD(ChmpxSlave, sendKv)
{
	// declare_variables
	char* strbinkey = NULL;
	size_t strbinkey_len = 0;
	char* strbinval = NULL;
	size_t strbinval_len = 0;
	zend_bool is_routing = true;
	zend_bool is_broadcast = false;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STRING(strbinkey, strbinkey_len)
		Z_PARAM_STRING(strbinval, strbinval_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_routing)
		Z_PARAM_BOOL(is_broadcast)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	if(!strbinkey || 0 == strbinkey_len){
		php_error(E_ERROR, "send binary key is empty.");
		RETURN_FALSE;
	}
	if(!strbinval || 0 == strbinval_len){
		php_error(E_ERROR, "send binary val is empty.");
		RETURN_FALSE;
	}
	
	// get_props
	// chmpx_handle property
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is wrong type.");
		RETURN_FALSE;
	}
	// msgid_handle property
	zval* zval_msgid_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "msgid_handle");
	if(!zval_msgid_handle_ptr) {
		php_error(E_NOTICE, "msgid_handle property is wrong type.");
		RETURN_FALSE;
	}

	// get_resources after get_props
	// chmpx_handle
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	// msgid_handle
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}
		
	// call_some_functions after get_resources
	CHMKVP kvp;
	kvp.key.byptr = (unsigned char*)strbinkey;
	kvp.key.length = (size_t)strbinkey_len;
	kvp.val.byptr = (unsigned char*)strbinval;
	kvp.val.length = (size_t)strbinval_len;
	size_t length = 0;
	unsigned char* pdata = cvt_kvp_bin(&kvp, &length);
	if(NULL == pdata) {
		php_error(E_ERROR, "something error occurred in converting key and value to binary data.");
		RETURN_FALSE;
	}
	chmhash_t hashval = make_kvp_hash(&kvp);
	long rcvcnt = 0;
	bool bResult;
	if(is_broadcast){
		// broadcast
		if(false == (bResult = chmpx_msg_broadcast(*chmpx_handle_ptr, *msgid_handle_ptr, pdata, length, hashval, &rcvcnt))){
			php_error(E_ERROR, "failed broadcast binary data.");
			if(pdata){
				free(pdata);
			}
			RETURN_FALSE;
		} else {
			// free pdata
			if(pdata){
				free(pdata);
			}
		}
	}else{
		if(false == (bResult = chmpx_msg_send(*chmpx_handle_ptr, *msgid_handle_ptr, pdata, length, hashval, &rcvcnt, 0 != is_routing ? true : false))){
			php_error(E_ERROR, "failed send binary data.");
			if(pdata){
				free(pdata);
			}
			RETURN_FALSE;
		} else {
			// free pdata
			if(pdata){
				free(pdata);
			}
		}
	}
	
	// return_result after call_some_functions
	RETURN_LONG((long)rcvcnt);
}

PHP_METHOD(ChmpxSlave, receive)
{
	// declare_variables
	zval* strbinary = NULL; // pass by reference
	long timeout_ms = RCV_NO_WAIT;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(strbinary)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		ZEND_PARSE_PARAMETERS_END();
	
	// get_props
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is wrong type.");
		RETURN_FALSE;
	}
	zval* zval_msgid_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "msgid_handle");
	if(!zval_msgid_handle_ptr) {
		php_error(E_NOTICE, "msgid_handle property is wrong type.");
		RETURN_FALSE;
	}
	
	// get_resources after get_props
	// chmpx_handle
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	// msgid_handle
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	// call chmpx_msg_receive
	chmpx_pkt_h chmpx_pkt_handle = 0L;
	unsigned char* pbody = NULL;
	size_t length = 0;
	if(!chmpx_msg_receive(*chmpx_handle_ptr, *msgid_handle_ptr, &chmpx_pkt_handle, &pbody, &length, (int)timeout_ms)){
		php_error(E_ERROR, "could not receive data, probably there is no received data by timeout.");
		RETURN_FALSE;
	}
	// copy received data
	if(Z_ISREF_P(strbinary)) {
		// See https://www.phpinternalsbook.com/php7/zvals/references.html
		ZVAL_DEREF(strbinary);	// dereferencing
	}
	// create a zval with the received data
	zval_ptr_dtor(strbinary);
	ZVAL_STRINGL(strbinary, (char*)pbody, length);
	if(pbody){
		free(pbody);
	}
	// call chmpx_pkth_destroy
	if(0L != chmpx_pkt_handle && !chmpx_pkth_destroy(chmpx_pkt_handle)){
		php_error(E_WARNING, "could not close chmpx packet handler.");
	}
	
	// return_result after call_some_functions
	RETURN_TRUE;
}

PHP_METHOD(ChmpxSlave, receiveKv)
{
	// declare_variables
	zval* strbinkey = NULL; // pass by reference
	zval* strbinval = NULL; // pass by reference
	long timeout_ms = RCV_NO_WAIT;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(strbinkey)
		Z_PARAM_ZVAL(strbinval)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		ZEND_PARSE_PARAMETERS_END();
	
	// get props
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is wrong type.");
		RETURN_FALSE;
	}
	zval* zval_msgid_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "msgid_handle");
	if(!zval_msgid_handle_ptr) {
		php_error(E_NOTICE, "msgid_handle property is wrong type.");
		RETURN_FALSE;
	}

	// get_resources after get_props
	// chmpx_handle
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	// msgid_handle
	msgid_t* msgid_handle_ptr = (msgid_t *)zend_fetch_resource(Z_RES_P(zval_msgid_handle_ptr), "msgid_handle", msgid_handle_resource_number);
	if(CHM_INVALID_MSGID == *msgid_handle_ptr){
		php_error(E_NOTICE, "msgid_handle is CHM_INVALID_MSGID");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	// call chmpx_msg_receive
	chmpx_pkt_h chmpx_pkt_handle = 0L;
	unsigned char* pbody = NULL;
	size_t length = 0;
	if(!chmpx_msg_receive(*chmpx_handle_ptr, *msgid_handle_ptr, &chmpx_pkt_handle, &pbody, &length, (int)timeout_ms)){
		php_error(E_ERROR, "could not receive data, probably there is no received data by timeout.");
		RETURN_FALSE;
	}
	CHMKVP kvp;
	if(cvt_bin_kvp(&kvp, pbody, length)){
		// copy received data to each
		if(Z_ISREF_P(strbinkey)) {
			// See https://www.phpinternalsbook.com/php7/zvals/references.html
			ZVAL_DEREF(strbinkey);	// dereferencing
		}
		zval_ptr_dtor(strbinkey);
		ZVAL_STRINGL(strbinkey, (char*)kvp.key.byptr, kvp.key.length);

		if(Z_ISREF_P(strbinval)) {
			// See https://www.phpinternalsbook.com/php7/zvals/references.html
			ZVAL_DEREF(strbinval);	// dereferencing
		}
		zval_ptr_dtor(strbinval);
		ZVAL_STRINGL(strbinval, (char*)kvp.val.byptr, kvp.val.length);
	}
	if(pbody){
		free(pbody);
	}
	// call chmpx_pkth_destroy
	if(0L != chmpx_pkt_handle && !chmpx_pkth_destroy(chmpx_pkt_handle)){
		php_error(E_WARNING, "could not close chmpx packet handler.");
	}
	
	// return_result after call_some_functions
	RETURN_TRUE;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
