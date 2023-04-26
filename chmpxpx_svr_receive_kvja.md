---
layout: contents
language: ja
title: chmpxpx_svr_receive_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_receive_kv.html
lang_opp_word: To English
prev_url: chmpxpx_svr_receiveja.html
prev_string: chmpxpx_svr_receive
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_replyja.html
next_string: chmpxpx_svr_reply
---

# chmpxpx_svr_receive_kv
キーとバリューのメッセージを受信する

## 説明

```
function chmpxpx_svr_receive_kv($handle_res, &$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false) {}
```

キーとバリューのメッセージを受信します。

## パラメータ
* handle_res
  * chmpxハンドル
* strbinkey
  * キーとして受信するデータ（参照渡し）
* strbinval
  * バリューとして受信するデータ（参照渡し）
* timeout_ms
  * 待ち時間を指定する
* no_giveup_rejoin
  * chmpxサーバプロセスに自動的に再接続する場合は、真を指定する

## 戻り値
成功時は、chmpx通信情報ハンドル。失敗時は偽。

## 参考
- [ChmpxServer::receive](chmpxserver_class_receivekvja.html) - キーとバリューのメッセージを受信する
