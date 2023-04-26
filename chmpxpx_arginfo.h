/*
* CHMPX PHP Extension library
*
* Copyright 2022 Yahoo Japan Corporation.
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
* AUTHOR:   Hirotaka Wakabayashi
* CREATE:   Tue, Feb 22 2022
* REVISION:
*/

/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d87faf2747d484b72f06aac26407d65c46d16a80 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_bump_debug_level, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_chmpxpx_set_debug_level_silent arginfo_chmpxpx_bump_debug_level

#define arginfo_chmpxpx_set_debug_level_error arginfo_chmpxpx_bump_debug_level

#define arginfo_chmpxpx_set_debug_level_warning arginfo_chmpxpx_bump_debug_level

#define arginfo_chmpxpx_set_debug_level_message arginfo_chmpxpx_bump_debug_level

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_set_debug_file, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_unset_debug_file, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_chmpxpx_load_debug_env arginfo_chmpxpx_unset_debug_file

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_load_hash_library, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, libpath, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_chmpxpx_unload_hash_library arginfo_chmpxpx_unset_debug_file

ZEND_BEGIN_ARG_INFO_EX(arginfo_chmpxpx_create, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, is_on_server, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_auto_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_chmpxpx_create_server, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_auto_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_chmpxpx_create_slave arginfo_chmpxpx_create_server

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_destroy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
ZEND_END_ARG_INFO()

#define arginfo_chmpxpx_process_running arginfo_chmpxpx_destroy

ZEND_BEGIN_ARG_INFO_EX(arginfo_chmpxpx_msgid_open, 0, 0, 1)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, no_giveup_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_msgid_close, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(0, handle_msgid)
ZEND_END_ARG_INFO()

#define arginfo_chmpxpx_pkth_close arginfo_chmpxpx_destroy

ZEND_BEGIN_ARG_INFO_EX(arginfo_chmpxpx_svr_receive, 0, 0, 2)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(1, strbinary)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, no_giveup_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_chmpxpx_svr_receive_kv, 0, 0, 3)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(1, strbinkey)
	ZEND_ARG_INFO(1, strbinval)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, no_giveup_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_svr_reply, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(0, handle_pxpk)
	ZEND_ARG_TYPE_INFO(0, strbinary, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_svr_reply_kv, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(0, handle_pxpk)
	ZEND_ARG_TYPE_INFO(0, strbinkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, strbinval, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_slv_receive, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(0, handle_msgid)
	ZEND_ARG_INFO(1, strbinary)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_slv_receive_kv, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(0, handle_msgid)
	ZEND_ARG_INFO(1, strbinkey)
	ZEND_ARG_INFO(1, strbinval)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_slv_send, 0, 3, IS_LONG, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(0, handle_msgid)
	ZEND_ARG_TYPE_INFO(0, strbinary, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_routing, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_broadcast, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_slv_send_kv, 0, 4, IS_LONG, 0)
	ZEND_ARG_INFO(0, handle_res)
	ZEND_ARG_INFO(0, handle_msgid)
	ZEND_ARG_TYPE_INFO(0, strbinkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, strbinval, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_routing, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_broadcast, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_chmpxpx_print_version, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO_WITH_DEFAULT_VALUE(0, output, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ChmpxServer___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ChmpxServer___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxServer_reply, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, strbinary, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxServer_replyKv, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, strbinkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, strbinval, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxServer_receive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(1, strbinary)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, no_giveup_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxServer_receiveKv, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(1, strbinkey)
	ZEND_ARG_INFO(1, strbinval)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, no_giveup_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ChmpxSlave___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, no_giveup_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_ChmpxSlave___destruct arginfo_class_ChmpxServer___destruct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxSlave_send, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, strbinary, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_routing, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_broadcast, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxSlave_sendKv, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, strbinkey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, strbinval, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_routing, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_broadcast, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxSlave_receive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(1, strbinary)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ChmpxSlave_receiveKv, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(1, strbinkey)
	ZEND_ARG_INFO(1, strbinval)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout_ms, IS_LONG, 0, "RCV_NO_WAIT")
ZEND_END_ARG_INFO()

#define arginfo_class_Chmpx___construct arginfo_class_ChmpxServer___destruct

#define arginfo_class_Chmpx___destruct arginfo_class_ChmpxServer___destruct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Chmpx_create, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, is_on_server, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_auto_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Chmpx_createServer, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, is_auto_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

#define arginfo_class_Chmpx_createSlave arginfo_class_Chmpx_createServer

#define arginfo_class_Chmpx_destroy arginfo_chmpxpx_unset_debug_file

#define arginfo_class_Chmpx_isRunning arginfo_chmpxpx_unset_debug_file

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_class_Chmpx_getChmpxSlave, 0, 0, ChmpxSlave, MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, no_giveup_rejoin, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_class_Chmpx_getChmpxServer, 0, 0, ChmpxServer, MAY_BE_FALSE)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(chmpxpx_bump_debug_level);
ZEND_FUNCTION(chmpxpx_set_debug_level_silent);
ZEND_FUNCTION(chmpxpx_set_debug_level_error);
ZEND_FUNCTION(chmpxpx_set_debug_level_warning);
ZEND_FUNCTION(chmpxpx_set_debug_level_message);
ZEND_FUNCTION(chmpxpx_set_debug_file);
ZEND_FUNCTION(chmpxpx_unset_debug_file);
ZEND_FUNCTION(chmpxpx_load_debug_env);
ZEND_FUNCTION(chmpxpx_load_hash_library);
ZEND_FUNCTION(chmpxpx_unload_hash_library);
ZEND_FUNCTION(chmpxpx_create);
ZEND_FUNCTION(chmpxpx_create_server);
ZEND_FUNCTION(chmpxpx_create_slave);
ZEND_FUNCTION(chmpxpx_destroy);
ZEND_FUNCTION(chmpxpx_process_running);
ZEND_FUNCTION(chmpxpx_msgid_open);
ZEND_FUNCTION(chmpxpx_msgid_close);
ZEND_FUNCTION(chmpxpx_pkth_close);
ZEND_FUNCTION(chmpxpx_svr_receive);
ZEND_FUNCTION(chmpxpx_svr_receive_kv);
ZEND_FUNCTION(chmpxpx_svr_reply);
ZEND_FUNCTION(chmpxpx_svr_reply_kv);
ZEND_FUNCTION(chmpxpx_slv_receive);
ZEND_FUNCTION(chmpxpx_slv_receive_kv);
ZEND_FUNCTION(chmpxpx_slv_send);
ZEND_FUNCTION(chmpxpx_slv_send_kv);
ZEND_FUNCTION(chmpxpx_print_version);
ZEND_METHOD(ChmpxServer, __construct);
ZEND_METHOD(ChmpxServer, __destruct);
ZEND_METHOD(ChmpxServer, reply);
ZEND_METHOD(ChmpxServer, replyKv);
ZEND_METHOD(ChmpxServer, receive);
ZEND_METHOD(ChmpxServer, receiveKv);
ZEND_METHOD(ChmpxSlave, __construct);
ZEND_METHOD(ChmpxSlave, __destruct);
ZEND_METHOD(ChmpxSlave, send);
ZEND_METHOD(ChmpxSlave, sendKv);
ZEND_METHOD(ChmpxSlave, receive);
ZEND_METHOD(ChmpxSlave, receiveKv);
ZEND_METHOD(Chmpx, __construct);
ZEND_METHOD(Chmpx, __destruct);
ZEND_METHOD(Chmpx, create);
ZEND_METHOD(Chmpx, createServer);
ZEND_METHOD(Chmpx, createSlave);
ZEND_METHOD(Chmpx, destroy);
ZEND_METHOD(Chmpx, isRunning);
ZEND_METHOD(Chmpx, getChmpxSlave);
ZEND_METHOD(Chmpx, getChmpxServer);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(chmpxpx_bump_debug_level, arginfo_chmpxpx_bump_debug_level)
	ZEND_FE(chmpxpx_set_debug_level_silent, arginfo_chmpxpx_set_debug_level_silent)
	ZEND_FE(chmpxpx_set_debug_level_error, arginfo_chmpxpx_set_debug_level_error)
	ZEND_FE(chmpxpx_set_debug_level_warning, arginfo_chmpxpx_set_debug_level_warning)
	ZEND_FE(chmpxpx_set_debug_level_message, arginfo_chmpxpx_set_debug_level_message)
	ZEND_FE(chmpxpx_set_debug_file, arginfo_chmpxpx_set_debug_file)
	ZEND_FE(chmpxpx_unset_debug_file, arginfo_chmpxpx_unset_debug_file)
	ZEND_FE(chmpxpx_load_debug_env, arginfo_chmpxpx_load_debug_env)
	ZEND_FE(chmpxpx_load_hash_library, arginfo_chmpxpx_load_hash_library)
	ZEND_FE(chmpxpx_unload_hash_library, arginfo_chmpxpx_unload_hash_library)
	ZEND_FE(chmpxpx_create, arginfo_chmpxpx_create)
	ZEND_FE(chmpxpx_create_server, arginfo_chmpxpx_create_server)
	ZEND_FE(chmpxpx_create_slave, arginfo_chmpxpx_create_slave)
	ZEND_FE(chmpxpx_destroy, arginfo_chmpxpx_destroy)
	ZEND_FE(chmpxpx_process_running, arginfo_chmpxpx_process_running)
	ZEND_FE(chmpxpx_msgid_open, arginfo_chmpxpx_msgid_open)
	ZEND_FE(chmpxpx_msgid_close, arginfo_chmpxpx_msgid_close)
	ZEND_FE(chmpxpx_pkth_close, arginfo_chmpxpx_pkth_close)
	ZEND_FE(chmpxpx_svr_receive, arginfo_chmpxpx_svr_receive)
	ZEND_FE(chmpxpx_svr_receive_kv, arginfo_chmpxpx_svr_receive_kv)
	ZEND_FE(chmpxpx_svr_reply, arginfo_chmpxpx_svr_reply)
	ZEND_FE(chmpxpx_svr_reply_kv, arginfo_chmpxpx_svr_reply_kv)
	ZEND_FE(chmpxpx_slv_receive, arginfo_chmpxpx_slv_receive)
	ZEND_FE(chmpxpx_slv_receive_kv, arginfo_chmpxpx_slv_receive_kv)
	ZEND_FE(chmpxpx_slv_send, arginfo_chmpxpx_slv_send)
	ZEND_FE(chmpxpx_slv_send_kv, arginfo_chmpxpx_slv_send_kv)
	ZEND_FE(chmpxpx_print_version, arginfo_chmpxpx_print_version)
	ZEND_FE_END
};


static const zend_function_entry class_ChmpxServer_methods[] = {
	ZEND_ME(ChmpxServer, __construct, arginfo_class_ChmpxServer___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxServer, __destruct, arginfo_class_ChmpxServer___destruct, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxServer, reply, arginfo_class_ChmpxServer_reply, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxServer, replyKv, arginfo_class_ChmpxServer_replyKv, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxServer, receive, arginfo_class_ChmpxServer_receive, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxServer, receiveKv, arginfo_class_ChmpxServer_receiveKv, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_ChmpxSlave_methods[] = {
	ZEND_ME(ChmpxSlave, __construct, arginfo_class_ChmpxSlave___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxSlave, __destruct, arginfo_class_ChmpxSlave___destruct, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxSlave, send, arginfo_class_ChmpxSlave_send, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxSlave, sendKv, arginfo_class_ChmpxSlave_sendKv, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxSlave, receive, arginfo_class_ChmpxSlave_receive, ZEND_ACC_PUBLIC)
	ZEND_ME(ChmpxSlave, receiveKv, arginfo_class_ChmpxSlave_receiveKv, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Chmpx_methods[] = {
	ZEND_ME(Chmpx, __construct, arginfo_class_Chmpx___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, __destruct, arginfo_class_Chmpx___destruct, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, create, arginfo_class_Chmpx_create, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, createServer, arginfo_class_Chmpx_createServer, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, createSlave, arginfo_class_Chmpx_createSlave, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, destroy, arginfo_class_Chmpx_destroy, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, isRunning, arginfo_class_Chmpx_isRunning, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, getChmpxSlave, arginfo_class_Chmpx_getChmpxSlave, ZEND_ACC_PUBLIC)
	ZEND_ME(Chmpx, getChmpxServer, arginfo_class_Chmpx_getChmpxServer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_chmpxpx_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("RCV_NO_WAIT", 0, CONST_PERSISTENT);
}

static zend_class_entry *register_class_ChmpxServer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ChmpxServer", class_ChmpxServer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_chmpx_handle_default_value;
	ZVAL_NULL(&property_chmpx_handle_default_value);
	zend_string *property_chmpx_handle_name = zend_string_init("chmpx_handle", sizeof("chmpx_handle") - 1, 1);
	zend_declare_property_ex(class_entry, property_chmpx_handle_name, &property_chmpx_handle_default_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(property_chmpx_handle_name);

	zval property_chmpx_pkt_handle_default_value;
	ZVAL_NULL(&property_chmpx_pkt_handle_default_value);
	zend_string *property_chmpx_pkt_handle_name = zend_string_init("chmpx_pkt_handle", sizeof("chmpx_pkt_handle") - 1, 1);
	zend_declare_property_ex(class_entry, property_chmpx_pkt_handle_name, &property_chmpx_pkt_handle_default_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(property_chmpx_pkt_handle_name);

	return class_entry;
}

static zend_class_entry *register_class_ChmpxSlave(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "ChmpxSlave", class_ChmpxSlave_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_chmpx_handle_default_value;
	ZVAL_NULL(&property_chmpx_handle_default_value);
	zend_string *property_chmpx_handle_name = zend_string_init("chmpx_handle", sizeof("chmpx_handle") - 1, 1);
	zend_declare_property_ex(class_entry, property_chmpx_handle_name, &property_chmpx_handle_default_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(property_chmpx_handle_name);

	zval property_msgid_handle_default_value;
	ZVAL_NULL(&property_msgid_handle_default_value);
	zend_string *property_msgid_handle_name = zend_string_init("msgid_handle", sizeof("msgid_handle") - 1, 1);
	zend_declare_property_ex(class_entry, property_msgid_handle_name, &property_msgid_handle_default_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(property_msgid_handle_name);

	return class_entry;
}

static zend_class_entry *register_class_Chmpx(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "Chmpx", class_Chmpx_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_chmpx_handle_default_value;
	ZVAL_NULL(&property_chmpx_handle_default_value);
	zend_string *property_chmpx_handle_name = zend_string_init("chmpx_handle", sizeof("chmpx_handle") - 1, 1);
	zend_declare_property_ex(class_entry, property_chmpx_handle_name, &property_chmpx_handle_default_value, ZEND_ACC_PRIVATE, NULL);
	zend_string_release(property_chmpx_handle_name);

	zval property_is_server_mode_default_value;
	ZVAL_NULL(&property_is_server_mode_default_value);
	zend_string *property_is_server_mode_name = zend_string_init("is_server_mode", sizeof("is_server_mode") - 1, 1);
	zend_declare_property_ex(class_entry, property_is_server_mode_name, &property_is_server_mode_default_value, ZEND_ACC_PRIVATE, NULL);
	zend_string_release(property_is_server_mode_name);

	return class_entry;
}

/*
* Local variables:
* tab-width: 4
* c-basic-offset: 4
* End:
* vim600: noexpandtab sw=4 ts=4 fdm=marker
* vim<600: noexpandtab sw=4 ts=4
*/
