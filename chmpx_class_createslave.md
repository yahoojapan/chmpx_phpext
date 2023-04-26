---
layout: contents
language: en-us
title: Chmpx::createSlave
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_createslaveja.html
lang_opp_word: To Japanese
prev_url: chmpx_class_createserver.html
prev_string: Chmpx::createServer
top_url: chmpx_class_class.html
top_string: Chmpx Class
next_url: chmpx_class_destroy.html
next_string: Chmpx::destroy
---

# Chmpx::createSlave
Creates a ChmpxSlave instance

## Description

```
public function createSlave(string $filepath, bool $is_auto_rejoin = false): bool
```

Creates a ChmpxSlave instance.

## Parameters
* filepath
  * Specifies the chmpx configuration file path.
* is_auto_rejoin
  * True if reconnect with a chmpx server/slave process automatically.

## Return Values
Returns true on success or false on failure. 

## Examples
```
php -r '$chmpx = new Chmpx(); var_dump($chmpx->createSlave("./tests/slave.yaml", true));' 
```

The above example will output:

```
bool(true)
```

## See Also
- [Chmpx::destroy](chmpx_class_destroy.html) - Destroys a Chmpx instance

