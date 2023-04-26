---
layout: contents
language: en-us
title: chmpxpx_slv_receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_slv_receiveja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_set_debug_level_warning.html
prev_string: chmpxpx_set_debug_level_warning
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_slv_receive_kv.html
next_string: chmpxpx_slv_receive_kv
---

# chmpxpx_slv_receive
Receives a message


## Description

```
function chmpxpx_slv_receive($handle_res, $handle_msgid, &$strbinary, int $timeout_ms = RCV_NO_WAIT): bool {}
```

Receives a message.

## Parameters

* handle_res
  * Specifies a chmpx handle
* handle_msgid
  * Specifies a chmpx message handle
* strbinary
  * Specifies received data variable by reference
* timeout_ms
  * Specifies waiting time

## Return Values
Returns true on success or false on failure. 

## See Also
- [ChmpxSlave::receive](chmpxslave_class_receive.html) - Receives a message
