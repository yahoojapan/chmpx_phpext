---
layout: contents
language: en-us
title: chmpxpx_create_slave
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_create_slaveja.html
lang_opp_word: To Japanese
prev_url: chmpxpx_create_server.html
prev_string: chmpxpx_create_server
top_url: chmpxpx.html
top_string: chmpxpx Functions
next_url: chmpxpx_destroy.html
next_string: chmpxpx_destroy
---

# chmpxpx_create_slave
Creates a chmpx handle for a chmpx slave process

## Description

```
function chmpxpx_create_slave(string $filepath, bool $is_auto_rejoin = false) {}
```

Creates a chmpx handle for a chmpx slave process.

## Parameters
* filepath
  * Specifies the chmpx configuration file path.
* is_auto_rejoin
  * True if reconnect with a chmpx slave process automatically

## Return Values
Returns a chmpx handle resource on success or false on failure. 

## Examples

```
php -r 'var_dump(chmpxpx_create_slave("./tests/slave.yaml"));'
```

The above example will output:

```
resource(4) of type (chmpx_handle)
```

## See Also
- [Chmpx::create](chmpx_class_create.html) - Creates a chmpx handle
