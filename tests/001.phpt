--TEST--
Check if chmpx is loaded
--CREDITS--
CHMPX PHP Extension library

Copyright 2023 Yahoo Japan Corporation.

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

AUTHOR:   hiwakaba@yahoo-corp.jp
CREATE:   Fri Mar 31 2023
REVISION:
--EXTENSIONS--
chmpxpx
--FILE--
<?php
echo 'The extension "chmpxpx" is available';
?>
--EXPECT--
The extension "chmpxpx" is available
--DESCRIPTION---
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
