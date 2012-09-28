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
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_uuid.h"
#include "uuid/uuid.h"

/* True global resources - no need for thread safety here */
static int le_uuid;

/* {{{ uuid_functions[]
 *
 * Every user visible function must have an entry in uuid_functions[].
 */
const zend_function_entry uuid_functions[] = {
	PHP_FE(generate_uuid,	NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ uuid_module_entry
 */
zend_module_entry uuid_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"uuid",
	uuid_functions,
	PHP_MINIT(uuid),
	PHP_MSHUTDOWN(uuid),
	PHP_RINIT(uuid),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(uuid),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(uuid),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_UUID
ZEND_GET_MODULE(uuid)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(uuid)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(uuid)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(uuid)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(uuid)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(uuid)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "uuid support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


PHP_FUNCTION(generate_uuid)
{
  uuid_t my_uuid;
  uuid_generate(my_uuid);

  char stringy[36];
  uuid_unparse(my_uuid, stringy);
  RETURN_STRING(stringy, 1);
}
/* }}} */
