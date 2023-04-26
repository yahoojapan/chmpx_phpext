---
layout: contents
language: en-us
title: Chmpx::isRunning
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_isRunningja.html
lang_opp_word: To Japanese
prev_url: chmpx_class_destroy.html
prev_string: Chmpx::destroy
top_url: chmpx_class.html
top_string: Chmpx Class
next_url: chmpx_class_getchmpxserver.html
next_string: Chmpx::getChmpxServer
---

# Chmpx::isRunning
Checks if a chmpx process exists

## Description

```
public function isRunning(): bool
```

Checks if a chmpx process exists.

## Parameters

## Return Values
Returns true if a chmpx process is alive.

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createSlave("./tests/slave.yaml", true); var_dump($chmpx->isRunning());'
```

The above example will output:

```
bool(true)
```


## See Also
- [Chmpx::construct](chmpx_class_construct.html) - Creates a empty Chmpx instance
- [Chmpx::create](chmpx_class_create.html) - Creates a ChmpxServer instance
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
