---
layout: contents
language: en-us
title: chmpxpx_load_debug_env
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_load_debug_envja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_destroy.html
prev_string: chmpxpx_destroy
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_load_hash_library.html
next_string: chmpxpx_load_hash_library
---

# chmpxpx_load_debug_env
Loads environment variables

## Description

```
function chmpxpx_load_debug_env(): bool {}
```

Loads environment variables.

## Parameters
This function has no parameters.

## Return Values
Returns true on success or false on failure. 

## Examples
```
<?php
var_dump(chmpxpx_load_debug_env());
?>
```

The above example will output:

```
bool(true)
```

