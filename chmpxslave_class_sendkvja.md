---
layout: contents
language: ja
title: ChmpxSlave::sendKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_sendkv.html
lang_opp_word: To English
prev_url: chmpxslave_class_sendja.html
prev_string: ChmpxSlave::send
top_url: chmpxslave_classja.html
top_string: ChmpxSlave Class
next_url:
next_string:
---

# ChmpxSlave::sendKv
キーバリュー形式のメッセージを送信する

## 説明

```
public function sendKv(string $strbinkey, string $strbinval, bool $is_routing = true, bool $is_broadcast = false): int {}
```

キーバリュー形式のメッセージを送信します。

## パラメータ
* strbinkey
  * キーとして送信するデータ
* strbinval
  * バリューとして送信するデータ
* is_routing
  * メッセージをルーティング可能な状態で送信するなら真。
* is_broadcast
  * メッセージを全てのサーバに送信するなら真

## 戻り値
送信メッセージ長


## 例

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


## 参考
- [Chmpx::createSlave](chmpx_class_createslaveja.html) - ChmpxSlaveインスタンスを作成する
- [Chmpx::isRunning](chmpx_class_isrunningja.html) - chmpxプロセスを確認する
- [ChmpxSlave::sendKv](chmpxslave_class_sendkvja.html) - キーバリュー形式のメッセージを送信する
- [ChmpxSlave::receiveKv](chmpxslave_class_receivekvja.html) - キーバリュー形式のメッセージを受信する
