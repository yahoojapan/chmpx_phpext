---
layout: contents
language: en-us
title: ChmpxServer::replyKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_replykvja.html
lang_opp_word: To Japanese
prev_url: chmpxserver_class_reply.html
prev_string: ChmpxServer::reply
top_url: chmpxserver_class.html
top_string: ChmpxServer Class
next_url:
next_string:
---

# ChmpxServer::replyKv
Replies a key and a value message

## Description

```
public function replyKv(string $strbinkey, string $strbinval):bool {}
```

Replies a key and a value message.

## Parameters

* strbinkey
  * Specifies key data
* strbinval
  * Specifies value data

## Return Values
Returns true on success or false on failure. 

## Examples

ChmpxServer:
```
php -r '
> $chmpx = new Chmpx();
> $chmpx->CreateServer("./tests/server.yaml", true);
> $svrobj = $chmpx->GetChmpxServer();
> $key = "";
> $val = "";
> $svrobj->receiveKv($key, $val, 10 * 1000, true);
> var_dump($svrobj->replyKv($key, $val));'
'
```

ChmpxSlave:
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
> $slaveobj->receiveKv($rkey, $rval);
> echo "rkey:".$rkey." rval:".$rval;'
'
```

The above example will output:

ChmpxServer:
```
bool(true)
```

ChmpxSlave:
```
rkey:hello rval:world!
```


## See Also
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [ChmpxServer::receiveKv](chmpxserver_class_receivekv.html) - Receives a message with a key and a value
- [Chmpx::createSlave](chmpx_class_createslave.html) - Creates a ChmpxSlave instance
- [ChmpxSlave::sendKv](chmpxslave_class_sendkv.html) - Sends a message with a key and a value
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekv.html) - Receives a message witha a key and a value
