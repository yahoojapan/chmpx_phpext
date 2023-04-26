---
layout: contents
language: en-us
title: chmpxpx_unload_hash_library
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_unload_hash_libraryja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_svr_reply_kv.html
prev_string: chmpxpx_svr_reply_kv
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_unset_debug_file.html
next_string: chmpxpx_unset_debug_file
---

# chmpxpx_unload_hash_library
Removes the user-defined hash library

## Description

```
function chmpxpx_unload_hash_library(): bool {}
```

Removes the user-defined hash library that is added by chmpxpx_load_hash_library. 

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Removes the user-defined hash library

```
<?php
var_dump(chmpxpx_unload_hash_library());
?>
```

The above example will output:

```
bool(true)
```


## See Also
- [chmpxpx_load_hash_library](chmpxpx_load_hash_library.html) - Loads hash functions from the file
