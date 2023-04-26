---
layout: contents
language: en-us
title: chmpxpx_svr_reply_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_reply_kvja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_svr_reply.html
prev_string: chmpxpx_svr_reply
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_unload_hash_library.html
next_string: chmpxpx_unload_hash_library
---

# chmpxpx_svr_reply_kv
Replies a key and a value message

## Description

```
function chmpxpx_svr_reply_kv($handle_res, $handle_pxpk, string $strbinkey, string $strbinval): bool {}
```

Replies a key and a value message.

## Parameters

* handle_res
  * Specifies a chmpx handle
* handle_pxpk
  * Specifies a chmpx communication information handle
* strbinkey
  * Specifies key data
* strbinval
  * Specifies value data

## Return Values
Returns true on success or false on failure. 

## See Also
- [ChmpxServer::replyKv](chmpxserver_class_replykv.html) - Replies a key and a value message
