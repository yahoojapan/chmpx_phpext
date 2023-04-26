---
layout: contents
language: ja
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_getchmpxserver.html
lang_opp_word: To English
prev_url: chmpx_class_isrunningja.html
prev_string: Chmpx::isRunning
top_url: chmpx_classja.html
top_string: Chmpx Class
next_url: chmpx_class_getchmpxslaveja.html
next_string: Chmpx::getChmpxSlave
---

# Chmpx::getChmpxServer
ChmpxServerインスタンスを取得する
 
## Description

```
public function getChmpxServer(): ChmpxServer|false {}
```

ChmpxServerインスタンスを取得します。

## Parameters

## Return Values
成功時はChmpxServerインスタンス。

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createServer("./tests/server.yaml", true); var_dump($chmpx->getChmpxServer());'
```

上の例は、下のように出力されます。

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
- [Chmpx::construct](chmpx_class_constructja.html) - Chmpxインスタンスを作成する
- [Chmpx::destruct](chmpx_class_destructja.html) - Chmpxインスタンスを解放する
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
