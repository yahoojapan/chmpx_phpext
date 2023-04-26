---
layout: contents
language: ja
title: chmpxpx_slv_receive_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_receive_kv.html
lang_opp_word: To English
prev_url: chmpxpx_slv_receiveja.html
prev_string: chmpxpx_slv_receive
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_slv_sendja.html
next_string: chmpxpx_slv_send
---

# chmpxpx_slv_receive_kv
キーとバリューのメッセージを受け取る


## 説明

```
function chmpxpx_slv_receive_kv($handle_res, $handle_msgid, &$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT): bool {}
```

キーとバリューのメッセージを受け取ります。

## パラメータ

* handle_res
  * chmpxハンドル
* handle_msgid
  * chmpxメッセージハンドル
* strbinkey
  * キーとして受信するデータ（参照渡し）
* strbinval
  * バリューとして受信するデータ（参照渡し）
* timeout_ms
  * 待ち時間

## 戻り値
成功時は真。失敗時はそれ以外。

## 参考
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekvja.html) - キーとバリューのメッセージを受け取る
