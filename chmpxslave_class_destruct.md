---
layout: contents
language: en-us
title: K2hQueue::__construct
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_constructja.html
lang_opp_word: To Japanese
prev_url: 
prev_string: 
top_url: chmpxslave_class.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_receive.html
next_string: ChmpxSlave::receive
---

# ChmpxSlave::__destruct
Destroys a ChmpxSlave instance

## Description

```
public function __destruct()
```

Destroys a ChmpxSlave instance

## Parameters

## Examples

```
php -r '
> $handle = chmpxpx_create("./tests/slave.yaml", false, true);
> $slvobj = new ChmpxSlave($handle);
> unset($slvobj);
> chmpxpx_destroy($handle);
'
```

## See Also
- [ChmpxSlave::construct](chmpxslave_class_construct.html) - Creates a empty ChmpxSlave instance
