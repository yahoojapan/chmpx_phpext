---
layout: contents
language: ja
title: chmpxpx_svr_reply
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_reply.html
lang_opp_word: To English
prev_url: chmpxpx_svr_receive_kvja.html
prev_string: chmpxpx_svr_receive_kv
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_svr_reply_kvja.html
next_string: chmpxpx_svr_reply_kv
---

# chmpxpx_svr_reply
メッセージを返信する

## 説明

```
function chmpxpx_svr_reply($handle_res, $handle_pxpk, string $strbinary): bool {}
```

メッセージを返信する。

## パラメータ

* handle_res
  * chmpxハンドル
* handle_pxpk
  * chmpx通信情報ハンドル
* strbinary
  * 返信メッセージデータ

## 戻り値
成功時は真。それ以外は偽。

## 参考
- [ChmpxServer::reply](chmpxserver_class_replyja.html) - メッセージを返信する
