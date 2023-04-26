---
layout: contents
language: ja
title: chmpxpx_load_debug_env
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_load_debug_env.html
lang_opp_word: To English
prev_url: chmpxpx_destroyja.html
prev_string: chmpxpx_destroy
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url: chmpxpx_load_hash_libraryja.html
next_string: chmpxpx_load_hash_library
---

# chmpxpx_load_debug_env
環境変数を読み込む

## 説明

```
function chmpxpx_load_debug_env(): bool {}
```

環境変数を読み込みます。 

## パラメータ
この関数にはパラメータはありません。

## 戻り値
成功した場合に true を、失敗した場合に false を返します。 

## 例

```
<?php
var_dump(chmpxpx_load_debug_env());
?>
```

上の例の出力は以下となります。

```
bool(true)
```

