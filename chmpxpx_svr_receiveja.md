---
layout: contents
language: ja
title: chmpxpx_svr_receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_receive.html
lang_opp_word: To English
prev_url: chmpxpx_slv_send_kvja.html
prev_string: chmpxpx_slv_send_kv
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_receive_kvja.html
next_string: chmpxpx_svr_receive_kv
---

# chmpxpx_svr_receive
メッセージを受信する

## 説明

```
function chmpxpx_svr_receive($handle_res, &$strbinary, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false) {}
```

メッセージを受信します。

## パラメータ

* handle_res
  * chmpxハンドル
* strbinary
  * 受信メッセージ（参照渡し）
* timeout_ms
  * 待ち時間
* no_giveup_rejoin
  * 真ならばchmpxサーバプロセスに自動的に再接続する

## 戻り値
成功時はchmpx通信情報ハンドル。失敗時は偽。

## 参考
- [ChmpxServer::receive](chmpxserver_class_receiveja.html) - メッセージを受信する
