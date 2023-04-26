---
layout: contents
language: en-us
title: Chmpx::getChmpxSlave
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_getchmpxslaveja.html
lang_opp_word: To Japanese
prev_url: chmpx_class_getchmpxserver.html
prev_string: Chmpx::getChmpxServer
top_url: chmpx_class.html
top_string: Chmpx Class
next_url:
next_string:
---

# Chmpx::getChmpxSlave
Retrieves a ChmpxSlave instance

## Description

```
public function getChmpxSlave(bool $no_giveup_rejoin = false): ChmpxSlave|false {}
```

Retrieves a ChmpxSlave instance

## Parameters

* no_giveup_rejoin
  * Specifies true if reconnect automatically with a chmpx slave process

## Return Values

A ChmpxSlave instance on success or false on failure. 

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createSlave("./tests/slave.yaml", true); var_dump($chmpx->getChmpxSlave());'
```

The above example will output:

```
object(ChmpxSlave)#2 (2) {
  ["chmpx_handle"]=>
  resource(9) of type (chmpx_handle)
  ["msgid_handle"]=>
  resource(8) of type (msgid_handle)
}
```

## See Also
- [Chmpx::construct](chmpx_class_construct.html) - Creates a empty Chmpx instance
- [Chmpx::destruct](chmpx_class_destruct.html) - Destroys a Chmpx instance
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
