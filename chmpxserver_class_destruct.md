---
layout: contents
language: en-us
title: ChmpxServer::__destruct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_destructja.html
lang_opp_word: To Japanese
prev_url: chmpxserver_class_construct.html
prev_string: ChmpxServer::__construct
top_url: chmpxserver_class.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_receive.html
next_string: ChmpxServer::receive
---

# ChmpxServer::__destruct
Destroys a ChmpxServer instance

## Description

```
public function __destruct()
```

Destroys a ChmpxServer instance

## Parameters

## Examples

```
php -r '
> $handle = chmpxpx_create_server("./tests/server.yaml", true);
> $svrobj = new ChmpxServer($handle);
> unset($svrobj);
> chmpxpx_destroy($handle);
'
```

## See Also
- [chmpxpx_create_server](chmpxpx_create_server.html) - Creates a chmpx server handle
- [ChmpxServer::construct](chmpxserver_class_construct.html) - Creates a empty ChmpxServer instance
- [chmpxpx_destroy](chmpxpx_create.html) - Destroys a chmpx handle
