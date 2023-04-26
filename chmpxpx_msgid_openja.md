---
layout: contents
language: ja
title: chmpxpx_msgid_open
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_msgid_open.html
lang_opp_word: To English
prev_url: chmpxpx_msgid_closeja.html
prev_string: chmpxpx_msgid_close
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_pkth_closeja.html
next_string: chmpxpx_pkth_close
---

# chmpxpx_msgid_open
chmpxメッセージハンドルを作成する

## 説明

```
function chmpxpx_msgid_open($handle_res, bool $no_giveup_rejoin = false) {}
```

chmpxメッセージハンドルを作成します。

## パラメータ
- handle_res
chmpxハンドル
- no_giveup_rejoin
真ならば、chmpxに自動的に再接続し続ける

## 戻り値
成功時は、chmpxメッセージハンドル。それ以外は偽。

## 参考
- [chmpxpx_msgid_close](chmpxpx_msgid_closeja.html) - chmpxメッセージハンドルを閉じる
