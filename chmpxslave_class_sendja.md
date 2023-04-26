---
layout: contents
language: ja
title: ChmpxSlave::send
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_send.html
lang_opp_word: To English
prev_url: chmpxslave_class_receivekvja.html
prev_string: ChmpxSlave::receiveKv
top_url: chmpxslave_classja.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_sendkvja.html
next_string: ChmpxSlave::sendKv
---

# ChmpxSlave::send
メッセージを送信する

## 説明

```
public function send(string $strbinary, bool $is_routing = true, bool $is_broadcast = false): int {}
```

メッセージを送信します。

## パラメータ
* strbinary
  * 送信メッセージ
* is_routing
  * ルーティング
* is_broadcast
  * 同報通知

## 戻り値
送信メッセージ長

## 例

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


## 参考
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [Chmpx::isRunning](chmpx_class_isrunningja.html) - chmpxプロセスを確認する
- [ChmpxSlave::send](chmpxslave_class_sendja.html) - メッセージを送信する
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekvja.html) - キーバリュー形式のメッセージを受信する

