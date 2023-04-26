---
layout: contents
language: en-us
title: chmpxpx_svr_reply
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_replyja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_svr_receive_kv.html
prev_string: chmpxpx_svr_receive_kv
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_reply_kv.html
next_string: chmpxpx_svr_reply_kv
---

# chmpxpx_svr_reply
Replies a message

## Description

```
function chmpxpx_svr_reply($handle_res, $handle_pxpk, string $strbinary): bool {}
```

Replies a message.

## Parameters

* handle_res
  * Specifies a chmpx handle
* handle_pxpk
  * Specifies a chmpx communication information handle
* strbinary
  * Specifies a message to be replied

## Return Values
Returns true on success or false on failure. 

## See Also
- [ChmpxServer::reply](chmpxserver_class_reply.html) - Sets the value associated with the key
