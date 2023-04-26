---
layout: contents
language: ja
title: ChmpxServer::reply
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_reply.html
lang_opp_word: To English
prev_url: chmpxserver_class_receivekvja.html
prev_string: ChmpxServer::receiveKv
top_url: chmpxserver_classja.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_replykvja.html
next_string: ChmpxServer::replyKv
---

# ChmpxServer::reply
メッセージを返信する

## 説明

```
public function reply($strbinary): bool {}
```

メッセージを返信します。

## パラメータ
* strbinary
  * 返信メッセージデータ

## 戻り値
成功時は真。

## 例

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

上の例は、下のように表示されます。

ChmpxServer:
```
bool(true)
```

ChmpxSlave:
```
rcvdata:hello, world!
```


## 参考
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserverja.html) - ChmpxServerインスタンスを取得する
- [ChmpxServer::receive](chmpxserver_class_receiveja.html) - メッセージを受信する

