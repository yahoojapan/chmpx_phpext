---
layout: contents
language: ja
title: ChmpxServer Class
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class.html
lang_opp_word: To English
prev_url: chmpx_classja.html
prev_string: Chmpx
top_url: developerja.html
top_string: Developer
next_url: chmpxslave_classja.html
next_string: ChmpxSlave
---

# ChmpxServer クラス
ChmpxServerクラスは、[CHMPX](https://chmpx.antpick.ax/indexja.html)を操作するメソッドを提供します。  

## Class 概要

```
class ChmpxServer {
    /** @var resource|null */
    public $chmpx_handle;
    /** @var resource|null */
    public $chmpx_pkt_handle;

    /**
     * @param resource $handle
     */
    public function __construct($handle) {}
    public function __destruct() {}
	
    /** @param string $strbinary */
    public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT,  bool $no_giveup_rejoin = false): bool {}
    /**
     * @param string $strbinkey
     * @param string $strbinval
     */
    public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false): bool {}
	
    public function reply(string $strbinary):bool {}
    public function replyKv(string $strbinkey, string $strbinval):bool {}
}
```


## メソッド一覧

- [ChmpxServer::__construct](chmpxserver_class_constructja.html) - ChmpxServerインスタンスを作成する
- [ChmpxServer::__destruct](chmpxserver_class_destructja.html) - ChmpxServerインスタンスを解放する
- [ChmpxServer::receive](chmpxserver_class_receiveja.html) - メッセージを受信する
- [ChmpxServer::receiveKv](chmpxserver_class_receivekvja.html) - キーバリュー形式のメッセージを受信する
- [ChmpxServer::reply](chmpxserver_class_replyja.html) - メッセージを返信する
- [ChmpxServer::replyKv](chmpxserver_class_replykvja.html) - キーバリュー形式のメッセージを返信する
