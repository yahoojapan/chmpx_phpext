---
layout: contents
language: en-us
title: ChmpxServer::reply
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_replyja.html
lang_opp_word: To Japanese
prev_url: chmpxserver_class_receivekv.html
prev_string: ChmpxServer::receiveKv
top_url: chmpxserver_class.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_replykv.html
next_string: ChmpxServer::replyKv
---

# ChmpxServer::reply
Replies a message

## Description

```
public function reply(string $strbinary):bool {}
```

Replies a message.

## Parameters
* strbinary
  * Specifies a message to be replied

## Return Values
Returns true on success or false on failure. 

## Examples

ChmpxServer:
```
php -r '
> $chmpx = new Chmpx();
> $chmpx->createServer("./tests/server.yaml", true);
> $svrobj = $chmpx->getChmpxServer();
> $rcvdata = "";
> $svrobj->receive($rcvdata, 10 * 1000, true);
> var_dump($svrobj->reply($rcvdata));
'
```

ChmpxSlave:
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
> echo "rcvdata:".$rcvdata;
'
```

The above example will output:

ChmpxServer:
```
bool(true)
```

ChmpxSlave:
```
rcvdata:hello, world!
```


## See Also
- [Chmpx::createServer](chmpx_class_createserver.html) - Creates a ChmpxServer instance
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserver.html) - Gets a ChmpxServer instance
- [ChmpxServer::receive](chmpxserver_class_receive.html) - Gets a message

