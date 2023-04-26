---
layout: contents
language: en-us
title: chmpxpx_set_debug_file
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_set_debug_fileja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_process_running.html
prev_string: chmpxpx_process_running
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_set_debug_level_error.html
next_string: chmpxpx_set_debug_level_error
---

# chmpxpx_set_debug_file
Writes log to the file

## Description

```
function chmpxpx_set_debug_file(string $filepath): bool {}
```

Writes log to the file. 

## Parameters
* filepath
  * Specifies path to the file where to write logs.

## Return Values
Returns true on success or false on failure. 

## Examples
- Example 1 - Write log to a file

```
<?php
var_dump(chmpxpx_set_debug_file("/tmp/chmpx.log"));
?>
```

The above example will output:

```
NULL
```


## See Also
- [chmpxpx_bump_debug_level](chmpxpx_bump_debug_level.html) - Changes the log level
- [chmpxpx_set_debug_level_error](chmpxpx_set_debug_level_error.html) - Sets log level to error
- [chmpxpx_set_debug_level_message](chmpxpx_set_debug_level_message.html) - Sets log level to info
- [chmpxpx_set_debug_level_silent](chmpxpx_set_debug_level_silent.html) - Stops logging
- [chmpxpx_set_debug_level_warning](chmpxpx_set_debug_level_warning.html) - Sets log level to warning
- [chmpxpx_unset_debug_file](chmpxpx_unset_debug_file.html) - Writes logs to stderr
