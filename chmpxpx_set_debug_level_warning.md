---
layout: contents
language: en-us
title: chmpxpx_set_debug_level_warning
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_set_debug_level_warningja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_set_debug_level_silent.html
prev_string: chmpxpx_set_debug_level_silent
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_slv_receive.html
next_string: chmpxpx_slv_receive
---

# chmpxpx_set_debug_level_warning
Sets log level to warning

## Description

```
function chmpxpx_set_debug_level_warning(): void {}
```

Sets log level to 'warning level. 

## Parameters
This function has no parameters.

## Return Values
No value is returned. 

## Examples
- Example 1 - Sets log level to warning

```
<?php
var_dump(chmpxpx_set_debug_file("/tmp/chmpx.log"));
chmpxpx_set_debug_level_warning();
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
- [chmpxpx_unset_debug_file](chmpxpx_unset_debug_file.html) - Writes logs to stderr
