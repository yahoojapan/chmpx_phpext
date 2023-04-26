---
layout: contents
language: ja
title: ChmpxSlave::__destruct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_destruct.html
lang_opp_word: To English
prev_url: chmpxslave_class_constructja.html
prev_string: ChmpxSlave::__construct
top_url: chmpxslave_classja.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_receiveja.html
next_string: ChmpxSlave::receive
---

# ChmpxSlave::__destruct
ChmpxSlaveインスタンスを解放する

## 説明

```
public function __destruct()
```

ChmpxSlaveインスタンスを解放します。

## パラメータ

## 例

```
php -r '
> $handle = chmpxpx_create("./tests/slave.yaml", false, true); 
> $slvobj = new ChmpxSlave($handle);
> unset($slvobj);
> chmpxpx_destroy($handle);
'
```

## 参考
- [ChmpxSlave::construct](chmpxslave_class_construct.html) - ChmpxSlaveインスタンスを作成する
