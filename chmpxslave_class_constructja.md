---
layout: contents
language: ja
title: ChmpxSlave::__construct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_construct.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: chmpxserver_classja.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_destructja.html
next_string: ChmpxSlave::__destruct
---

# ChmpxSlave::__construct
ChmpxSlaveインスタンスを作成する

## 説明

```
public function __construct($handle, bool $no_giveup_rejoin = false) {}
```

[ChmpxSlave](chmpxslave_class.html)インスタンスを作成します。

## パラメータ
* handle
  * chmpx ハンドル
* no_giveup_rejoin
  * 真ならばchmpxのサーバまたはchmpxのスレーブプロセスに自動的に再接続する。

## 例

```
php -r '
> $handle = chmpxpx_create("./tests/slave.yaml", false, true);
> $slvobj = new ChmpxSlave($handle);
> chmpxpx_destroy($handle);
'
```

上の例は、下のように出力されます。

```
object(ChmpxSlave)#1 (2) {
  ["chmpx_handle"]=>
  resource(4) of type (chmpx_handle)
  ["msgid_handle"]=>
  resource(5) of type (msgid_handle)
}
```


## 参考
- [chmpxpx_create](chmpxpx_create.html) - chmpx ハンドルを作成する
- [chmpxpx_destroy](chmpxpx_create.html) - chmpx ハンドルを解放する

