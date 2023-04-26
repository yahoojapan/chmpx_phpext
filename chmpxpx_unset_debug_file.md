---
layout: contents
language: en-us
title: chmpxpx_unset_debug_file
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_unset_debug_fileja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_unload_hash_library.html
prev_string: chmpxpx_unload_hash_library
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url:
next_string:
---

# chmpxpx_unset_debug_file
Set log output  to stderr

## Description

```
function chmpxpx_unset_debug_file(): bool {}
```

Set log output  to stderr.

## Parameters
This function has no parameters.

## Examples
- Example 1 - Set log output  to stderr

```
<?php
var_dump(chmpxpx_unset_debug_file());
?>
```

The above example will output:

```
NULL
```


## See Also
- [chmpxpx_bump_debug_level](chmpxpx_bump_debug_level.html) - Changes the log level
- [chmpxpx_set_debug_file](chmpxpx_set_debug_file.html) - Writes log to the file
- [chmpxpx_set_debug_level_error](chmpxpx_set_debug_level_error.html) - Sets log level to error
- [chmpxpx_set_debug_level_message](chmpxpx_set_debug_level_message.html) - Sets log level to info
- [chmpxpx_set_debug_level_silent](chmpxpx_set_debug_level_silent.html) - Stops logging
- [chmpxpx_set_debug_level_warning](chmpxpx_set_debug_level_warning.html) - Sets log level to warning
