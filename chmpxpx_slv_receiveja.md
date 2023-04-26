---
layout: contents
language: ja
title: chmpxpx_slv_receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_receive.html
lang_opp_word: To English
prev_url: chmpxpx_set_debug_level_warningja.html
prev_string: chmpxpx_set_debug_level_warning
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_slv_receive_kvja.html
next_string: chmpxpx_slv_receive_kv
---

# chmpxpx_slv_receive
メッセージを受け取る


## 説明

```
function chmpxpx_slv_receive($handle_res, $handle_msgid, &$strbinary, int $timeout_ms = RCV_NO_WAIT): bool {}
```

メッセージを受け取ります。

## パラメータ

* handle_res
  * chmpxハンドル
* handle_msgid
  * chmpxメッセージハンドル
* strbinary
  * 受信するデータ（参照渡し）
* timeout_ms
  * 待ち時間

## 戻り値

成功時は真。失敗時はそれ以外。

## 参考
- [ChmpxSlave::receive](chmpxslave_class_receiveja.html) - メッセージを受け取る
