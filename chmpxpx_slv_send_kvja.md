---
layout: contents
language: ja
title: chmpxpx_slv_send_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_send_kv.html
lang_opp_word: To English
prev_url: chmpxpx_slv_sendja.html
prev_string: chmpxpx_slv_send
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_receiveja.html
next_string: chmpxpx_svr_receive
---

# chmpxpx_slv_send_kv
キーバリュー形式のメッセージを送信する

## 説明

```
function chmpxpx_slv_send_kv($handle_res, $handle_msgid, string $strbinkey, string $strbinval, bool $is_routing = true, bool $is_broadcast = false): int {}
```

キーバリュー形式のメッセージを送信します。

## パラメータ
* handle_res
  * chmpxハンドル
* handle_msgid
  * chmpxメッセージハンドル
* strbinkey
  * キーとして送信するデータ
* strbinval
  * バリューとして送信するデータ
* is_routing
  * メッセージをルーティング可能な状態で送信するなら真。
* is_broadcast
  * メッセージを全てのサーバに送信するなら真

## 戻り値
送信メッセージ長

## 参考
- [ChmpxSlave::sendKv](chmpxslave_class_sendkvja.html) - キーバリュー形式のメッセージを送信する
