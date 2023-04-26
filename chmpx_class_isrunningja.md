---
layout: contents
language: ja
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_isRunning.html
lang_opp_word: To English
prev_url: chmpx_class_destroyja.html
prev_string: Chmpx::destroy
top_url: chmpx_classja.html
top_string: Chmpx Class
next_url: chmpx_class_getchmpxserverja.html
next_string: Chmpx::getChmpxServer
---

# Chmpx::isRunning
chmpxプロセスを確認する

## Description

```
public function isRunning(): bool
```

chmpxプロセスを確認します。

## Parameters

## Return Values
chmpxプロセスが生きていれば真。

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createSlave("./tests/slave.yaml", true); var_dump($chmpx->isRunning());'
```

上の例は、下のように出力されます。

```
bool(true)
```


## See Also
- [Chmpx::construct](chmpx_class_constructja.html) - Chmpxインスタンスを作成する
- [Chmpx::create](chmpx_class_createja.html) - ChmpxServer/ChmpxSlaveインスタンスを作成する
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
