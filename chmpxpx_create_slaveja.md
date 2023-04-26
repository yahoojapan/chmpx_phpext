---
layout: contents
language: ja
title: chmpxpx_create_slave
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_create_slave.html
lang_opp_word: To English
prev_url: chmpxpx_create_serverja.html
prev_string: chmpxpx_create_server
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_destroyja.html
next_string: chmpxpx_destroy
---

# chmpxpx_create_slave
chmpxハンドルを作る

## 説明

```
function chmpxpx_create_slave(string $filepath, bool $is_auto_rejoin = false) {}
```

chmpxハンドルを作ります。

## パラメータ
* filepath
  * chmpxの設定ファイルのパス。
* is_auto_rejoin
  * 真ならばchmpxのスレーブプロセスに自動的に再接続する。

## 戻り値
成功時は、chmpxハンドル。失敗時は偽。

## 例

```
php -r 'var_dump(chmpxpx_create_slave("./tests/slave.yaml"));'
```

上の例は、下のように出力されます。

```
resource(4) of type (chmpx_handle)
```

## 参考
- [Chmpx::create](chmpx_class_createja.html) - chmpxハンドルを作成する

