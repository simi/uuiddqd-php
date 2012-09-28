/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Josef Šimánek                                                |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_UUID_H
#define PHP_UUID_H

extern zend_module_entry uuid_module_entry;
#define phpext_uuid_ptr &uuid_module_entry

#ifdef PHP_WIN32
#	define PHP_UUID_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_UUID_API __attribute__ ((visibility("default")))
#else
#	define PHP_UUID_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(uuid);
PHP_MSHUTDOWN_FUNCTION(uuid);
PHP_RINIT_FUNCTION(uuid);
PHP_RSHUTDOWN_FUNCTION(uuid);
PHP_MINFO_FUNCTION(uuid);

PHP_FUNCTION(generate_uuid);


#ifdef ZTS
#define UUID_G(v) TSRMG(uuid_globals_id, zend_uuid_globals *, v)
#else
#define UUID_G(v) (uuid_globals.v)
#endif

#endif	/* PHP_UUID_H */
