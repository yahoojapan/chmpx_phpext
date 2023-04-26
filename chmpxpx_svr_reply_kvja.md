---
layout: contents
language: ja
title: chmpxpx_svr_reply_kv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_svr_reply_kv.html
lang_opp_word: To English
prev_url: chmpxpx_svr_replyja.html
prev_string: chmpxpx_svr_reply
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_unload_hash_libraryja.html
next_string: chmpxpx_unload_hash_library
---

# chmpxpx_svr_reply_kv
キーとバリューのメッセージを返信する

## 説明

```
function chmpxpx_svr_reply_kv($handle_res, $handle_pxpk, string $strbinkey, string $strbinval): bool {}
```

キーとバリューのメッセージを返信します。

## パラメータ

* handle_res
  * chmpxハンドル
* handle_pxpk
  * chmpx通信情報ハンドル
* strbinkey
  * キー
* strbinval
  * バリュー

## 戻り値
成功時は真。それ以外は偽。

## 参考
- [ChmpxServer::replyKv](chmpxserver_class_replykvja.html) - キーとバリューのメッセージを返信する
