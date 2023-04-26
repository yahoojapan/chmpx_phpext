---
layout: contents
language: ja
title: ChmpxSlave::receiveKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxslave_class_receivekv.html
lang_opp_word: To English
prev_url: chmpxslave_class_receiveja.html
prev_string: ChmpxSlave::receive
top_url: chmpxslave_classja.html
top_string: ChmpxSlave Class
next_url: chmpxslave_class_sendja.html
next_string: ChmpxSlave::send
---

# ChmpxSlave::receiveKv
キーとバリューのメッセージを受信する


## 説明

```
public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT): bool {}
```

キーとバリューのメッセージを受信します。

## パラメータ
* strbinkey
  * キーとして受信するデータ（参照渡し）
* strbinval
  * バリューとして受信するデータ（参照渡し）
* timeout_ms
  * 待ち時間

## 戻り値
成功時は真。

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
> sleep(2);
> $rkey= "";
> $rval = "";
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
