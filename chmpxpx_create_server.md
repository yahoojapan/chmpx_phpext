---
layout: contents
language: en-us
title: chmpxpx_create_server
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_createja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_close.html
prev_string: chmpxpx_close
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_create_slave.html
next_string: chmpxpx_create_slave
---

# chmpxpx_create_server
Creates a chmpx handle for a chmpx server process

## Description

```
function chmpx_create_server(string $filepath, bool $is_auto_rejoin = false) {}
```

Creates a chmpx handle for a chmpx server process.

## Parameters
* filepath
  * Specifies the chmpx configuration file path.
* is_auto_rejoin
  * True if reconnect with a chmpx server/slave process automatically

## Return Values
Returns a chmpx handle resource on success or false on failure. 

## Examples

```
php -r 'var_dump(chmpxpx_create_server("./tests/server.yaml"));'
```

The above example will output:

```
resource(4) of type (chmpx_handle)
```

## See Also
- [Chmpx::create](chmpx_class_create.html) - Creates a chmpx handle
