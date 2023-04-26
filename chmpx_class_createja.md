---
layout: contents
language: ja
title: Chmpx::push
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_create.html
lang_opp_word: To English
prev_url: chmpx_class_destructja.html
prev_string: Chmpx::__destruct
top_url: chmpx_classja.html
top_string: Chmpx Class
next_url: chmpx_class_createserverja.html
next_string: Chmpx::createServer
---

# Chmpx::create
ChmpxServer/ChmpxSlaveインスタンスを作成する。

## Description

```
public function create(string $filepath, bool $is_on_server, bool $is_auto_rejoin = false): bool
```

ChmpxServer/ChmpxSlaveインスタンスを作成します。

## Parameters
* filepath
  * chmpxの設定ファイルのパス。
* is_on_server
  * 真ならばChmpxServerインスタンスを生成する。
* is_auto_rejoin
  * 真ならばchmpxのサーバまたはchmpxのスレーブプロセスに自動的に再接続する。

## Return Values
成功ならば真。

## Examples

```
php -r '$chmpx = new Chmpx(); var_dump($chmpx->create("./tests/server.yaml", true));' 
```

上の例は、下のように出力されます。

```
bool(true)
```


## See Also
- [Chmpx::destroy](chmpx_class_destroy.html) - Chmpxインスタンスを解放する
