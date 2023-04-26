---
layout: contents
language: ja
title: ChmpxServer::replyKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_replykv.html
lang_opp_word: To English
prev_url: chmpxserver_class_replyja.html
prev_string: ChmpxServer::reply
top_url: chmpxserver_classja.html
top_string: ChmpxServer Class
next_url:
next_string:
---

# ChmpxServer::replyKv
キーとバリューのメッセージを返信する

## 説明

```
public function replyKv(string $strbinkey, string $strbinval):bool {}
```

キーとバリューのメッセージを返信します。

## パラメータ

* strbinkey
  * キー
* strbinval
  * バリュー

## 戻り値
成功時は真。

## 例

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

上の例は、下のようなに表示されます。

ChmpxServer:
```
bool(true)
```

ChmpxSlave:
```
rkey:hello rval:world!
```


## 参考
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [ChmpxServer::receiveKv](chmpxserver_class_receivekvja.html) - キーとバリューのメッセージを受信する
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [ChmpxSlave::sendKv](chmpxslave_class_sendkvja.html) - Sends キーとバリューのメッセージを送信する
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekvja.html) - キーとバリューのメッセージを受信する
