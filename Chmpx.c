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

PHP_METHOD(Chmpx, __construct)
{
	// chmpx_handle property
	// Firstly, create a chmpx_handle
	chmpx_h* chmpx_handle_ptr = emalloc(sizeof(long));
	if (chmpx_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		return;
	}
	*chmpx_handle_ptr = CHM_INVALID_CHMPXHANDLE;
	// Secondarily, create a zend_resource with the chmpx handle
	zend_resource* my_chmpx_handle_ptr = zend_register_resource(chmpx_handle_ptr, chmpx_handle_resource_number);
	// Thirdly, create a zval with the zend_resource
	zval zval_new_chmpx_handle;
	ZVAL_RES(&zval_new_chmpx_handle, my_chmpx_handle_ptr);
	// Finally, set the zend_resource with this object
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle", strlen("chmpx_handle"), &zval_new_chmpx_handle);

	// is_server_mode property
	// Firstly, create a is_server_mode
	long* is_server_mode_ptr = emalloc(sizeof(long));
	if (is_server_mode_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		return;
	}
	*is_server_mode_ptr = 1;
	// Secondarily, create a zend_resource with the chmpx handle
	zend_resource* my_res_is_server_mode = zend_register_resource(is_server_mode_ptr, is_server_mode_resource_number);
	// Thirdly, create a zval with the zend_resource
	zval zval_new_is_server_mode;
	ZVAL_RES(&zval_new_is_server_mode, my_res_is_server_mode);
	// Finally, set the zend_resource with this object
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "is_server_mode", strlen("is_server_mode"), &zval_new_is_server_mode);
}

static void chmpx_class_dtor_opt(INTERNAL_FUNCTION_PARAMETERS, int opt)
{
	// declare_variables
	zend_bool is_destruct = true;

	// hack: override the is_on_server by using the opt parameter
	switch (opt) {
	case 0:
		is_destruct = false;
		break;
	case 1:
		break;
	default:
		RETURN_FALSE;
	}

	// assign_after_declare
	// chmpx_handle resource
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(zval_chmpx_handle_ptr) {
		chmpx_h* chmpx_handle_ptr;
		chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
		if(CHM_INVALID_CHMPXHANDLE != *chmpx_handle_ptr){
			// destroy handle
			chmpx_destroy(*chmpx_handle_ptr);
		}
		zval_dtor(zval_chmpx_handle_ptr);
	}
	// is_server_mode resource
	zval* zval_is_server_mode = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "is_server_mode");
	if(zval_is_server_mode) {
		zval_dtor(zval_is_server_mode);
	}

	// update_props
	// NOTICE: set invalid handle to avoid SIGSEGV if not is_destruct
	if (!is_destruct) {
		// Firstly, create a chmpx_handle
		chmpx_h* chmpx_handle_ptr = emalloc(sizeof(long));
		if (chmpx_handle_ptr == NULL) {
			php_error(E_ERROR, "malloc error");
			RETURN_FALSE;
		}
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		*chmpx_handle_ptr = CHM_INVALID_CHMPXHANDLE;
		// Secondarily, create a zend_resource with the chmpx handle
		zend_resource* my_chmpx_handle_ptr = zend_register_resource(chmpx_handle_ptr, chmpx_handle_resource_number);
		// Thirdly, create a zval with the zend_resource
		zval zval_new_chmpx_handle;
		ZVAL_RES(&zval_new_chmpx_handle, my_chmpx_handle_ptr);
		// Finally, set the zend_resource with this object
		chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle", strlen("chmpx_handle"), &zval_new_chmpx_handle);
	}

	// return_result after call_some_functions
	// NOTICE: destruct shoud return nothing
	if (!is_destruct) {
		RETURN_TRUE;
	}
}

PHP_METHOD(Chmpx, __destruct)
{
	chmpx_class_dtor_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 1);
}

PHP_METHOD(Chmpx, destroy)
{
	chmpx_class_dtor_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 0);
}

static void chmpx_class_create_instance_opt(INTERNAL_FUNCTION_PARAMETERS, int opt)
{
	// declare_variables
	char* filepath = NULL;
	size_t filepath_len = 0;
	zend_bool is_on_server = true;
	zend_bool is_auto_rejoin = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STRING(filepath, filepath_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(is_on_server)
		Z_PARAM_BOOL(is_auto_rejoin)
		ZEND_PARSE_PARAMETERS_END();

	// hack: override the is_on_server by using the opt parameter
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

	// validate_after_assign
	if(!filepath || 0 == filepath_len){
		php_error(E_ERROR, "CHMPX configuration file path is empty.");
		RETURN_FALSE;
	}

	// get_props and  get_resources
	// chmpx_handle
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(zval_chmpx_handle_ptr) {
		chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
		if(CHM_INVALID_CHMPXHANDLE != *chmpx_handle_ptr){
			// destroy handle
			chmpx_destroy(*chmpx_handle_ptr);
		}
		zval_dtor(zval_chmpx_handle_ptr);
	}
	// is_server_mode
	zval* zval_is_server_mode = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "is_server_mode");
	if(zval_is_server_mode) {
		zval_dtor(zval_is_server_mode);
	}

	// call_some_functions after get_resources
	// Firstly, create a chmpx_handle
	chmpx_h* new_chmpx_handle_ptr = emalloc(sizeof(long));
	if (new_chmpx_handle_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*new_chmpx_handle_ptr = chmpx_create(filepath, 0 != is_on_server ? true : false, 0 != is_auto_rejoin ? true : false);
	// Secondarily, create a zend_resource with the chmpx handle
	zend_resource* res_new_chmpx_handle = zend_register_resource(new_chmpx_handle_ptr, chmpx_handle_resource_number);
	// Thirdly, create a zval with the zend_resource
	zval zval_res_new_chmpx_handle;
	ZVAL_RES(&zval_res_new_chmpx_handle, res_new_chmpx_handle);
	// Finally, set the zend_resource with this object
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle", strlen("chmpx_handle"), &zval_res_new_chmpx_handle);
	// update a property after init props after getting props
	// Firstly, create a is_server_mode
	bool* new_is_server_mode_ptr = emalloc(sizeof(bool));
	if (new_is_server_mode_ptr == NULL) {
		php_error(E_ERROR, "malloc error");
		RETURN_FALSE;
	}
	// cppcheck-suppress unmatchedSuppression
	// cppcheck-suppress nullPointerRedundantCheck
	*new_is_server_mode_ptr = is_on_server;
	// Secondarily, create a zend_resource with the is_server_mode
	zend_resource* res_new_is_server_mode = zend_register_resource(new_is_server_mode_ptr, is_server_mode_resource_number);
	// Thirdly create a zval with the zend_resource
	zval zval_res_new_is_server_mode;
	ZVAL_RES(&zval_res_new_is_server_mode, res_new_is_server_mode);
	// Finally, set the zend_resource with this object
	chmpxpx_update_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "is_server_mode", strlen("is_server_mode"), &zval_res_new_is_server_mode);

	// return_result after call_some_functions
	RETURN_TRUE;
}


PHP_METHOD(Chmpx, create)
{
	chmpx_class_create_instance_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 0);
}

PHP_METHOD(Chmpx, createServer)
{
	chmpx_class_create_instance_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 1);
}

PHP_METHOD(Chmpx, createSlave)
{
	chmpx_class_create_instance_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 2);
}

PHP_METHOD(Chmpx, isRunning)
{
	// get_props
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "zval_chmpx_handle_ptr shoule be a valid pointer but NULL");
	}

	// get_resources after get_props
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		php_error(E_NOTICE, "chmpx_handle is CHM_INVALID_CHMPXHANDLE");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	bool bResult = is_chmpx_proc_exists(*chmpx_handle_ptr);

	// return_result after call_some_functions
	if (bResult) {
		RETURN_TRUE;
	}
	php_error(E_NOTICE, "is_chmpx_proc_exists false");
	RETURN_FALSE;
}

static void chmpx_class_get_instance_opt(INTERNAL_FUNCTION_PARAMETERS, int opt)
{
	// declare_variables
	zend_bool is_on_server = true;
	zend_bool no_giveup_rejoin = false;

	// assign_after_declare
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(no_giveup_rejoin)
		ZEND_PARSE_PARAMETERS_END();

	// hack: override the is_on_server by using the opt parameter
	switch (opt) {
	case 1:
		is_on_server = true;
		break;
	case 2:
		is_on_server = false;
		break;
	default:
		RETURN_FALSE;
	}

	// validate_after_assign
	// get_props
	// chmpx_handle property
	zval* zval_chmpx_handle_ptr = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "chmpx_handle");
	if(!zval_chmpx_handle_ptr) {
		php_error(E_NOTICE, "chmpx_handle property is invalid");
		RETURN_FALSE;
	}
	// getting the is_server_mode property
	zval* zval_is_server_mode = chmpxpx_read_property_resource(Z_OBJCE_P(ZEND_THIS), ZEND_THIS, "is_server_mode");
	if(!zval_is_server_mode) {
		php_error(E_NOTICE, "is_server_mode porperty is invalid");
		RETURN_FALSE;
	}
	
	// get_resources after get_props
	// chmpx_handle property
	chmpx_h* chmpx_handle_ptr = (chmpx_h *)zend_fetch_resource(Z_RES_P(zval_chmpx_handle_ptr), "chmpx_handle", chmpx_handle_resource_number);
	if(CHM_INVALID_CHMPXHANDLE == *chmpx_handle_ptr){
		// no created handle
		RETURN_FALSE;
	}
	// is_server_mode
	bool* is_server_mode_ptr = (bool *)zend_fetch_resource(Z_RES_P(zval_is_server_mode), "is_server_mode", is_server_mode_resource_number);
	if( !is_on_server && *is_server_mode_ptr ){
		// mode is server
		php_error(E_NOTICE, "is_server_mode should be slave but server");
		RETURN_FALSE;
	}

	// call_some_functions after get_resources
	// NOTICE: this case does not call ChmpxSlave::__construct().
	if (!is_on_server) {
		// set msgid handle for ChmpxSlave instance
		msgid_t* res_msgid_handle_ptr = emalloc(sizeof(long));
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		if (res_msgid_handle_ptr == NULL) {
			php_error(E_ERROR, "malloc error");
			RETURN_FALSE;
		}
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		*res_msgid_handle_ptr = chmpx_open(*chmpx_handle_ptr, 0 != no_giveup_rejoin ? true : false);
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		if(CHM_INVALID_MSGID == *res_msgid_handle_ptr){
			php_error(E_NOTICE, "failed to open msgid on slave CHMPX.");
			RETURN_FALSE;
		}
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		zval zval_msgid_handle;
		zend_resource* my_res_msgid_handle = zend_register_resource(res_msgid_handle_ptr, msgid_handle_resource_number);
		ZVAL_RES(&zval_msgid_handle, my_res_msgid_handle);
	
		// NOTICE: set invalid handle to avoid SIGSEGV
		zval zval_dup_chmpx_handle;
		chmpx_h* res_dup_chmpx_handle_ptr = emalloc(sizeof(long));
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		if (res_dup_chmpx_handle_ptr == NULL) {
			php_error(E_ERROR, "malloc error");
			RETURN_FALSE;
		}
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		*res_dup_chmpx_handle_ptr = *chmpx_handle_ptr;
		zend_resource* my_res_dup_chmpx_handle = zend_register_resource(res_dup_chmpx_handle_ptr, chmpx_handle_resource_number);
		ZVAL_RES(&zval_dup_chmpx_handle, my_res_dup_chmpx_handle);
	
		// return a new object(ChmpxSlave class)
		object_init_ex(return_value, chmpx_slave_class_entry);
		add_property_zval(return_value, "chmpx_handle", &zval_dup_chmpx_handle);
		add_property_zval(return_value, "msgid_handle", &zval_msgid_handle);

	} else {
		// set pkt handle for ChmpxServer instance
		chmpx_pkt_h* res_pkt_handle_ptr = emalloc(sizeof(long));
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		if (res_pkt_handle_ptr == NULL) {
			php_error(E_ERROR, "malloc error");
			RETURN_FALSE;
		}
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		*res_pkt_handle_ptr = 0L;
		zval zval_pkt_handle;
		zend_resource* my_res_pkt_handle = zend_register_resource(res_pkt_handle_ptr, chmpx_pkt_handle_resource_number);
		ZVAL_RES(&zval_pkt_handle, my_res_pkt_handle);
	
		// NOTICE: set invalid handle to avoid SIGSEGV
		zval zval_dup_chmpx_handle;
		chmpx_h* res_dup_chmpx_handle_ptr = emalloc(sizeof(long));
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		if (res_dup_chmpx_handle_ptr == NULL) {
			php_error(E_ERROR, "malloc error");
			RETURN_FALSE;
		}
		// cppcheck-suppress unmatchedSuppression
		// cppcheck-suppress nullPointerRedundantCheck
		*res_dup_chmpx_handle_ptr = *chmpx_handle_ptr;
		zend_resource* my_res_dup_chmpx_handle = zend_register_resource(res_dup_chmpx_handle_ptr, chmpx_handle_resource_number);
		ZVAL_RES(&zval_dup_chmpx_handle, my_res_dup_chmpx_handle);
	
		// return a new object(ChmpxServer class)
		object_init_ex(return_value, chmpx_server_class_entry);
		add_property_zval(return_value, "chmpx_handle", &zval_dup_chmpx_handle);
		add_property_zval(return_value, "chmpx_pkt_handle", &zval_pkt_handle);
	}
}

PHP_METHOD(Chmpx, getChmpxSlave)
{
	chmpx_class_get_instance_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 2);
}

PHP_METHOD(Chmpx, getChmpxServer)
{
	chmpx_class_get_instance_opt(INTERNAL_FUNCTION_PARAM_PASSTHRU, 1);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
