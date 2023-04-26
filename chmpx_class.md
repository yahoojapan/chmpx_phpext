---
layout: contents
language: en-us
title: Chmpx Class
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpx_classja.html
lang_opp_word: To Japanese
prev_url: constants.html
prev_string: Constants
top_url: developer.html
top_string: Developer
next_url: chmpxserver_class.html
next_string: ChmpxServer Class
---

# Chmpx Class
Chmpx class provides methods to operation for [CHMPX](https://chmpx.antpick.ax/).  

## Class overview

```
Chmpx {
    public function __construct()
    public function __destruct()
    public function create(string $filepath, bool $is_on_server, bool $is_auto_rejoin = false): bool
    public function createServer(string $filepath, bool $is_auto_rejoin = false): bool
    public function createSlave(string $filepath, bool $is_auto_rejoin = false): bool
    public function destroy(): bool
    public function isRunning(): bool
    public function getChmpxSlave(bool $no_giveup_rejoin = false): ChmpxSlave|false {}
    public function getChmpxServer(): ChmpxServer|false {}
}
```

## Method list
- [Chmpx::__construct](chmpx_class_construct.html) - Creates a empty Chmpx instance
- [Chmpx::__destruct](chmpx_class_destruct.html) - Destroys a Chmpx instance
- [Chmpx::create](chmpx_class_create.html) - Creates a ChmpxServer instance
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
- [Chmpx::destroy](chmpx_class_destroy.html) - Destroys a Chmpx instance
- [Chmpx::isRunning](chmpx_class_isrunning.html) - Checks if a chmpx process exists
- [Chmpx::getChmpxSlave](chmpx_class_getchmpxslave.html) - Retrieves the ChmpxSlave instance
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserver.html) - Retrieves the ChmpxServer instance
