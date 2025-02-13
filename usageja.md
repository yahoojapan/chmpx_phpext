---
layout: contents
language: ja
title: Usage
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: usage.html
lang_opp_word: To English
prev_url: featureja.html
prev_string: Feature
top_url: indexja.html
top_string: TOP
next_url: developerja.html
next_string: Developer
---

# 使い方
このページではCHMPX PHPドライバのインストールと使い方を説明します。

## 1. インストール
Debianのパッケージ管理システムをベースとするLinux利用者は、次の手順を実行してください。

```
$ sudo apt-get update -y

$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh | sudo bash

$ sudo apt-get install -y php8.4 libapache2-mod-php8.4
$ sudo update-alternatives --set php-config /usr/bin/php-config8.4
$ sudo update-alternatives --set php /usr/bin/php8.4
$ sudo apt-get install -y chmpx php-pecl-chmpx
```

RPMパッケージ管理システムをベースとするLinux利用者は、次の手順を実行してください。
```
$ sudo dnf update -y

$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh | sudo bash

$ sudo dnf install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
$ sudo dnf install https://rpms.remirepo.net/enterprise/remi-release-8.rpm
$ sudo dnf module reset php
$ sudo dnf module install php:remi-8.4
$ sudo dnf install -y php-pecl-chmpx
```

ALPINEベースのLinuxの場合は、以下の手順に従ってください。
```
# apk update

# curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.alpine.sh | sh

# apk add php83 php83-dev php83-tokenizer
$ apk add php83-pecl-chmpx
```

## 2. 動作テスト

最初にCHMPX PHPドライバのGitHubレポジトリをcloneしてください。

```
$ git clone https://github.com/yahoojapan/chmpx_phpext.git
```

CHMPXサーバプロセスを起動します。
```
$ chmpx -conf ./chmpx_phpext/tests/server.yaml &
```

CHMPXスレーブプロセスを起動します。
```
$ chmpx -conf ./chmpx_phpext/tests/slave.yaml &
```

PHPサーバアプリを起動します。
```
$ php -r '
> $chmpx = new Chmpx(); 
> $chmpx->CreateServer("./chmpx_phpext/tests/server.yaml", true); 
> $svrobj = $chmpx->GetChmpxServer(); 
> $rcvdata = ""; 
> $svrobj->Receive($rcvdata, 60 * 1000, true); // wait for one minute.
> echo $rcvdata;
'
```
PHPクライアントアプリを起動して、CHMPXスレーブプロセスを経由して、PHPサーバアプリにメッセージを送ります。
```
$ php -r '
> $chmpx = new Chmpx();
> $chmpx->CreateSlave("./chmpx_phpext/tests/slave.yaml", true); 
> $slaveobj = $chmpx->GetChmpxSlave();
> $slaveobj->Send("hello", true, false);
'
```

上の例を実行した場合の出力結果は、次のようになります。
```
hello
```

