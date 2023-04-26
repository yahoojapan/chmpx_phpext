---
layout: contents
language: en-us
title: chmpxpx_svr_receive_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_receive_kvja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_svr_receive.html
prev_string: chmpxpx_svr_receive
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_reply.html
next_string: chmpxpx_svr_reply
---

# chmpxpx_svr_receive_kv
Receives a message with a key and a value

## Description

```
function chmpxpx_svr_receive_kv($handle_res, &$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false) {}
```

Receives a message with a key and a value.

## Parameters

* handle_res 
  * Specifies a chmpx handle
* strbinkey
  * Specifies received key data variable by reference
* strbinval
  * Specifies received value data variable by reference
* timeout_ms
  * Specifies waiting time
* no_giveup_rejoin
  * Specifies true if reconnect automatically with a chmpx server process

## Return Values
Returns chmpx communication information handle on sucess or false on failure

## See Also
- [ChmpxServer::receive](chmpxserver_class_receivekv.html) - Receives a message with a key and a value
