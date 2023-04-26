---
layout: contents
language: ja
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_destroy.html
lang_opp_word: To English
prev_url: chmpx_class_createslaveja.html
prev_string: Chmpx::createSlave
top_url: chmpx_classja.html
top_string: Chmpx Class
next_url: chmpx_class_isrunningja.html
next_string: Chmpx::isRunning
---

# Chmpx::destroy
Chmpxインスタンスを解放する

## Description

```
public function destroy(): bool
```

Chmpxインスタンスを解放します。

## Parameters

## Return Values
成功ならば真。

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createServer("./tests/server.yaml", true); var_dump($chmpx->destroy());'
```

上の例は、下のように出力されます。

```
bool(true)
```

## See Also
- [Chmpx::create](chmpx_class_createja.html) - ChmpxServer/ChmpxSlaveインスタンスを作成する
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
