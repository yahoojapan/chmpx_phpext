---
layout: contents
language: en-us
title: ChmpxSlave Class
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_classja.html
lang_opp_word: To Japanese
prev_url: chmpxserver_class.html
prev_string: ChmpxServer Class 
top_url: developer.html
top_string: Developer
next_url: chmpxpx.html
next_string: chmpxpx Functions
---

# ChmpxSlave Class
ChmpxSlave class provides methods to operation for [CHMPX](https://chmpx.antpick.ax/).  

## Class overview

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


## Method list

- [ChmpxSlave::__construct](chmpxslave_class_construct.html) - Creates a empty Chmpx instance
- [ChmpxSlave::__destruct](chmpxslave_class_destruct.html) - Destroys a Chmpx instance
- [ChmpxSlave::receive](chmpxslave_class_receive.html) - Receives a message
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekv.html) - Receives a message witha a key and a value
- [ChmpxSlave::send](chmpxslave_class_send.html) - Sends a message
- [ChmpxSlave::sendKv](chmpxslave_class_sendkv.html) - Sends a message with a key and a value

