---
layout: contents
language: ja
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_getchmpxslave.html
lang_opp_word: To English
prev_url: chmpx_class_getchmpxserverja.html
prev_string: Chmpx::getChmpxServer
top_url: chmpx_classja.html
top_string: Chmpx Class
next_url:
next_string:
---

# Chmpx::getChmpxSlave
ChmpxSlaveインスタンスを取得する

## Description

```
public function getChmpxSlave(bool $no_giveup_rejoin = false): ChmpxSlave|false {}
```

ChmpxSlaveインスタンスを取得します。

## Parameters

* no_giveup_rejoin
  * 真ならば、CHMPXが停止した場合に、再起動待ちの上限回数を無視（上限なし）。

## Return Values

成功時はChmpxSlaveインスタンス。失敗時は偽。

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createSlave("./tests/slave.yaml", true); var_dump($chmpx->getChmpxSlave());'
```

上の例は、下のように出力されます。

```
object(ChmpxSlave)#2 (2) {
  ["chmpx_handle"]=>
  resource(9) of type (chmpx_handle)
  ["msgid_handle"]=>
  resource(8) of type (msgid_handle)
}
```

## See Also
- [Chmpx::construct](chmpx_class_constructja.html) - Chmpxインスタンスを作成する
- [Chmpx::destruct](chmpx_class_destructja.html) - Chmpxインスタンスを解放する
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
