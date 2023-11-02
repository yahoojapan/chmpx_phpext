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

// cppcheck-suppress missingInclude
#include "php.h"
// cppcheck-suppress missingInclude
#include "ext/standard/info.h"
#include "php_chmpxpx.h"

PHP_METHOD(ChmpxServer, __construct)
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
		php_error(E_ERROR, "zval_chmpx_handle_ptr should be a valid pointer.");
		RETURN_FALSE;
	}

	// get_props or update_props
	// chmpx_handle property
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle", strlen("chmpx_handle"), zval_chmpx_handle_ptr);
	// chmpx_pkt_handle property
	// Firstly, create a chmpx_handle
	long* chmpx_pkt_handle_ptr = emalloc(sizeof(long));
	if (chmpx_pkt_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*chmpx_pkt_handle_ptr = 0L;
	// Secondarily, create a zend_resource with the chmpx handle
	zend_resource* my_chmpx_pkt_handle_ptr = zend_register_resource(chmpx_pkt_handle_ptr, chmpx_pkt_handle_resource_number);
	// Thirdly, create a zval with the zend_resource
	zval zval_new_chmpx_pkt_handle;
	ZVAL_RES(&zval_new_chmpx_pkt_handle, my_chmpx_pkt_handle_ptr);
	// Finally, set the zend_resource with this object
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_pkt_handle", strlen("chmpx_pkt_handle"), &zval_new_chmpx_pkt_handle);
}

PHP_METHOD(ChmpxServer, __destruct)
{
	// get_props
	// chmpx_handle property
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is invalid");
		return;
	}
	// chmpx_pkt_handle property
	zval* zval_chmpx_pkt_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_pkt_handle");
	if(!zval_chmpx_pkt_handle_ptr) {
		php_error(E_NOTICE, "chmpx_pkt_handle property is invalid");
		return;
	}

	// get_resources after get_props
	// chmpx_handle resource
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	//if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
	//	// no created handle
	//	php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
	//	RETURN_FALSE;
	//}
	// chmpx_pkt_handle resource
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_ptr), "chmpx_pkt_handle", chmpx_pkt_handle_resource_number);
	//if(CHM_INVALID_CHMPXHANDLE == *chmpx_pkt_handle_ptr){
	//	php_error(E_NOTICE, "chmpx_pkt_handle is CHM_INVALID_CHMPXHANDLE");
	//	RETURN_FALSE;
	//}

	// call_some_functions after get_resources
	if (CHM_INVALID_CHMPXHANDLE != *chmpx_handle_ptr && 0L != *chmpx_pkt_handle_ptr) {
		// destroy handle
		if(!chmpx_pkth_destroy(*chmpx_pkt_handle_ptr)) {
			php_error(E_ERROR, "failed to close CHMPX pkt handle.");
		}
		zval_ptr_dtor(zval_chmpx_pkt_handle_ptr);
	}
	zval_ptr_dtor(zval_chmpx_handle_ptr);

	// return_result after call_some_functions
	// NOTICE: destruct shoud return nothing
}

PHP_METHOD(ChmpxServer, reply)
{
	// declare_variables
	char* strbinary = NULL;
	size_t strbinary_len = 0;
	
	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(strbinary, strbinary_len)
		ZEND_PARSE_PARAMETERS_END();

	// validate_after_assign
	if(!strbinary || 0 == strbinary_len){
		php_error(E_ERROR, "send binary data is empty.");
		RETURN_FALSE;
	}

	// get_props
	// chmpx_handle property
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is invalid");
		RETURN_FALSE;
	}
	// chmpx_pkt_handle property
	zval* zval_chmpx_pkt_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_pkt_handle");
	if(!zval_chmpx_pkt_handle_ptr) {
		php_error(E_NOTICE, "chmpx_pkt_handle property is invalid");
		RETURN_FALSE;
	}

	// get_resources after get_props
	// chmpx_handle resource
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	// chmpx_pkt_handle resource
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_ptr), "chmpx_pkt_handle", chmpx_pkt_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_pkt_handle_ptr){
		php_error(E_NOTICE, "chmpx_pkt_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	bool bResult = chmpx_msg_reply(*chmpx_handle_ptr, *chmpx_pkt_handle_ptr, (const unsigned char*)strbinary, (size_t)strbinary_len);

	// return_result after call_some_functions
	if (bResult) {
		RETURN_TRUE;
	}
	php_error(E_ERROR, "failed send binary data.");
	RETURN_FALSE;
}

PHP_METHOD(ChmpxServer, replyKv)
{
	// declare_variables
	char* strbinkey = NULL;
	size_t strbinkey_len = 0;
	char* strbinval = NULL;
	size_t strbinval_len = 0;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STRING(strbinkey, strbinkey_len)
		Z_PARAM_STRING(strbinval, strbinval_len)
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
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is wrong type.");
		RETURN_FALSE;
	}
	zval* zval_chmpx_pkt_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_pkt_handle");
	if(!zval_chmpx_pkt_handle_ptr) {
		php_error(E_NOTICE, "chmpx_pkt_handle property is wrong type.");
		RETURN_FALSE;
	}

	// get_resources after get_props
	// chmpx_handle resource
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	// chmpx_pkt_handle resource
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_ptr), "chmpx_pkt_handle", chmpx_pkt_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_pkt_handle_ptr){
		php_error(E_NOTICE, "chmpx_pkt_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions
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
	bool bResult = chmpx_msg_reply(*chmpx_handle_ptr, *chmpx_pkt_handle_ptr, pdata, length);

	// return_result after call_some_functions
	if (!bResult) {
		php_error(E_ERROR, "failed send binary data.");
		if(pdata){
			free(pdata);
		}
		RETURN_FALSE;
	}
	else {
		if(pdata){
			free(pdata);
		}
	}
	RETURN_TRUE;
}

PHP_METHOD(ChmpxServer, receive)
{
	// declare_variables
	zval* strbinary = NULL; // pass by reference
	long timeout_ms = RCV_NO_WAIT;
	zend_bool no_giveup_rejoin = false;

	// validate_after_assign
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(strbinary)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		Z_PARAM_BOOL(no_giveup_rejoin)
		ZEND_PARSE_PARAMETERS_END();

	// get_props
	// chmpx_handle property
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is invalid");
		RETURN_FALSE;
	}
	// chmpx_pkt_handle property
	zval* zval_chmpx_pkt_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_pkt_handle");
	if(!zval_chmpx_pkt_handle_ptr) {
		php_error(E_NOTICE, "chmpx_pkt_handle property is invalid");
		RETURN_FALSE;
	}

	// get_resources after get_props
	// chmpx_handle resource
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}
	// chmpx_pkt_handle resource
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_ptr), "chmpx_pkt_handle", chmpx_pkt_handle_resource_number);
	if(0L != *chmpx_pkt_handle_ptr){
		// close handle
		if(!chmpx_pkth_destroy(*chmpx_pkt_handle_ptr)){
			php_error(E_ERROR, "ChmpxServer::Receive: failed to close CHMPX pkt handle.");
		}
	}

	// call_some_functions after get_resources
	// call chmpx_svr_receive
	chmpx_pkt_h new_chmpx_pkt_handle = 0L;
	unsigned char* pbody = NULL;
	size_t length = 0;
	bool bResult = chmpx_svr_receive(*chmpx_handle_ptr, &new_chmpx_pkt_handle, &pbody, &length, (int)timeout_ms, 0 != no_giveup_rejoin ? true : false);
	if (!bResult) {
		php_error(E_ERROR, "could not receive data, probably there is no received data by timeout.");
		RETURN_FALSE;
	}
	// copy received data
	if(Z_ISREF_P(strbinary)) {
		// See https://www.phpinternalsbook.com/php7/zvals/references.html
		ZVAL_DEREF(strbinary);	// dereferencing
	}
	zval_ptr_dtor(strbinary);
	ZVAL_STRINGL(strbinary, (char*)pbody, length);
	if(pbody){
		free(pbody);
	}
	// register the chmpx_pkt_handle to chmpx_pkt_handle_resource_number. The resource will destroy by using chmpx_pkt_handle_resource_dtor
	// Firstly, create a chmpx_handle
	long* new_chmpx_pkt_handle_ptr = emalloc(sizeof(long));
	if (new_chmpx_pkt_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*new_chmpx_pkt_handle_ptr = new_chmpx_pkt_handle;
	// Secondarily, create a zend_resource with the chmpx handle
	zend_resource* my_chmpx_pkt_handle_ptr = zend_register_resource(new_chmpx_pkt_handle_ptr, chmpx_pkt_handle_resource_number);
	// Thirdly, create a zval with the zend_resource
	zval zval_new_chmpx_pkt_handle;
	ZVAL_RES(&zval_new_chmpx_pkt_handle, my_chmpx_pkt_handle_ptr);
	// Finally, set the zend_resource with this object
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_pkt_handle", strlen("chmpx_pkt_handle"), &zval_new_chmpx_pkt_handle);

	// return_result after call_some_functions
	RETURN_TRUE;
}

PHP_METHOD(ChmpxServer, receiveKv)
{
	// declare_variables
	zval* strbinkey = NULL; // pass by reference
	zval* strbinval = NULL; // pass by reference
	long timeout_ms = RCV_NO_WAIT;
	zend_bool no_giveup_rejoin = false;

	// validate_after_assign
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_ZVAL(strbinkey)
		Z_PARAM_ZVAL(strbinval)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(timeout_ms)
		Z_PARAM_BOOL(no_giveup_rejoin)
		ZEND_PARSE_PARAMETERS_END();

	// get props
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is wrong type.");
		RETURN_FALSE;
	}
	zval* zval_chmpx_pkt_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_pkt_handle");
	if(!zval_chmpx_pkt_handle_ptr) {
		php_error(E_NOTICE, "chmpx_pkt_handle property is wrong type.");
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
	// chmpx_pkt_handle
	chmpx_pkt_h* chmpx_pkt_handle_ptr = (chmpx_pkt_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_pkt_handle_ptr), "chmpx_pkt_handle", chmpx_pkt_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_pkt_handle_ptr){
		php_error(E_NOTICE, "chmpx_pkt_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	// call chmpx_svr_receive
	unsigned char* pbody = NULL;
	size_t length = 0;
	if(!chmpx_svr_receive(*chmpx_handle_ptr, chmpx_pkt_handle_ptr, &pbody, &length, (int)timeout_ms, 0 != no_giveup_rejoin ? true : false)){
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

		// copy received data to each
		if(Z_ISREF_P(strbinval)) {
			// See https://www.phpinternalsbook.com/php7/zvals/references.html
			ZVAL_DEREF(strbinval);	// dereferencing
		}
		zval_ptr_dtor(strbinval);
		ZVAL_STRINGL(strbinval, (char*)kvp.val.byptr, kvp.val.length);
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
