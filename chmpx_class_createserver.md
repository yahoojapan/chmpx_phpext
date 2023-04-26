---
layout: contents
language: en-us
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_createserverja.html
lang_opp_word: To Japanese
prev_url: chmpx_class_create.html
prev_string: Chmpx::create
top_url: chmpx_class.html
top_string: Chmpx Class
next_url: chmpx_class_createslave.html
next_string: Chmpx::createSlave
---

# Chmpx::createServer
Creates a ChmpxServer instance
 
## Description

```
public function createServer(string $filepath, bool $is_auto_rejoin = false): bool
```

Creates a ChmpxServer instance.

## Parameters
* filepath
  * Specifies the chmpx configuration file path.
* is_auto_rejoin
  * True if reconnect with a chmpx server/slave process automatically.

## Return Values
Returns true on success or false on failure. 

## Examples

```
php -r '$chmpx = new Chmpx(); var_dump($chmpx->createServer("./tests/server.yaml", true));' 
```

The above example will output:

```
bool(true)
```

## See Also
- [Chmpx::destroy](chmpx_class_destroy.html) - Destroys a Chmpx instance

