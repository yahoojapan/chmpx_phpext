chmpx php extension
====================
[![PHP AntPickax CI](https://github.com/yahoojapan/chmpx_phpext/workflows/PHP%20AntPickax%20CI/badge.svg)](https://github.com/yahoojapan/chmpx_phpext/actions)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/yahoojapan/chmpx_phpext/master/LICENSE)
[![GitHub forks](https://img.shields.io/github/forks/yahoojapan/chmpx_phpext.svg)](https://github.com/yahoojapan/chmpx_phpext/network)
[![GitHub stars](https://img.shields.io/github/stars/yahoojapan/chmpx_phpext.svg)](https://github.com/yahoojapan/chmpx_phpext/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/yahoojapan/chmpx_phpext.svg)](https://github.com/yahoojapan/chmpx_phpext/issues)
[![debian packages](https://img.shields.io/badge/deb-packagecloud.io-844fec.svg)](https://packagecloud.io/antpickax/stable)
[![RPM packages](https://img.shields.io/badge/rpm-packagecloud.io-844fec.svg)](https://packagecloud.io/antpickax/stable)

### Overview
CHMPX (Consistent Hashing Mq inProcess data eXchange) is communication middleware over the network for sending binary data.
This PHP Extension library is for using CHMPX from PHP.  

By [CHMPX PHP Extension](https://php.chmpx.antpick.ax/) library, you can easily incorporate the functions and features of CHMPX into PHP based programs.  
For the features and functions of CHMPX, see the [chmpx documentation](https://chmpx.antpick.ax/).  

![CHMPX PHP Extension](https://php.chmpx.antpick.ax/images/top_chmpx_phpext.png)

### Usage
CHMPX PHP Extension library is provided as RPM and Debian package.  
Before installing this package, you need the CHMPX package(RPM or Debian).  
First of all, please install the chmpx developer package as described [here](https://chmpx.antpick.ax/usage.html).  
Next, install the CHMPX PHP Extension library using the package manager command.  

- Debian based Linux users can install it by following the steps below:  
```
$ sudo apt-get update -y

$ sudo apt-get install curl -y
$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.deb.sh | sudo bash

$ sudo apt-get install -y php8.3 libapache2-mod-php8.3
$ sudo update-alternatives --set php-config /usr/bin/php-config8.3
$ sudo update-alternatives --set php /usr/bin/php8.3
$ sudo apt-get install -y chmpx php-pecl-chmpx
```
- Fedora derived RPM based Linux(Fedora, CentOS, CentOS Stream, RHEL, etc.) users can install it by following the steps below:
```
$ sudo dnf update -y

$ curl -s https://packagecloud.io/install/repositories/antpickax/stable/script.rpm.sh | sudo bash

$ sudo dnf install https://dl.fedoraproject.org/pub/epel/epel-release-latest-9.noarch.rpm
$ sudo dnf install https://rpms.remirepo.net/enterprise/remi-release-9.rpm
$ sudo dnf module reset php
$ sudo dnf module install php:remi-8.3
$ sudo dnf install -y php-pecl-chmpx
```

### Documents
- [Document top page](https://php.chmpx.antpick.ax/)
- [Github wiki page](https://github.com/yahoojapan/chmpx_phpext/wiki)
- [About CHMPX](https://chmpx.antpick.ax/)
- [About AntPickax](https://antpick.ax/)

### Packages
- [RPM packages(packagecloud.io)](https://packagecloud.io/antpickax/stable)
- [Debian packages(packagecloud.io)](https://packagecloud.io/antpickax/stable)

### License
This software is released under the MIT License, see the license file.

### AntPickax
CHMPX PHP Extension is one of [AntPickax](https://antpick.ax/) products.

Copyright(C) 2022 Yahoo Japan corporation.
