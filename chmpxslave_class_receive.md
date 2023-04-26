---
layout: contents
language: en-us
title: ChmpxSlave::receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_receiveja.html
lang_opp_word: To Japanese
prev_url: chmpxslave_class_destruct.html
prev_string: ChmpxSlave::__destruct
top_url: chmpxslave_class.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_receivekv.html
next_string: ChmpxSlave::receiveKv
---

# ChmpxSlave::receive
Receives a message

## Description

```
public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT): bool {}
```

Receives a message.

## Parameters
* strbinary
  * Specifies received data variable by reference
* timeout_ms
  * Specifies waiting time

## Return Values
Returns true on success or false on failure. 

## Examples

```
php -r '
> $chmpx = new Chmpx();
> $chmpx->createServer("./tests/server.yaml", true);
> $svrobj = $chmpx->getChmpxServer();
> $rcvdata = "";
> $svrobj->receive($rcvdata, 10 * 1000, true);
> $svrobj->reply($rcvdata);'
'
```

```
php -r '
> $chmpx = new Chmpx();
> $chmpx->createSlave("./tests/slave.yaml", true);
> echo "isRunning:".$chmpx->isRunning();
> $slaveobj = $chmpx->getChmpxSlave();
> $snddata = "hello, world!";
> $slaveobj->send($snddata, true, false);
> sleep(2);
> $rcvdata= "";
> $slaveobj->receive($rcvdata);
> echo "rcvdata:".$rcvdata;'
'
```

The above example will output:

```
isRunning:1
bool(true)
rcvdata:hello, world!
```


## See Also
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
- [Chmpx::isRunning](chmpx_class_isrunning.html) - Checks if a chmpx process exists
- [ChmpxSlave::send](chmpxslave_class_send.html) - Sends a message
- [ChmpxSlave::receive](chmpxslave_class_receive.html) - Receives a message
