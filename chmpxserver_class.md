---
layout: contents
language: en-us
title: ChmpxServer Class
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_classja.html
lang_opp_word: To Japanese
prev_url: chmpx_class.html
prev_string: Chmpx
top_url: developer.html
top_string: Developer
next_url: chmpxslave_class.html
next_string: ChmpxSlave
---

# ChmpxServer Class
ChmpxServer class provides methods to operation for [CHMPX](https://chmpx..antpick.ax/).  

## Class overview

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


## Method list

- [ChmpxServer::__construct](chmpxserver_class_construct.html) - Creates a ChmpxServer instance
- [ChmpxServer::__destruct](chmpxserver_class_destruct.html) - Destroys a ChmpxServer instance
- [ChmpxServer::receive](chmpxserver_class_receive.html) - Receives a message
- [ChmpxServer::receiveKv](chmpxserver_class_receivekv.html) - Receives a message with a key and a value
- [ChmpxServer::reply](chmpxserver_class_reply.html) - Replies a message
- [ChmpxServer::replyKv](chmpxserver_class_replykv.html) - Replies a message with a key and a value
