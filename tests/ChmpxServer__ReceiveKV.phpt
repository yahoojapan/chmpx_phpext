--TEST--
ChmpxServer__ReceiveKV
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

    if(!file_exists("./tests/server.yaml") || !file_exists("./tests/slave.yaml")){
        die("NG: File does not exist.");
    }

// fork
if(-1 == ($cpid = pcntl_fork())){
    die("NG: Could not do fork.");
}

$sndkey = "TEST KEY";
$sndval = "TEST VAL";

if(0 == $cpid){
    //-----------------------------
    // child process - Server node
    //-----------------------------
    // chmpx
    exec("chmpx -conf ./tests/server.yaml -d info > /tmp/test_chmpx_server.log 2>&1 &");
    exec("sleep 1");

    time_nanosleep(0, 500 * 1000 * 1000);
    $procid = exec("ps ax | grep chmpx | grep tests/server.yaml | grep -v grep | awk '{print $1}'");

    // chmpx class
    $chmpx = new Chmpx();
    if(isset($procid) && $chmpx->CreateServer("./tests/server.yaml", true)){
        // service in
        exec("sleep 1");
        exec("bash -c 'echo SERVICEIN > /dev/tcp/127.0.0.1/8021'");
        time_nanosleep(0, 500 * 1000 * 1000);

        // join
        $svrobj = $chmpx->GetChmpxServer();
        if(false !== $svrobj && is_object($svrobj)){
            // receive
            $rcvkey = "";
            $rcvval = "";
            if($svrobj->ReceiveKV($rcvkey, $rcvval, 3000, true)){
                if($rcvkey == $sndkey && $rcvval == $sndval){
                    echo "OK";
                }else{
                    echo "NG: Received data is wrong.(" . $sndval . " -> " . $rcvval . ")\n";
                }
            }else{
                echo "NG: Could not receive data.\n";
            }
        }else{
            echo "NG: Failed to join chmpx server.\n";
        }
        unset($svrobj);

        // destroy chmpx class
        if(!$chmpx->Destroy()){
            echo "NG: Could not destory chmpx object.\n";
        }
    }else{
        echo "NG: Could not make chmpx class.\n";
    }
    unset($chmpx);

    // kill chmpx
    if($procid == sprintf("%d", intval($procid))){
        $killcmd = "kill -HUP " . $procid . " >> /tmp/test_chmpx_server.log 2>&1";
        exec($killcmd);
        time_nanosleep(0, 500 * 1000 * 1000);
    }
}else{
    //-----------------------------
    // parent process - Slave node
    //-----------------------------
    // chmpx
    exec("chmpx -conf ./tests/slave.yaml -d info > /tmp/test_chmpx_slave.log 2>&1 &");
    exec("sleep 1");

    time_nanosleep(0, 500 * 1000 * 1000);
    $slvprocid = exec("ps ax | grep chmpx | grep tests/slave.yaml | grep -v grep | awk '{print $1}'");

    // chmpx class
    $chmpx = new Chmpx();
    if(isset($slvprocid) && $chmpx->CreateSlave("./tests/slave.yaml", true)){
        // join
        $slaveobj = $chmpx->GetChmpxSlave();
        if(false !== $slaveobj && is_object($slaveobj)){
            // send data from slave
            sleep(2);

            $count = $slaveobj->SendKV($sndkey, $sndval, true, false);
            if(1 <= $count){
                // send success...
                // OK
            }else{
                echo "NG: Could not send data.";
            }
            unset($slaveobj);
        }else{
            echo "NG: Failed to join slave chmpx.";
        }

        // destroy chmpx class
        if(!$chmpx->Destroy()){
            echo "NG: Could not destory chmpx object.\n";
        }
    }else{
        echo "NG: Could not make chmpx class.";
    }
    unset($chmpx);

    // kill chmpx
    if($slvprocid == sprintf("%d", intval($slvprocid))){
        $killcmd = "kill -HUP " . $slvprocid . " >> /tmp/test_chmpx_slave.log 2>&1";
        exec($killcmd);
    }
    $status = 0;
    pcntl_wait($status); 
}
exit(0);
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
