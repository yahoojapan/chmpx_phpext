---
layout: contents
language: en-us
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_createja.html
lang_opp_word: To Japanese
prev_url: chmpx_class_destruct.html
prev_string: Chmpx::__destruct
top_url: chmpx_class.html
top_string: Chmpx Class
next_url: chmpx_class_createserver.html
next_string: Chmpx::createServer
---

# Chmpx::create
Creates a ChmpxServer/ChmpxSlave instance

## Description

```
public function create(string $filepath, bool $is_on_server, bool $is_auto_rejoin = false): bool
```

Creates a ChmpxServer/ChmpxSlave instance.

## Parameters
* filepath
  * Specifies the chmpx configuration file path.
* is_on_server
  * True if a ChmpxServer instance.
* is_auto_rejoin
  * True if reconnect with a chmpx server/slave process automatically

## Return Values
Returns true on success or false on failure. 

## Examples

```
php -r '$chmpx = new Chmpx(); var_dump($chmpx->create("./tests/server.yaml", true));' 
```

The above example will output:

```
bool(true)
```


## See Also
- [Chmpx::destroy](chmpx_class_destroy.html) - Destroys a Chmpx instance
