---
layout: contents
language: en-us
title: Developer
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: developerja.html
lang_opp_word: To Japanese
prev_url: usage.html
prev_string: Usage
top_url: index.html
top_string: TOP
next_url: configurations.html
next_string: Configurations
---

# Developers

## [Predefined Constants](constants.html)
CHMPX PHP Extension defines [constants](constants.html).

## [Chmpx](chmpx_class.html) Class
[Chmpx](chmpx_class.html) class provides the methods below.

- [Chmpx::__construct](chmpx_class_construct.html) - Creates a empty Chmpx instance
- [Chmpx::__destruct](chmpx_class_destruct.html) - Destroys a Chmpx instance
- [Chmpx::create](chmpx_class_create.html) - Creates a ChmpxServer instance
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
- [Chmpx::destroy](chmpx_class_destroy.html) - Destroys a Chmpx instance
- [Chmpx::isRunning](chmpx_class_isrunning.html) - Checks if a chmpx process exists
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserver.html) - Retrieves the ChmpxServer instance
- [Chmpx::getChmpxSlave](chmpx_class_getchmpxslave.html) - Retrieves the ChmpxSlave instance

## [ChmpxServer](chmpxserver_class.html) Class
[ChmpxServer](chmpxserver_class.html) class provides the methods below.

- [ChmpxServer::__construct](chmpxserver_class_construct.html) - Creates a ChmpxServer instance
- [ChmpxServer::__destruct](chmpxserver_class_destruct.html) - Destroys a ChmpxServer instance
- [ChmpxServer::reply](chmpxserver_class_reply.html) - Replies a message
- [ChmpxServer::replyKv](chmpxserver_class_replykv.html) - Replies a message with a key and a value
- [ChmpxServer::receive](chmpxserver_class_receive.html) - Receives a message
- [ChmpxServer::receiveKv](chmpxserver_class_receivekv.html) - Receives a message with a key and a value

## [ChmpxSlave](chmpxslave_class.html) Class
[ChmpxSlave](chmpxslave_class.html) class provides the methods below.

- [ChmpxSlave::__construct](chmpxslave_class_construct.html) - Creates a empty Chmpx instance
- [ChmpxSlave::__destruct](chmpxslave_class_destruct.html) - Destroys a Chmpx instance
- [ChmpxSlave::send](chmpxslave_class_send.html) - Sends a message
- [ChmpxSlave::sendKv](chmpxslave_class_sendkv.html) - Sends a message with a key and a value
- [ChmpxSlave::receive](chmpxslave_class_receive.html) - Receives a message
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekv.html) - Receives a message witha a key and a value


## [Chmpxpx](chmpxpx.html) Funsctions
[Chmpxpx](chmpxpx.html) functions provides the methods below.

- [chmpxpx_bump_debug_level](chmpxpx_bump_debug_level.html) - Changes the log level
- [chmpxpx_set_debug_file](chmpxpx_set_debug_file.html) - Writes log to the file
- [chmpxpx_set_debug_level_error](chmpxpx_set_debug_level_error.html) - Sets log level to error
- [chmpxpx_set_debug_level_message](chmpxpx_set_debug_level_message.html) - Sets log level to info
- [chmpxpx_set_debug_level_silent](chmpxpx_set_debug_level_silent.html) - Stops logging
- [chmpxpx_set_debug_level_warning](chmpxpx_set_debug_level_warning.html) - Sets log level to warning
- [chmpxpx_unset_debug_file](chmpxpx_unset_debug_file.html) - Writes logs to stderr
- [chmpxpx_load_debug_env](chmpxpx_load_debug_env.html) - Loads environment variables
- [chmpxpx_load_hash_library](chmpxpx_load_hash_library.html) - Loads hash functions from the file
- [chmpxpx_unload_hash_library](chmpxpx_unload_hash_library.html) - Removes the user-defined hash library
- [chmpxpx_create](chmpxpx_create.html) - Creates a chmpx handle
- [chmpxpx_create_server](chmpxpx_create_server.html) - Creates a chmpx handle
- [chmpxpx_create_slave](chmpxpx_create_slave.html) - Creates a chmpx handle
- [chmpxpx_destroy](chmpxpx_destroy.html) - Destroys a chmpx handle
- [chmpxpx_process_running](chmpxpx_process_running.html) - Checks if a chmpx process exists
- [chmpxpx_msgid_open](chmpxpx_msgid_open.html) - Creates a msgid handle
- [chmpxpx_msgid_close](chmpxpx_msgid_close.html) - Closes a msgid handle
- [chmpxpx_pkth_close](chmpxpx_pkth_close.html) - Closes a chmpx packet handle
- [chmpxpx_svr_receive](chmpxpx_svr_receive.html) - Receives a message
- [chmpxpx_svr_receive_kv](chmpxpx_svr_receive_kv.html) - Receives a message with a key and a value
- [chmpxpx_svr_reply](chmpxpx_svr_reply.html) - Replies a message
- [chmpxpx_svr_reply_kv](chmpxpx_svr_reply_kv.html) - Replies a message with a key and a value
- [chmpxpx_slv_receive](chmpxpx_slv_receive.html) - Receives a message
- [chmpxpx_slv_receive_kv](chmpxpx_slv_receive_kv.html) - Receives a message with a key and a value
- [chmpxpx_slv_send](chmpxpx_slv_send.html) - Sends a message
- [chmpxpx_slv_send_kv](chmpxpx_slv_send_kv.html) - Sends a message with a key and a value
- [chmpxpx_print_version](chmpxpx_print_version.html) - Prints the chmpx library version
