---
layout: contents
language: ja
title: ChmpxSlave Class
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class.html
lang_opp_word: To English
prev_url: chmpxserver_classja.html
prev_string: ChmpxServer Class
top_url: developerja.html
top_string: Developer
next_url: chmpxpxja.html
next_string: chmpxpx Functions
---

# ChmpxSlave クラス
ChmpxSlaveクラスは、[CHMPX](https://chmpx.antpick.ax/indexja.html)を操作するメソッドを提供します。  

## Class 概要

```
ChmpxSlave {
    /** @var resource|null */
    public $chmpx_handle;
    /** @var resource|null */
    public $msgid_handle;

    /**
     * @param resource $handle
     */
    public function __construct($handle, bool $no_giveup_rejoin = false) {}
    public function __destruct() {}
    
    /** @param string $strbinary */
    public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT): bool {}
    /**
     * @param string $strbinkey
     * @param string $strbinval
     */
    public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT): bool {}
	
    public function send(string $strbinary, bool $is_routing = true, bool $is_broadcast = false): int {}
    public function sendKv(string $strbinkey, string $strbinval, bool $is_routing = true, bool $is_broadcast = false): int {}
}
```


## メソッド一覧

- [ChmpxSlave::__construct](chmpxslave_class_constructja.html) - ChmpxSlaveインスタンスを作成する
- [ChmpxSlave::__destruct](chmpxslave_class_destructja.html) - ChmpxSlaveインスタンスを解放する
- [ChmpxSlave::receive](chmpxslave_class_receiveja.html) - メッセージを受信する
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekvja.html) - キーバリュー形式のメッセージを受信する
- [ChmpxSlave::send](chmpxslave_class_sendja.html) - メッセージを送信する
- [ChmpxSlave::sendKv](chmpxslave_class_sendkvja.html) - キーバリュー形式のメッセージを送信する

