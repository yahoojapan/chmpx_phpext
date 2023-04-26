---
layout: contents
language: ja
title: Developer
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: developer.html
lang_opp_word: To English
prev_url: usageja.html
prev_string: Usage
top_url: indexja.html
top_string: TOP
next_url: configurationsja.html
next_string: 実行時変数
---

# 開発者向け

## [定義済み定数](constantsja.html)
CHMPX PHP Extensionは、[定数](constantsja.html)を定義しています。

## [Chmpx](chmpx_classja.html) Class
[Chmpx](chmpx_classja.html)クラスは、次のメソッドを提供します。

- [Chmpx::__construct](chmpx_class_constructja.html) - Chmpxインスタンスを作成する
- [Chmpx::__destruct](chmpx_class_destructja.html) - Chmpxインスタンスを解放する
- [Chmpx::create](chmpx_class_createja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [Chmpx::destroy](chmpx_class_destroyja.html) - Chmpxインスタンスを解放する
- [Chmpx::isRunning](chmpx_class_isrunningja.html) - chmpxプロセスを確認する
- [Chmpx::getChmpxSlave](chmpx_class_getchmpxslaveja.html) - ChmpxSlaveインスタンスを取得する
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserverja.html) - ChmpxServerインスタンスを取得する

## [ChmpxServer](chmpxserver_classja.html) Class
[ChmpxServer](chmpxserver_classja.html)クラスは、次のメソッドを提供します。

- [ChmpxServer::__construct](chmpxserver_class_constructja.html) - ChmpxServerインスタンスを作成する
- [ChmpxServer::__destruct](chmpxserver_class_destructja.html) - ChmpxServerインスタンスを解放する
- [ChmpxServer::reply](chmpxserver_class_replyja.html) - メッセージを返信する
- [ChmpxServer::replyKv](chmpxserver_class_replykvja.html) - キーバリュー形式のメッセージを返信する
- [ChmpxServer::receive](chmpxserver_class_receiveja.html) - メッセージを受信する
- [ChmpxServer::receiveKv](chmpxserver_class_receivekvja.html) - キーバリュー形式のメッセージを受信する

## [ChmpxSlave](chmpxslave_classja.html) Class
[ChmpxSlave](chmpxslave_classja.html) クラスは、次のメソッドを提供します。

- [ChmpxSlave::__construct](chmpxslave_class_constructja.html) - ChmpxSlaveインスタンスを作成する
- [ChmpxSlave::__destruct](chmpxslave_class_destructja.html) - ChmpxSlaveインスタンスを解放する
- [ChmpxSlave::send](chmpxslave_class_sendja.html) - メッセージを送信する
- [ChmpxSlave::sendKv](chmpxslave_class_sendkvja.html) - キーバリュー形式のメッセージを送信する
- [ChmpxSlave::receive](chmpxslave_class_receiveja.html) - メッセージを受信する
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekvja.html) - キーバリュー形式のメッセージを受信する


## [Chmpxpx](chmpxpxja.html) Funsctions
[Chmpxpx](chmpxpxja.html) 関数群の関数は、次のとおりです。

- [chmpxpx_bump_debug_level](chmpxpx_bump_debug_levelja.html) - ログレベルを変更する
- [chmpxpx_set_debug_file](chmpxpx_set_debug_fileja.html) - ログ出力先ファイル名を指定する
- [chmpxpx_set_debug_level_error](chmpxpx_set_debug_level_errorja.html) - ライブラリのログレベルをerrorにする
- [chmpxpx_set_debug_level_message](chmpxpx_set_debug_level_messageja.html) - ライブラリのログレベルをmessage(info相当）にする
- [chmpxpx_set_debug_level_silent](chmpxpx_set_debug_level_silentja.html) - ライブラリのログを出力しない
- [chmpxpx_set_debug_level_warning](chmpxpx_set_debug_level_warningja.html) - ライブラリのログレベルをwarningにする
- [chmpxpx_unset_debug_file](chmpxpx_unset_debug_fileja.html) - ログ出力先を標準エラーに指定する
- [chmpxpx_load_debug_env](chmpxpx_load_debug_envja.html) - 環境変数を読み込む
- [chmpxpx_load_hash_library](chmpxpx_load_hash_libraryja.html) - ハッシュ関数ライブラリを有効にする
- [chmpxpx_unload_hash_library](chmpxpx_unload_hash_libraryja.html) - ハッシュ関数ライブラリを取り外す
- [chmpxpx_create](chmpxpx_createja.html) - chmpxハンドルを作成する
- [chmpxpx_create_server](chmpxpx_create_serverja.html) - chmpxハンドルを作成する
- [chmpxpx_create_slave](chmpxpx_create_slaveja.html) - chmpxハンドルを作成する
- [chmpxpx_destroy](chmpxpx_destroyja.html) - chmpxハンドルを解放する
- [chmpxpx_process_running](chmpxpx_process_runningja.html) - chmpxプロセスを確認する
- [chmpxpx_msgid_open](chmpxpx_msgid_openja.html) - msgidハンドルを作成する
- [chmpxpx_msgid_close](chmpxpx_msgid_closeja.html) - msgidハンドルを解放する
- [chmpxpx_pkth_close](chmpxpx_pkth_closeja.html) - chmpx_pktハンドルを解放する
- [chmpxpx_svr_receive](chmpxpx_svr_receiveja.html) - メッセージを受信する
- [chmpxpx_svr_receive_kv](chmpxpx_svr_receive_kvja.html) - キーバリュー形式メッセージを受信する
- [chmpxpx_svr_reply](chmpxpx_svr_replyja.html) - メッセージを返信する
- [chmpxpx_svr_reply_kv](chmpxpx_svr_reply_kvja.html) - キーバリュー形式メッセージを返信する
- [chmpxpx_slv_receive](chmpxpx_slv_receiveja.html) - メッセージを受信する
- [chmpxpx_slv_receive_kv](chmpxpx_slv_receive_kvja.html) - キーバリュー形式メッセージを受信する
- [chmpxpx_slv_send](chmpxpx_slv_sendja.html) - メッセージを送信する
- [chmpxpx_slv_send_kv](chmpxpx_slv_send_kvja.html) - キーバリュー形式メッセージを送信する
- [chmpxpx_print_version](chmpxpx_print_versionja.html) - ライブラリのバージョンなどを表示する
