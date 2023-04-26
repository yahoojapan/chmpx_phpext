---
layout: contents
language: ja
title: ChmpxSlave::receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_receive.html
lang_opp_word: To English
prev_url: chmpxslave_class_destructja.html
prev_string: ChmpxSlave::__destruct
top_url: chmpxslave_classja.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_receivekvja.html
next_string: ChmpxSlave::receiveKv
---

# ChmpxSlave::receive
メッセージを受信する

## 説明

```
public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT): bool {}
```

メッセージを受信します。

## パラメータ
* strbinary
  * 受信メッセージ（参照渡し）
* timeout_ms
  * 待ち時間

## 戻り値
成功時は真。

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

上の例は、下のように出力されます。

```
isRunning:1bool(true)
rcvdata:hello, world!
```


## 参考
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [Chmpx::isRunning](chmpx_class_isrunningja.html) - chmpxプロセスを確認する
- [ChmpxSlave::send](chmpxslave_class_sendja.html) - メッセージを送信する
- [ChmpxSlave::receive](chmpxslave_class_receiveja.html) - メッセージを受信する
