---
layout: contents
language: ja
title: chmpxpx_load_hash_librarmy
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_load_hash_library.html
lang_opp_word: To English
prev_url: chmpxpx_load_debug_envja.html
prev_string: chmpxpx_load_debug_env
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_msgid_closeja.html
next_string: chmpxpx_msgid_close
---

# chmpxpx_load_hash_library
ハッシュ関数を有効にする

## 説明

```
function chmpxpx_load_hash_library(string $libpath): bool {}
```

ハッシュ関数を有効にします。 

## パラメータ
* libpath
  * 共有ライブラリファイルのパス

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例
- 例 1 - ハッシュ関数用ライブラリを読み込む

```
<?php
var_dump(chmpxpx_load_hash_library("/usr/lib/libchmpxtest.so"));
?>
```

上の例の出力は以下となります。

```
bool(true)
```


## 参考
- [chmpxpx_unload_hash_library](chmpxpx_unload_hash_libraryja.html) - ハッシュ関数ライブラリを取り外す
