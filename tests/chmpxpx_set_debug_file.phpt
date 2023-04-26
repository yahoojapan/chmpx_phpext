--TEST--
chmpxpx_set_debug_file
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
--FILE--
<?php
if(chmpxpx_set_debug_file('/dev/null')){
	echo "OK";
}else{
	echo "NG";
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
