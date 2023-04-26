---
layout: contents
language: en-us
title: chmpxpx_create
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_createja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_bump_debug_level.html
prev_string: chmpxpx_bump_debug_level
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_create_server.html
next_string: chmpxpx_create_server
---

# chmpxpx_create
Creates a chmpx handle

## Description

```
function chmpxpx_create(string $filepath, bool $is_on_server, bool $is_auto_rejoin = false) {}
```

Creates a chmpx handle.

## Parameters
* filepath
  * Specifies the chmpx configuration file path.
* is_on_server
  * True if a ChmpxServer instance.
* is_auto_rejoin
  * True if reconnect with a chmpx server/slave process automatically

## Return Values
Returns a chmpx handle resource on success or false on failure. 

## Examples

```
php -r 'var_dump(chmpxpx_create("./tests/server.yaml", true));'
```

The above example will output:

```
resource(4) of type (chmpx_handle)
```

## See Also
- [Chmpx::create](chmpx_class_create.html) - Creates a chmpx handle
