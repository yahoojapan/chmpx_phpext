---
layout: contents
language: en-us
title: chmpxpx_bump_debug_level
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_bump_debug_levelja.html
lang_opp_word: To Japanese
prev_url:
prev_string:
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_create.html
next_string: chmpxpx_create
---

# chmpxpx_bump_debug_level
Changes the log level

## Description

```
function chmpxpx_bump_debug_level(): void {}
```

Changes the log level by each call. The order is 'error' , 'warning' , 'message' (info), 'dump' (debug), 'silent' (no logging). The log level turns 'error' when calling the function in the 'silent' level. 

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples

```
php -r 'var_dump(chmpxpx_bump_debug_level());'
```

The above example will output:

```
NULL
```


## See Also
- [chmpxpx_set_debug_file](chmpxpx_set_debug_file.html) - Writes log to the file
- [chmpxpx_set_debug_level_error](chmpxpx_set_debug_level_error.html) - Sets log level to error
- [chmpxpx_set_debug_level_message](chmpxpx_set_debug_level_message.html) - Sets log level to info
- [chmpxpx_set_debug_level_silent](chmpxpx_set_debug_level_silent.html) - Stops logging
- [chmpxpx_set_debug_level_warning](chmpxpx_set_debug_level_warning.html) - Sets log level to warning
- [chmpxpx_unset_debug_file](chmpxpx_unset_debug_file.html) - Writes logs to stderr
