---
layout: contents
language: en-us
title: ChmpxServer::receiveKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_receivekvja.html
lang_opp_word: To Japanese
prev_url: chmpxserver_class_receive.html
prev_string: ChmpxServer::receive
top_url: chmpxserver_class.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_reply.html
next_string: ChmpxServer::reply
---

# ChmpxServer::receiveKv
Receives a message with a key and a value


## Description

```
public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false): bool {}
```

Receives a message with a key and a value

## Parameters
* strbinkey
  * Specifies received key data variable by reference
* strbinval
  * Specifies received value data variable by reference
* timeout_ms
  * Specifies waiting time
* no_giveup_rejoin
  * Specifies true if reconnect automatically with a chmpx server process

## Return Values
Returns true on success or false on failure. 

## Examples

```
php -r '
$chmpx = new Chmpx(); 
$chmpx->createServer("./tests/server.yaml", true);
$svrobj = $chmpx->getChmpxServer();
$key = "";
$val = ""; 
$svrobj->receiveKv($key, $val, 10 * 1000, true); 
echo "key:".$key." val:".$val; 
'
```

```
php -r '
> $chmpx = new Chmpx();
> $chmpx->createSlave("./tests/slave.yaml", true);
> $slaveobj = $chmpx->GetChmpxSlave();
> $key = "hello";
> $val = "world!";
> $slaveobj->sendKv($key, $val, true, false);
'
```

The above example will output:

```
key:hello val:world!
```


## See Also
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserver.html) - Gets a ChmpxServer instance
- [ChmpxSlave::sendKv](chmpxslave_class_sendkv.html) - Sends a message with a key and a value
