---
layout: contents
language: ja
title: chmpxpx_unload_hash_library
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_unload_hash_library.html
lang_opp_word: To English
prev_url: chmpxpx_svr_reply_kvja.html
prev_string: chmpxpx_svr_reply_kv
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_unset_debug_fileja.html
next_string: chmpxpx_unset_debug_file
---

# chmpxpx_unload_hash_library
ハッシュ関数ライブラリを取り外す

## 説明

```
function chmpxpx_unload_hash_library(): bool {}
```

chmpxpx_load_hash_libraryでロードした共有ライブラリファイルを取り外します。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ハッシュ関数用ライブラリを取り外す

```
<?php
var_dump(chmpxpx_unload_hash_library());
?>
```

上の例の出力は以下となります。

```
bool(true)
```


## 参考
- [chmpxpx_load_hash_library](chmpxpx_load_hash_libraryja.html) - ハッシュ関数を有効にする
