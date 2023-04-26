---
layout: contents
language: ja
title: ChmpxServer::receive
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_receive.html
lang_opp_word: To English
prev_url: chmpxserver_class_destructja.html
prev_string: ChmpxServer::__destruct
top_url: chmpxserver_classja.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_receivekvja.html
next_string: ChmpxServer::receiveKv
---

# ChmpxServer::receive
メッセージを受信する

## 説明

```
public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT,  bool $no_giveup_rejoin = false): bool {}
```

メッセージを受信します。

## パラメータ
* strbinary
  * 受信メッセージ（参照渡し）
* timeout_ms
  * 待ち時間
* no_giveup_rejoin
  * 真ならばchmpxサーバプロセスに自動的に再接続する

## 戻り値
成功時は真。

## 例

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

上の例は、下のように出力されます。
```
bool(true)
rcvdata:hello, world!
```


## 参考
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [ChmpxSlave::send](chmpxslave_class_sendja.html) - メッセージを送信する

