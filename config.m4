dnl $Id$
dnl config.m4 for extension uuid

PHP_ARG_WITH(uuid, for uuid support,
[  --with-uuid             Include uuid support])

if test "$PHP_UUID" != "no"; then

  dnl --with-uuid -> check with-path
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/uuid/uuid.h"
  if test -r $PHP_UUID/$SEARCH_FOR; then # path given as parameter
    UUID_DIR=$PHP_UUID
  else # search default path list
    AC_MSG_CHECKING([for uuid files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        UUID_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi
  
  if test -z "$UUID_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the uuid distribution])
  fi

  dnl --with-uuid -> add include path
  PHP_ADD_INCLUDE($UUID_DIR/include)

  dnl --with-uuid -> check for lib and symbol presence
  LIBNAME=uuid
  LIBSYMBOL=uuid_generate

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $UUID_DIR/lib, UUID_SHARED_LIBADD)
    AC_DEFINE(HAVE_UUIDLIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong uuid lib version or lib not found])
  ],[
    -L$UUID_DIR/lib -lm
  ])
  
  PHP_SUBST(UUID_SHARED_LIBADD)

  PHP_NEW_EXTENSION(uuid, uuid.c, $ext_shared)
fi
