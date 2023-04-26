---
layout: contents
language: ja
title: Chmpx::__construct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_construct.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: chmpx_classja.html
top_string: Chmpx Class
next_url: chmpx_class_destructja.html
next_string: Chmpx::__destruct
---

# Chmpx::__construct
新しいChmpxオブジェクトを作成する

## 説明

```
public function __construct() {}
```

新しい[Chmpx](chmpx_classja.html)オブジェクトを作成します。 

## パラメータ
なし

## 例

```
$ php -r 'var_dump(new Chmpx());'
```

上の例は、下のように表示されます。
```
object(Chmpx)#1 (2) {
  ["chmpx_handle":"Chmpx":private]=>
  resource(4) of type (chmpx_handle)
  ["is_server_mode":"Chmpx":private]=>
  resource(5) of type (is_server_mode)
}
```

## 参考
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [Chmpx::getChmpxSlave](chmpx_class_getchmpxslaveja.html) - ChmpxSlaveインスタンスを取得する
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserverja.html) - ChmpxServerインスタンスを取得する
