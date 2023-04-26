---
layout: contents
language: ja
title: 実行時変数
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: configurations.html
lang_opp_word: To English
prev_url: developerja.html
prev_string: Developer
top_url: indexja.html
top_string: TOP
next_url: 
next_string:
---

# 環境変数
CHMPX PHP Extension ライブラリは、独自の環境変数を使いません。  
しかし、CHMPX PHP Extension ライブラリが読み込む[CHMPX](https://chmpx.antpick.ax/indexja.html)によって、環境変数が読み込まれます。  
これらの環境変数については、[こちら](https://chmpx.antpick.ax/configurationsja.html)を参照してください。  
[CHMPX](https://chmpx.antpick.ax/indexja.html)の[環境変数](https://chmpx.antpick.ax/configurationsja.html)は、CHMPXライブラリの動作確認、デバッグなどで利用できます。

# 実行時設定
ライブラリの動作は、php.iniに書かれた設定や[ini_set関数](https://www.php.net/manual/ja/function.ini-set)によって変えられます。CHMPX PHP Extensionでは、以下の設定項目が定義されています。

## chmpxpx.debug
ログレベルを、以下の中から一つ指定してください。この値は、どこでも設定が可能です（`PHP_INI_ALL`）。

- **error**  
エラーメッセージをログに記録します。
- **warning**  
エラーメッセージ、警告メッセージをログに記録します。
- **info**  
エラーメッセージ、警告メッセージ、通知メッセージをログに記録します。
- **silent(default)**  
ログに記録されるメッセージはありません。デフォルトのログレベルです。
 
