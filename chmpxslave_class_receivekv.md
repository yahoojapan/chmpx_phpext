---
layout: contents
language: en-us
title: ChmpxSlave::receiveKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_receivekvja.html
lang_opp_word: To Japanese
prev_url: chmpxslave_class_receive.html
prev_string: ChmpxSlave::receive
top_url: chmpxslave_class.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_send.html
next_string: ChmpxSlave::send
---

# ChmpxSlave::receiveKv
Receives a message with a key and a value


## Description

```
public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT): bool {}
```

Receives a message with a key and a value.

## Parameters
* strbinkey
  * Specifies received key data variable by reference
* strbinval
  * Specifies received value data variable by reference
* timeout_ms
  * Specifies waiting time

## Return Values
Returns true on success or false on failure. 

## Examples

```
php -r '
> $chmpx = new Chmpx();
> $chmpx->CreateServer("./tests/server.yaml", true);
> $svrobj = $chmpx->GetChmpxServer();
> $key = "";
> $val = "";
> $svrobj->receiveKv($key, $val, 10 * 1000, true);
> $svrobj->replyKv($key, $val);'
'
```

```
php -r '
> $chmpx = new Chmpx();
> $chmpx->createSlave("./tests/slave.yaml", true);
> echo "isRunning:".$chmpx->isRunning();
> $slaveobj = $chmpx->GetChmpxSlave();
> $key = "hello";
> $val = "world!";
> $slaveobj->sendKv($key, $val, true, false);
> $rkey= "";
> $rval = "";
> sleep(2);
> var_dump($slaveobj->receiveKv($rkey, $rval));
> echo "rkey:".$rkey." rval:".$rval;'
'
```

The above example will output:

```
isRunning:1bool(true)
rkey:hello rval:world!
```


## See Also
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
- [Chmpx::isRunning](chmpx_class_isrunning.html) - Checks if a chmpx process exists
- [ChmpxSlave::sendKv](chmpxslave_class_sendkv.html) - Sends a message with a key and a value
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekv.html) - Receives a message witha a key and a value
