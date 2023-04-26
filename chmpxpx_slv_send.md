---
layout: contents
language: en-us
title: chmpxpx_slv_send
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_sendja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_slv_receive_kv.html
prev_string: chmpxpx_slv_receive_kv
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_slv_send_kv.html
next_string: chmpxpx_slv_send_kv
---

# chmpxpx_slv_send
Sends a message

## Description

```
function chmpxpx_slv_send($handle_res, $handle_msgid, string $strbinary, bool $is_routing = true, bool $is_broadcast = false): int {}
```

Sends a message.

## Parameters

* handle_res
  * Specifies a chmpx handle
* handle_msgid
  * Specifies a chmpx message handle
* strbinary
  * Specifies data to send
* is_routing
  * Specifies True if sending a message in routing mode
* is_broadcast
  * Specifies True if sending a message in broadcasting mode

## Return Values
Returns the message length

## See Also
- [ChmpxSlave::send](chmpxslave_class_send.html) - Sends a message
