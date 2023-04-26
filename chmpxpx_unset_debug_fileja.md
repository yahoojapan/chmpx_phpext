---
layout: contents
language: ja
title: chmpxpx_unset_debug_file
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxpx_unset_debug_file.html
lang_opp_word: To English
prev_url: chmpxpx_unload_hash_libraryja.html
prev_string: chmpxpx_unload_hash_library
top_url: chmpxpxja.html
top_string: chmpxpx Functions
next_url:
next_string:
---

# chmpxpx_unset_debug_file
ログ出力先を標準エラーに指定する

## 説明

```
function chmpxpx_unset_debug_file(): bool {}
```

ログ出力先を標準エラーに指定します。 

## パラメータ
この関数にはパラメータはありません。

## 例
- 例 1 - ログ出力先を標準エラーにする

```
<?php
var_dump(chmpxpx_unset_debug_file());
?>

```

上の例の出力は以下となります。

```
NULL
```


## 参考
- [chmpxpx_bump_debug_level](chmpxpx_bump_debug_levelja.html) - ログレベルを変更する
- [chmpxpx_set_debug_file](chmpxpx_set_debug_fileja.html) - ログ出力先ファイル名を指定する
- [chmpxpx_set_debug_level_error](chmpxpx_set_debug_level_errorja.html) - ライブラリのログレベルをerrorにする
- [chmpxpx_set_debug_level_message](chmpxpx_set_debug_level_messageja.html) - ライブラリのログレベルをmessage(info相当）にする
- [chmpxpx_set_debug_level_silent](chmpxpx_set_debug_level_silentja.html) - ライブラリのログを出力しない
- [chmpxpx_set_debug_level_warning](chmpxpx_set_debug_level_warningja.html) - ライブラリのログレベルをwarningにする
