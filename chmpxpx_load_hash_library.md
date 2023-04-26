---
layout: contents
language: en-us
title: chmpxpx_load_hash_library
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_load_hash_libraryja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_load_debug_env.html
prev_string: chmpxpx_load_debug_env
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_msgid_close.html
next_string: chmpxpx_msgid_close
---

# chmpxpx_load_hash_library
Loads hash functions from the file

## Description

```
function chmpx_load_hash_library(string $libpath): bool {}
```

Loads hash functions from the file. 

## Parameters
* libpath
  * Specifies the file path of hash functions defined.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Loads hash functions from the file

```
<?php
var_dump(chmpxpx_load_hash_library("/usr/lib/libchmpxtest.so"));
?>
```

The above example will output:

```
bool(true)
```


## See Also
- [chmpxpx_unload_hash_library](chmpxpx_unload_hash_library.html) - Removes the user-defined hash library
