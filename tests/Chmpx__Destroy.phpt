--TEST--
Chmpx__Destroy
--CREDITS--
CHMPX PHP Extension library

Copyright 2015 Yahoo Japan Corporation.

CHMPX is inprocess data exchange by MQ with consistent hashing.
CHMPX is made for the purpose of the construction of
original messaging system and the offer of the client
library.
CHMPX transfers messages between the client and the server/
slave. CHMPX based servers are dispersed by consistent
hashing and are automatically layouted. As a result, it
provides a high performance, a high scalability.

For the full copyright and license information, please view
the LICENSE file that was distributed with this source code.

AUTHOR:   nakatani@yahoo-corp.jp
CREATE:   Mon Mar 16 2015
REVISION:
--EXTENSIONS--
chmpxpx
pcntl
--SKIPIF--
<?php
    if(false === function_exists("pcntl_fork")){
        die("skip testing, because pcntl_fork function does not exist.");
    }
?>
--FILE--
<?php
    if(!file_exists("./tests/server.yaml")){
        die("NG: File does not exist.");
    }

// chmpx
exec("chmpx -conf ./tests/server.yaml -d info > /tmp/test_chmpx_server.log 2>&1 &");
exec("sleep 1");

time_nanosleep(0, 500 * 1000 * 1000);
$procid = exec("ps ax | grep chmpx | grep tests/server.yaml | grep -v grep | awk '{print $1}'");

// chmpx class
$chmpx = new Chmpx();
if($chmpx->CreateServer("./tests/server.yaml", true)){
    // destroy chmpx class
    if($chmpx->Destroy()){
        echo "OK";
    }else{
        echo "NG: Could not destory chmpx object.\n";
    }
}else{
    echo "NG: Could not create chmpx class.";
}
unset($chmpx);

// kill chmpx
if($procid == sprintf("%d", intval($procid))){
    $killcmd = "kill -HUP " . $procid . " >> /tmp/test_chmpx_server.log 2>&1";
    exec($killcmd);
}
?>
--EXPECT--
OK
--CLEAN--
<?php
$output = array();
$result_code = 0;
$slvprocid = exec("ps ax | grep chmpx | grep tests/slave.yaml | grep -v grep | awk '{print $1}'");
$procid = exec("ps ax | grep chmpx | grep tests/server.yaml | grep -v grep | awk '{print $1}'");
if (!empty($procid) && !empty($slvprocid)) {
    exec("pkill -KILL chmpx", $output, $result_code);
    if ($result_code !== 0) {
        $msg = var_export($output, true);
        die("failed to stop chmpx: $msg $pdocid $slvprocid");
    }
}
?>
--DESCRIPTION---
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
