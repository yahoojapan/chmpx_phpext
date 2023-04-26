---
layout: contents
language: en-us
title: chmpxpx_slv_receive_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_receive_kvja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_slv_receive.html
prev_string: chmpxpx_slv_receive
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_slv_send.html
next_string: chmpxpx_slv_send
---

# chmpxpx_slv_receive_kv
Receives a message with a key and a value


## Description

```
function chmpxpx_slv_receive_kv($handle_res, $handle_msgid, &$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT): bool {}
```

Receives a message with a key and a value.

## Parameters

* handle_res
  * Specifies a chmpx handle
* handle_msgid
  * Specifies a chmpx message handle
* strbinkey
  * Specifies received key data variable by reference
* strbinval
  * Specifies received value data variable by reference
* timeout_ms
  * Specifies waiting time

## Return Values
Returns true on success or false on failure. 

## See Also
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekv.html) - Receives a message with a key and a value
