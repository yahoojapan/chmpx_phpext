---
layout: contents
language: ja
title: ChmpxServer::receiveKv
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: chmpxserver_class_receivekv.html
lang_opp_word: To English
prev_url: chmpxserver_class_receiveja.html
prev_string: ChmpxServer::receive
top_url: chmpxserver_classja.html
top_string: ChmpxServer Class
next_url: chmpxserver_class_replyja.html
next_string: ChmpxServer::reply
---

# ChmpxServer::receiveKv
キーとバリューのメッセージを受信する


## 説明

```
public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false): bool {}
```

キーとバリューのメッセージを受信します。

## パラメータ

* strbinkey
  * キーとして受信するデータ（参照渡し）
* strbinval
  * バリューとして受信するデータ（参照渡し）
* timeout_ms
  * 待ち時間を指定する
* no_giveup_rejoin
  * chmpxサーバプロセスに自動的に再接続する場合は、真を指定する

## 戻り値
成功時は真。

## 例

```
php -r '
$chmpx = new Chmpx(); 
$chmpx->createServer("./tests/server.yaml", true);
$svrobj = $chmpx->getChmpxServer();
$key = "";
$val = ""; 
$svrobj->receiveKv($key, $val, 10 * 1000, true); 
echo "key:".$key." val:".$val; 
'
```

```
php -r '
> $chmpx = new Chmpx();
> $chmpx->createSlave("./tests/slave.yaml", true);
> $slaveobj = $chmpx->GetChmpxSlave();
> $key = "hello";
> $val = "world!";
> $slaveobj->sendKv($key, $val, true, false);
'
```

上の例は、下のように出力されます。

```
key:hello val:world!
```


## 参考
- [Chmpx::createServer](chmpx_class_createserverja.html) - ChmpxServerインスタンスを作成する
- [Chmpx::getChmpxServer](chmpx_class_getchmpxserverja.html) - ChmpxSeverインスタンスを取得する
- [ChmpxSlave::sendKv](chmpxslave_class_sendkvja.html) - キーとバリューを送信する
