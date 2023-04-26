---
layout: contents
language: en-us
title: ChmpxSlave::send
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_sendja.html
lang_opp_word: To Japanese
prev_url: chmpxslave_class_receivekv.html
prev_string: ChmpxSlave::receiveKv
top_url: chmpxslave_class.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_sendkv.html
next_string: ChmpxSlave::sendKv
---

# ChmpxSlave::send
Sends a message

## Description

```
public function send(string $strbinary, bool $is_routing = true, bool $is_broadcast = false): int {}
```

Sends a message.

## Parameters
* strbinary
  * Specifies data to send
* is_routing
  * Specifies True if sending a message in routing mode
* is_broadcast
  * Specifies True if sending a message in broadcasting mode

## Return Values
Returns the message length

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
