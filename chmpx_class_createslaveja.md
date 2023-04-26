---
layout: contents
language: ja
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_createslave.html
lang_opp_word: To English
prev_url: chmpx_class_createserverja.html
prev_string: Chmpx::createServer
top_url: chmpx_class_classja.html
top_string: Chmpx Class
next_url: chmpx_class_destroyja.html
next_string: Chmpx::destroy
---

# Chmpx::createSlave
ChmpxSlaveインスタンスを作成する

## Description
```
public function createSlave(string $filepath, bool $is_auto_rejoin = false): bool
```

ChmpxSlaveインスタンスを作成します。

## Parameters
* filepath
  * chmpxの設定ファイルのパス。
* is_auto_rejoin
  * 真ならばchmpxのサーバまたはchmpxのスレーブプロセスに自動的に再接続する。

## Return Values
成功ならば真。

## Examples
```
php -r '$chmpx = new Chmpx(); var_dump($chmpx->createSlave("./tests/slave.yaml", true));' 
```

上の例は、下のように出力されます。

```
bool(true)
```

## See Also
- [Chmpx::destroy](chmpx_class_destroy.html) - Chmpxインスタンスを解放する
