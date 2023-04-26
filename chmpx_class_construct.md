---
layout: contents
language: en-us
title: Chmpx::__construct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: chmpx_class.html
top_string: Chmpx Class
next_url: chmpx_class_destruct.html
next_string: Chmpx::__destruct
---

# Chmpx::__construct
Creates a Chmpx instance

## Description

```
public Chmpx::__construct ()
```

Creates a [Chmpx](chmpx_class.html) instance. 

## Parameters
No parameters required.

## Examples

```
$ php -r 'var_dump(new Chmpx());'
```

The above example will output something similar to:
```
object(Chmpx)#1 (2) {
  ["chmpx_handle":"Chmpx":private]=>
  resource(4) of type (chmpx_handle)
  ["is_server_mode":"Chmpx":private]=>
  resource(5) of type (is_server_mode)
}
```

## See Also
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
- [Chmpx::getChmpxSlave](chmpx_class_getchmpxslave.html) - Retrieves the ChmpxSlave instance
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserver.html) - Retrieves the ChmpxServer instance
