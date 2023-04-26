---
layout: contents
language: ja
title: ChmpxServer::__construct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_construct.html
lang_opp_word: To English
prev_url: 
prev_string: 
top_url: chmpxserver_classja.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_destructja.html
next_string: ChmpxServer::__destruct
---

# ChmpxServer::__construct
[ChmpxServer](chmpxserver_classja.html)インスタンスを作成する。

## 説明

```
public function __construct($handle) {}
```

新しい[ChmpxServer](chmpxserver_classja.html)オブジェクトを作成します。 

## パラメータ
* handle
  * chmpx ハンドル

## 例

```
php -r '
> $handle = chmpxpx_create_server("./tests/server.yaml", true);
> $svrobj = new ChmpxServer($handle);
> var_dump($svrobj);
> chmpxpx_destroy($handle);
'
```

上の例の出力は以下となります。

```
object(ChmpxServer)#1 (3) {
  ["chmpx_handle"]=>
  resource(4) of type (chmpx_handle)
  ["chmpx_pkt_handle"]=>
  resource(5) of type (chmpx_pkt_handle)
}
```


## 参考
- [chmpxpx_create_server](chmpxpx_create_serverja.html) - chmpx ハンドル(サーバ)を作成する
- [chmpxpx_destroy](chmpxpx_destroyja.html) - chmpx ハンドルを解放する
