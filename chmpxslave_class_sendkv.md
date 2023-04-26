---
layout: contents
language: en-us
title: ChmpxSlave::sendKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_sendkvja.html
lang_opp_word: To Japanese
prev_url: chmpxslave_class_send.html
prev_string: ChmpxSlave::send
top_url: chmpxslave_class.html
top_string: ChmpxSlave Class
next_url:
next_string:
---

# ChmpxSlave::sendKv
Sends a key and a value message

## Description

```
public function sendKv(string $strbinkey, string $strbinval, bool $is_routing = true, bool $is_broadcast = false): int {}
```

Sends a key and a value message.

## Parameters
* strbinkey
  * Specifies key data
* strbinval
  * Specifies value data
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
isRunning:1
bool(true)
rkey:hello rval:world!
```


## See Also
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
- [Chmpx::isRunning](chmpx_class_isrunning.html) - Checks if a chmpx process exists
- [ChmpxSlave::sendKv](chmpxslave_class_sendkv.html) - Sends a message with a key and a value
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekv.html) - Receives a message witha a key and a value
