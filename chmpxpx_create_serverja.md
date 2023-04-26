---
layout: contents
language: ja
title: chmpxpx_create_server
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_create.html
lang_opp_word: To English
prev_url: chmpxpx_closeja.html
prev_string: chmpxpx_close
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_create_slaveja.html
next_string: chmpxpx_create_slave
---

# chmpxpx_create_server
chmpxハンドルを作る

## 説明

```
function chmpx_create_server(string $filepath, bool $is_auto_rejoin = false) {}
```

chmpxハンドルを作ります。

## パラメータ
* filepath
  * chmpxの設定ファイルのパス。
* is_auto_rejoin
  * 真ならばchmpxのサーバまたはchmpxのスレーブプロセスに自動的に再接続する。

## 戻り値
成功時は、chmpxハンドル。失敗時は偽。

## 例

```
php -r 'var_dump(chmpxpx_create_server("./tests/server.yaml"));'
```

上の例は、下のように出力されます。

```
resource(4) of type (chmpx_handle)
```

## 参考
- [Chmpx::create](chmpx_class_createja.html) - chmpxハンドルを作成する

