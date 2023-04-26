---
layout: contents
language: ja
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_createserver.html
lang_opp_word: To English
prev_url: chmpx_class_createja.html
prev_string: Chmpx::create
top_url: chmpx_classja.html
top_string: Chmpx Class
next_url: chmpx_class_createslaveja.html
next_string: Chmpx::createSlave
---

# Chmpx::createServer
ChmpxServerインスタンスを作成する
 
## Description

```
public function createServer(string $filepath, bool $is_auto_rejoin = false): bool
```

ChmpxServerインスタンスを作成します。

## Parameters
* filepath
  * chmpxの設定ファイルのパス。
* is_auto_rejoin
  * 真ならばchmpxのサーバまたはchmpxのスレーブプロセスに自動的に再接続する。

## Return Values
成功ならば真。

## Examples

```
php -r '$chmpx = new Chmpx(); var_dump($chmpx->createServer("./tests/server.yaml", true));' 
```

上の例は、下のように出力されます。

```
bool(true)
```

## See Also
- [Chmpx::destroy](chmpx_class_destroy.html) - Chmpxインスタンスを解放する

