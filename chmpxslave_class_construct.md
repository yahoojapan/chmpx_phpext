---
layout: contents
language: en-us
title: ChmpxSlave::__construct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: chmpxserver_class.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_destruct.html
next_string: ChmpxSlave::__destruct
---

# ChmpxSlave::__construct
Creates a ChmpxSlave instance

## Description

```
public function __construct($handle, bool $no_giveup_rejoin = false) {}
```

Creates a [ChmpxSlave](chmpxslave_class.html) instance. 

## Parameters

* filepath
  * Specifies the chmpx configuration file path.
* is_auto_rejoin
  * True if reconnect with a chmpx server/slave process automatically.

## Examples

```
php -r '$handle = chmpxpx_create("./tests/slave.yaml", false, true); $slvobj = new ChmpxSlave($handle); chmpxpx_destroy($handle);'
```

The above example will output:

```
object(ChmpxSlave)#1 (2) {
  ["chmpx_handle"]=>
  resource(4) of type (chmpx_handle)
  ["msgid_handle"]=>
  resource(5) of type (msgid_handle)
}
```


## See Also
- [chmpxpx_create](chmpxpx_create.html) - Creates a chmpx handle
- [chmpxpx_destroy](chmpxpx_create.html) - Destroys a chmpx handle


