---
layout: contents
language: ja
title: chmpxpx_slv_send
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_send.html
lang_opp_word: To English
prev_url: chmpxpx_slv_receive_kvja.html
prev_string: chmpxpx_slv_receive_kv
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_slv_send_kvja.html
next_string: chmpxpx_slv_send_kv
---

# chmpxpx_slv_send
メッセージを送信する

## 説明

```
function chmpxpx_slv_send($handle_res, $handle_msgid, string $strbinary, bool $is_routing = true, bool $is_broadcast = false): int {}
```

メッセージを送信します。

## パラメータ

* handle_res
  * chmpxハンドル
* handle_msgid
  * chmpxメッセージハンドル
* strbinary
  * 送信メッセージ
* is_routing
  * ルーティングを有効にするなら、真。
* is_broadcast
  * 同報通知を有効にするなら、真。

## 戻り値
送信メッセージ長

## 参考
- [ChmpxSlave::send](chmpxslave_class_sendja.html) - メッセージを送信する
