---
layout: contents
language: en-us
title: Chmpx::getChmpxServer
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_getchmpxserverja.html
lang_opp_word: To Japanese
prev_url: chmpx_class_isrunning.html
prev_string: Chmpx::isRunning
top_url: chmpx_class.html
top_string: Chmpx Class
next_url: chmpx_class_getchmpxslave.html
next_string: Chmpx::getChmpxSlave
---

# Chmpx::getChmpxServer
Retrieves a ChmpxServer instance

## Description

```
public function getChmpxServer(): ChmpxServer|false {}
```

Retrieves a ChmpxServer instance.

## Parameters

## Return Values
Returns a ChmpxServer instance.

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createServer("./tests/server.yaml", true); var_dump($chmpx->getChmpxServer());'
```

The above example will output:

```
object(ChmpxServer)#2 (3) {
  ["chmpx_handle"]=>
  resource(8) of type (chmpx_handle)
  ["chmpx_pkt_handle"]=>
  resource(9) of type (chmpx_pkt_handle)
  ["handle":"ChmpxServer":private]=>
  int(-1)
}
```


## See Also
- [Chmpx::construct](chmpx_class_construct.html) - Creates a empty Chmpx instance
- [Chmpx::destruct](chmpx_class_destruct.html) - Destroys a Chmpx instance
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
