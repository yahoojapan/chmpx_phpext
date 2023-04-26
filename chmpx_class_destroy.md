---
layout: contents
language: en-us
title: Chmpx::destroy
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_class_destroyja.html
lang_opp_word: To Japanese
prev_url: chmpx_class_createslave.html
prev_string: Chmpx::createSlave
top_url: chmpx_class.html
top_string: Chmpx Class
next_url: chmpx_class_isrunning.html
next_string: Chmpx::isRunning
---

# Chmpx::destroy
Destroys a Chmpx instance

## Description

```
public function destroy(): bool
```

Destroys a Chmpx instance.

## Parameters

## Return Values
Returns true on success or false on failure. 

## Examples

```
php -r '$chmpx = new Chmpx(); $chmpx->createServer("./tests/server.yaml", true); var_dump($chmpx->destroy());'
```

The above example will output:

```
bool(true)
```

## See Also
- [Chmpx::create](chmpx_class_create.html) - Creates a ChmpxServer instance
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
