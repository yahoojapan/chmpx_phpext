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

#include "chmpx.h"
#include "config.h"

#ifndef PHP_CHMPXPX_H
#define PHP_CHMPXPX_H

// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress unknownMacro
ZEND_BEGIN_MODULE_GLOBALS(chmpxpx)
	char* chmpxpx_debug;
// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress unknownMacro
ZEND_END_MODULE_GLOBALS(chmpxpx)

// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress unknownMacro
ZEND_EXTERN_MODULE_GLOBALS(chmpxpx)

#define CHMPXPX_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(chmpxpx, v)

extern zend_module_entry chmpxpx_module_entry;
extern zend_class_entry* chmpx_slave_class_entry;
extern zend_class_entry* chmpx_server_class_entry;

extern int chmpx_handle_resource_number;
extern int msgid_handle_resource_number;
extern int chmpx_pkt_handle_resource_number;
extern int is_server_mode_resource_number;

//uncomment this on local build
//#define PHP_CHMPXPX_VERSION "x.y.z"

# if defined(ZTS) && defined(COMPILE_DL_CHMPXPX)
// cppcheck-suppress unmatchedSuppression
// cppcheck-suppress unknownMacro
ZEND_TSRMLS_CACHE_EXTERN()
# endif

zval* chmpxpx_read_property_resource(zend_class_entry* scope, zval* object, const char* name);
void chmpxpx_update_property_resource(zend_class_entry* scope, zval* object, const char* name, size_t name_length, zval* value);

#endif	/* PHP_CHMPXPX_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noexpandtab sw=4 ts=4 fdm=marker
 * vim<600: noexpandtab sw=4 ts=4
 */
