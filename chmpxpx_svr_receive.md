---
layout: contents
language: en-us
title: chmpxpx_svr_receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_receiveja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_slv_send_kv.html
prev_string: chmpxpx_slv_send_kv
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_receive_kv.html
next_string: chmpxpx_svr_receive_kv
---

# chmpxpx_svr_receive
Receives a message

## Description

```
function chmpxpx_svr_receive($handle_res, &$strbinary, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false) {}
```

Receives a message.

## Parameters

* handle_res
  * Specifies a chmpx handle
* strbinary
  * Specifies received data variable by reference
* timeout_ms
  * Specifies waiting time
* no_giveup_rejoin
  * Specifies true if reconnect automatically with a chmpx server process

## Return Values
Returns chmpx communication information handle on success or false on failure. 

## See Also
- [ChmpxServer::receive](chmpxserver_class_receive.html) - Receives a message
