<?php

/** @generate-class-entries */

/*
* CHMPX PHP Extension library
*
* Copyright 2015 Yahoo Japan corporation.
*
* CHMPX is inprocess data exchange by MQ with consistent hashing.
* CHMPX is made for the purpose of the construction of
* original messaging system and the offer of the client
* library.
* CHMPX transfers messages between the client and the server/
* slave. CHMPX based servers are dispersed by consistent
* hashing and are automatically layouted. As a result, it
* provides a high performance, a high scalability.
*
* For the full copyright and license information, please view
* the LICENSE file that was distributed with this source code.
*
* AUTHOR:   nakatani@yahoo-corp.jp
* CREATE:   Mon Mar 16 2015
* REVISION:
*/

function chmpxpx_bump_debug_level(): void {}

function chmpxpx_set_debug_level_silent(): void {}

function chmpxpx_set_debug_level_error(): void {}

function chmpxpx_set_debug_level_warning(): void {}

function chmpxpx_set_debug_level_message(): void {}

function chmpxpx_set_debug_file(string $filepath): bool {}

function chmpxpx_unset_debug_file(): bool {}

function chmpxpx_load_debug_env(): bool {}

function chmpxpx_load_hash_library(string $libpath): bool {}

function chmpxpx_unload_hash_library(): bool {}

/**
 * @return resource|false
 */
function chmpxpx_create(string $filepath, bool $is_on_server, bool $is_auto_rejoin = false) {}

/**
 * @return resource|false
 */
function chmpxpx_create_server(string $filepath, bool $is_auto_rejoin = false) {}

/**
 * @return resource|false
 */
function chmpxpx_create_slave(string $filepath, bool $is_auto_rejoin = false) {}

/**
 * @param resource $handle_res
 */
function chmpxpx_destroy($handle_res): bool {}

/**
 * @param resource $handle_res
 */
function chmpxpx_process_running($handle_res): bool {}

/**
 * @param resource $handle_res
 * @return resource|false
 */
function chmpxpx_msgid_open($handle_res, bool $no_giveup_rejoin = false) {}

/**
 * @param resource $handle_res
 * @param resource $handle_msgid
 */
function chmpxpx_msgid_close($handle_res, $handle_msgid): bool {}

/**
 * @param resource $handle_res
 */
function chmpxpx_pkth_close($handle_res): bool {}

/**
 * @param resource $handle_res
 * @param string $strbinary
 * @return resource|false
 */
function chmpxpx_svr_receive($handle_res, &$strbinary, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false) {}

/**
 * @param resource $handle_res
 * @param string $strbinkey
 * @param string $strbinval
 * @return resource|false
 */
function chmpxpx_svr_receive_kv($handle_res, &$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false) {}

/**
 * @param resource $handle_res
 * @param resource $handle_pxpk
 */
function chmpxpx_svr_reply($handle_res, $handle_pxpk, string $strbinary): bool {}

/**
 * @param resource $handle_res
 * @param resource $handle_pxpk
 */
function chmpxpx_svr_reply_kv($handle_res, $handle_pxpk, string $strbinkey, string $strbinval): bool {}

/**
 * @param resource $handle_res
 * @param resource $handle_msgid
 * @param string $strbinary
 */
function chmpxpx_slv_receive($handle_res, $handle_msgid, &$strbinary, int $timeout_ms = RCV_NO_WAIT): bool {}

/**
 * @param resource $handle_res
 * @param resource $handle_msgid
 * @param string $strbinkey
 * @param string $strbinval
 */
function chmpxpx_slv_receive_kv($handle_res, $handle_msgid, &$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT): bool {}

/**
 * @param resource $handle_res
 * @param resource $handle_msgid
 */
function chmpxpx_slv_send($handle_res, $handle_msgid, string $strbinary, bool $is_routing = true, bool $is_broadcast = false): int {}

/**
 * @param resource $handle_res
 * @param resource $handle_msgid
 */
function chmpxpx_slv_send_kv($handle_res, $handle_msgid, string $strbinkey, string $strbinval, bool $is_routing = true, bool $is_broadcast = false): int {}

/**
 * @param resource $output
 */
function chmpxpx_print_version($output = null): bool {}

class ChmpxServer
{
	/** @var resource|null */
	public $chmpx_handle;
	/** @var resource|null */
	public $chmpx_pkt_handle;

	/**
	 * @param resource $handle
	 */
	public function __construct($handle) {}
	public function __destruct() {}
	public function reply(string $strbinary):bool {}
	public function replyKv(string $strbinkey, string $strbinval):bool {}
	/** @param string $strbinary */
	public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false): bool {}
	/**
	 * @param string $strbinkey
	 * @param string $strbinval
	 */
	public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT, bool $no_giveup_rejoin = false): bool {}
}

class ChmpxSlave
{
	/** @var resource|null */
	public $chmpx_handle;
	/** @var resource|null */
	public $msgid_handle;

	/**
	 * @param resource $handle
	 */
	public function __construct($handle, bool $no_giveup_rejoin = false) {}
	public function __destruct() {}
	
	public function send(string $strbinary, bool $is_routing = true, bool $is_broadcast = false): int {}
	public function sendKv(string $strbinkey, string $strbinval, bool $is_routing = true, bool $is_broadcast = false): int {}
	/** @param string $strbinary */
	public function receive(&$strbinary, int $timeout_ms = RCV_NO_WAIT): bool {}
	/**
	 * @param string $strbinkey
	 * @param string $strbinval
	 */
	public function receiveKv(&$strbinkey, &$strbinval, int $timeout_ms = RCV_NO_WAIT): bool {}
}

class Chmpx
{
	/** @var resource|null */
	private $chmpx_handle;
	/** @var resource|null */
	private $is_server_mode;

	public function __construct() {}
	public function __destruct() {}
	public function create(string $filepath, bool $is_on_server, bool $is_auto_rejoin = false): bool {}
	public function createServer(string $filepath, bool $is_auto_rejoin = false): bool {}
	public function createSlave(string $filepath, bool $is_auto_rejoin = false): bool {}
	public function destroy(): bool {}
	public function isRunning(): bool {}
	public function getChmpxSlave(bool $no_giveup_rejoin = false): ChmpxSlave|false {}
	public function getChmpxServer(): ChmpxServer|false {}
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
