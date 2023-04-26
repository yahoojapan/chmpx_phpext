---
layout: contents
language: en-us
title: ChmpxServer::receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_receiveja.html
lang_opp_word: To Japanese
prev_url: chmpxserver_class_destruct.html
prev_string: ChmpxServer::__destruct
top_url: chmpxserver_class.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_receivekv.html
next_string: ChmpxServer::receiveKv
---

# ChmpxServer::receive
Receives a message

## Description

```
public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT,  bool $no_giveup_rejoin = false): bool {}
```

Receives a message.

## Parameters

* strbinary
  * Specifies received data variable by reference
* timeout_ms
  * Specifies waiting time
* no_giveup_rejoin
  * Specifies true if reconnect automatically with a chmpx server process

## Return Values

Returns true on success or false on failure. 

## Examples

```
php -r '
> $chmpx = new Chmpx();
> $handle = chmpxpx_create_server("./tests/server.yaml", true);
> $svrobj = new ChmpxServer($handle);
> $rcvdata = "";
> var_dump($svrobj->receive($rcvdata, 10 * 1000, true));
> echo "rcvdata:".$rcvdata;
> $svrobj->reply($rcvdata);
'
```

```
php -r '
> $chmpx = new Chmpx();
> $chmpx->createSlave("./tests/slave.yaml", true);
> $slaveobj = $chmpx->getChmpxSlave();
> $snddata = "hello, world!";
> $slaveobj->send($snddata, true, false);
> sleep(2);
> $rcvdata= "";
> $slaveobj->receive($rcvdata);
'
```

The above example will output:
```
bool(true)
rcvdata:hello, world!
```


## See Also
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxServer instance
- [ChmpxServer::send](chmpxslave_class_send.html) - Sends a message
