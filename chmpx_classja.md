---
layout: contents
language: ja
title: Chmpx Class
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class.html
lang_opp_word: To English
prev_url: constantsja.html
prev_string: 定数
top_url: developerja.html
top_string: Developer
next_url: chmpxserver_classja.html
next_string: ChmpxServer Class
---

# Chmpx クラス
Chmpxクラスは、[CHMPX](https://chmpx.antpick.ax/indexja.html)を操作するメソッドを提供します。  

## Class 概要

```
Chmpx {
    public function __construct()
    public function __destruct()
    public function create(string $filepath, bool $is_on_server, bool $is_auto_rejoin = false): bool
    public function createServer(string $filepath, bool $is_auto_rejoin = false): bool
    public function createSlave(string $filepath, bool $is_auto_rejoin = false): bool
    public function destroy(): bool
    public function isRunning(): bool
    public function getChmpxSlave(bool $no_giveup_rejoin = false): ChmpxSlave|false {}
    public function getChmpxServer(): ChmpxServer|false {}
}
```

## メソッド一覧
- [Chmpx::__construct](chmpx_class_constructja.html) - Chmpxインスタンスを作成する
- [Chmpx::__destruct](chmpx_class_destructja.html) - Chmpxインスタンスを解放する
- [Chmpx::create](chmpx_class_createja.html) - ChmpxServer/ChmpxSlaveインスタンスを作成する
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [Chmpx::destroy](chmpx_class_destroyja.html) - Chmpxインスタンスを解放する
- [Chmpx::isRunning](chmpx_class_isrunningja.html) - chmpxプロセスを確認する
- [Chmpx::getChmpxSlave](chmpx_class_getchmpxslaveja.html) - ChmpxSlaveインスタンスを取得する
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserverja.html) - ChmpxServerインスタンスを取得する
