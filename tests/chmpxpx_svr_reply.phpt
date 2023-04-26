--TEST--
chmpxpx_svr_reply
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
    if(!file_exists("./tests/server.yaml") || !file_exists("./tests/slave.yaml")){
        die("NG: File does not exist.");
    }
?>
--FILE--
<?php
// fork
if(-1 == ($cpid = pcntl_fork())){
    die("NG: Could not do fork.");
}

$snddata	= "TEST DATA";
$replydata	= "REPLY DATA";

if(0 == $cpid){
    //-----------------------------
    // child process - Server node
    //-----------------------------
    // chmpx
    exec("chmpx -conf ./tests/server.yaml -d info > /tmp/test_chmpx_server.log 2>&1 &");
    exec("sleep 1"); 

    time_nanosleep(0, 500 * 1000 * 1000);
    $procid = exec("ps ax | grep chmpx | grep tests/server.yaml | grep -v grep | awk '{print $1}'");

    // join
    $svrhandle = chmpxpx_create_server("./tests/server.yaml", true);
    if(isset($procid) && false !== $svrhandle){
        // service in
        exec("sleep 1");
        exec("bash -c 'echo SERVICEIN > /dev/tcp/127.0.0.1/8021'");
        time_nanosleep(0, 500 * 1000 * 1000);

        $rcvdata	= "";
        $pkthandle	= chmpxpx_svr_receive($svrhandle, $rcvdata, 3000, true);
        if(false !== $pkthandle){
            if($rcvdata == $snddata){
                // OK receive, next is replying
                if(chmpxpx_svr_reply($svrhandle, $pkthandle, $replydata)){
                    // OK
                }else{
                    echo "NG: Failed replying data.\n";
                }
            }else{
                echo "NG: Received data is wrong.(" . $snddata . " -> " . $rcvdata . ")\n";
            }
            chmpxpx_pkth_close($pkthandle);
        }else{
            echo "NG: Could not receive data.\n";
        }

        // close
        chmpxpx_destroy($svrhandle);
        time_nanosleep(0, 500 * 1000 * 1000);

    }else{
        echo "NG: Could not join server chmpx.\n";
    }

    // kill chmpx
    if($procid == sprintf("%d", intval($procid))){
        $killcmd = "kill -HUP " . $procid . " >> /tmp/test_chmpx_server.log 2>&1";
        exec($killcmd);
        time_nanosleep(0, 500 * 1000 * 1000);
    }
    exit(0); 

}else{
    //-----------------------------
    // parent process - Slave node
    //-----------------------------
    // chmpx
    exec("chmpx -conf ./tests/slave.yaml -d info > /tmp/test_chmpx_slave.log 2>&1 &");
    exec("sleep 1");

    time_nanosleep(0, 500 * 1000 * 1000);
    $slvprocid = exec("ps ax | grep chmpx | grep tests/slave.yaml | grep -v grep | awk '{print $1}'");

    // create handle
    $slvhandle = chmpxpx_create("./tests/slave.yaml", false, true);
    if(isset($slvprocid) && false !== $slvhandle){
        sleep(2);

        // open msgid
        $msgid = chmpxpx_msgid_open($slvhandle, true);
        if(false !== $msgid){

            // send data from slave
            $count = chmpxpx_slv_send($slvhandle, $msgid, $snddata, true, false);
            if(1 <= $count){
                // send success, next wait to receive...
                sleep(2);

                $rcvdata = "";
                if(chmpxpx_slv_receive($slvhandle, $msgid, $rcvdata)){
                    if($rcvdata == $replydata){
                        echo "OK";
                    }else{
                        echo "NG: Received data is wrong(replydata->" . $replydata . ", rcvdata->" . $rcvdata . ").";
                    }
                }else{
                    echo "NG: Could not recive data.";
                }
            }else{
                echo "NG: Could not send data.";
            }
            chmpxpx_msgid_close($slvhandle, $msgid);

        }else{
            echo "NG: Could not open msgid on slave chmpx.";
        }
        chmpxpx_destroy($slvhandle);

    }else{
        echo "NG: Could not join slave chmpx.";
    }

    // kill both chmpx
    if($slvprocid == sprintf("%d", intval($slvprocid))){
        $killcmd = "kill -HUP " . $slvprocid . " >> /tmp/test_chmpx_slave.log 2>&1";
        exec($killcmd);
    }
    $status = 0;
    pcntl_wait($status); 
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
