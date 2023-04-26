---
layout: contents
language: en-us
title: ChmpxServer::__construct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: chmpxserver_class.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_destruct.html
next_string: ChmpxServer::__destruct
---

# ChmpxServer::__construct
Create a ChmpxServer instance

## Description

```
public function __construct($handle) {}
```

Create a [ChmpxServer](chmpxserver_class.html) instance.

## Parameters

* handle
  * Specifies a chmpx handle.

## Examples

```
php -r '
> $handle = chmpxpx_create_server("./tests/server.yaml", true);
> $svrobj = new ChmpxServer($handle);
> var_dump($svrobj);
> chmpxpx_destroy($handle);
'
```

The above example will output:

```
object(ChmpxServer)#1 (3) {
  ["chmpx_handle"]=>
  resource(4) of type (chmpx_handle)
  ["chmpx_pkt_handle"]=>
  resource(5) of type (chmpx_pkt_handle)
}
```


## See Also
- [chmpxpx_create_server](chmpxpx_create_server.html) - Creates a chmpx server handle
- [chmpxpx_destroy](chmpxpx_create.html) - Destroys a chmpx handle
