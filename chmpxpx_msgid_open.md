---
layout: contents
language: en-us
title: chmpxpx_msgid_open
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_msgid_openja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_msgid_close.html
prev_string: chmpxpx_msgid_close
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_pkth_close.html
next_string: chmpxpx_pkth_close
---

# chmpxpx_msgid_open
Opens a chmpx message handle

## Description

```
function chmpxpx_msgid_open($handle_res, bool $no_giveup_rejoin = false) {}
```

Opens a chmpx message handle.

## Parameters
* handle_res
  * Specifies a chmpx handle
* is_auto_rejoin
  * True if reconnect with a chmpx server/slave process automatically.

## Return Values
Returns a chmpx message handle on success, otherwise false. 

## See Also
- [chmpxpx_msgid_close](chmpxpx_msgid_close.html) - Closes a chmpx message handle
