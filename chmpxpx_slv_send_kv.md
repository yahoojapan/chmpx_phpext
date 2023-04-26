---
layout: contents
language: en-us
title: chmpxpx_slv_send_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_send_kvja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_slv_send.html
prev_string: chmpxpx_slv_send
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_receive.html
next_string: chmpxpx_svr_receive
---

# chmpxpx_slv_send_kv
Sends a message with a key and a value

## Description

```
function chmpxpx_slv_send_kv($handle_res, $handle_msgid, string $strbinkey, string $strbinval, bool $is_routing = true, bool $is_broadcast = false): int {}
```

Sends a message with a key and a value.

## Parameters
* handle_res
  * Specifies a chmpx handle
* handle_msgid
  * Specifies a chmpx message handle
* strbinkey
  * Specifies a key data to send
* strbinval
  * Specifies a value data to send
* is_routing
  * Specifies True if sending a message in routing mode
* is_broadcast
  * Specifies True if sending a message in broadcasting mode

## Return Values
Returns the message length.

## See Also
- [ChmpxSlave::sendKv](chmpxslave_class_sendkv.html) - Sends a message with a key and a value
