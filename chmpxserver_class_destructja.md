---
layout: contents
language: ja
title: K2hQueue::__destruct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_destruct.html
lang_opp_word: To English
prev_url: chmpxserver_class_constructja.html
prev_string: ChmpxServer::__construct
top_url: chmpxserver_classja.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_receiveja.html
next_string: ChmpxServer::receive
---

# ChmpxServer::__destruct
ChmpxServerインスタンスを解放する

## 説明

```
public function __destruct()
```

ChmpxServerインスタンスを解放します。

## パラメータ

## 例

```
php -r '
> $handle = chmpxpx_create_server("./test_chmpx_sever.ini", true);
> $svrobj = new ChmpxServer($handle);
> unset($svrobj);
> chmpxpx_destroy($handle);
'
```

## 参考
- [chmpxpx_create_server](chmpxpx_create_serverja.html) - chmpxハンドルを作成する
- [ChmpxServer::construct](chmpxserver_class_constructja.html) - ChmpxServerインスタンスを作成する
- [chmpxpx_destroy](chmpxpx_destroyja.html) - chmpxハンドルを解放する
