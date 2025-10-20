#
# CHMPX PHP Extension library
#
# Copyright 2022 Yahoo Japan corporation.
#
# CHMPX is inprocess data exchange by MQ with consistent hashing.
# CHMPX is made for the purpose of the construction of
# original messaging system and the offer of the client
# library.
# CHMPX transfers messages between the client and the server/
# slave. CHMPX based servers are dispersed by consistent
# hashing and are automatically layouted. As a result, it
# provides a high performance, a high scalability.
#
# For the full copyright and license information, please view
# the LICENSE file that was distributed with this source code.
#
# AUTHOR:   Hirotaka Wakabayashi
# CREATE:   Tue, Feb 22 2022
# REVISION:
#

#
# Set chmpx php extension name
#
AC_SUBST([PHP_SO_NAME], "chmpxpx")
AC_SUBST([PHP_PECL_BASE_NAME], "pecl-chmpx")

#
# Load customizable variables
#
AC_CHECK_FILE([configure.custom],
	[
		configure_custom_file="configure.custom"
		custom_git_domain="$(grep '^\s*GIT_DOMAIN\s*=' configure.custom | sed -e 's|^\s*GIT_DOMAIN\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_git_org="$(grep '^\s*GIT_ORG\s*=' configure.custom | sed -e 's|^\s*GIT_ORG\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_git_repo="$(grep '^\s*GIT_REPO\s*=' configure.custom | sed -e 's|^\s*GIT_REPO\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_dev_email="$(grep '^\s*DEV_EMAIL\s*=' configure.custom | sed -e 's|^\s*DEV_EMAIL\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_dev_name="$(grep '^\s*DEB_NAME\s*=' configure.custom | sed -e 's|^\s*DEB_NAME\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
	],
	[
		configure_custom_file=""
		custom_git_domain="github.com"
		custom_git_org="yahoojapan"
		custom_git_repo="chmpx_phpext"
		custom_dev_email="ml-antpickax-support@lycorp.co.jp"
		custom_dev_name="K2HASH_DEVELOPER"
	]
)

#
# Common variables
#
AC_SUBST([CONFIGURECUSTOM], "${configure_custom_file}")
AC_SUBST([GIT_DOMAIN], "${custom_git_domain}")
AC_SUBST([GIT_ORG], "${custom_git_org}")
AC_SUBST([GIT_REPO], "${custom_git_repo}")
AC_SUBST([DEV_EMAIL], "$(echo ${DEBEMAIL:-"${custom_dev_email}"})")
AC_SUBST([DEV_NAME], "$(echo ${DEBFULLNAME:-"${custom_dev_name}"})")

AC_SUBST([HOME_PAGE],  "https://php.chmpx.antpick.ax/")
AC_SUBST([PKGLICENSE], [$(grep License LICENSE | sed -e 's/ License//g')])
AC_SUBST([DEBLICENSER],[$(grep Copyright LICENSE | sed -e 's/ *(c)//g')])
AC_SUBST([DEBCOPYING], [$(sed -e 's/^$/./g' -e 's/^/ /g' LICENSE)])

#
# Enable for this extension
#
PHP_ARG_ENABLE([chmpxpx], [whether to enable chmpx support], [AS_HELP_STRING([--enable-chmpxpx], [Enable chmpx support])], [no])

#
# For PHP Extension
#
if test "$PHP_CHMPXPX" != "no"; then
	PHP_EVAL_INCLINE($LIBCHMPX_CFLAGS)
	PHP_EVAL_LIBLINE($LIBCHMPX_LIBS, CHMPXPX_SHARED_LIBADD)

	AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
	AC_MSG_CHECKING(for libchmpxpx)

	if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists libchmpx; then
		CHMPXPX_INCDIR=`$PKG_CONFIG libchmpx --variable=includedir`
		CHMPXPX_LIBDIR=`$PKG_CONFIG libchmpx --variable=libdir`
		CHMPXPX_VERSION=`$PKG_CONFIG libchmpx --modversion`

		AC_MSG_RESULT(from pkgconfig: version $CHMPXPX_VERSION found in $CHMPXPX_LIBDIR)
	fi

	if test -z "$CHMPXPX_LIBDIR"; then
		AC_MSG_RESULT([not found])
		AC_MSG_ERROR([Please install the libchmpx distribution])
	fi

	PHP_ADD_INCLUDE($CHMPXPX_INCDIR/chmpx)
	PHP_ADD_LIBRARY_WITH_PATH(chmpx, $CHMPXPX_LIBDIR, CHMPXPX_SHARED_LIBADD)
	PHP_SUBST(CHMPXPX_SHARED_LIBADD)

	AC_DEFINE(HAVE_CHMPXPX, 1, [ Have chmpxpx support ])

	#
	# Source codes
	#
	PHP_NEW_EXTENSION(chmpxpx, chmpxpx_func.c Chmpx.c ChmpxServer.c ChmpxSlave.c, $ext_shared)
fi

AC_CHECK_PROG(CHMPXPX_HAVE_PHP_BINARY, [php --version], [yes], [no])

#
# Make PHP version variables
#
if test "${CHMPXPX_HAVE_PHP_BINARY}" = "yes"; then
	AC_SUBST([CHMPXPX_PHP_VERSION],       [$(php -r 'echo "".PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')])
	AC_SUBST([CHMPXPX_PHP_RAW_VERSION],   [$(php -r 'echo "".PHP_MAJOR_VERSION."".PHP_MINOR_VERSION;')])
	AC_SUBST([CHMPXPX_PHP_MAJOR_VERSION], [$(php -r 'echo "".PHP_MAJOR_VERSION."";')])
	AC_SUBST([CHMPXPX_PHP_MINOR_VERSION], [$(php -r 'echo "".PHP_MINOR_VERSION."";')])
	AC_SUBST([CHMPXPX_EXT_PKGNAME],       [$(head -n 1 $(pwd)/ChangeLog | awk '{print $1}')])
	AC_SUBST([CHMPXPX_EXT_VERSION],       [$(head -n 1 $(pwd)/ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g')])

	AC_DEFINE_UNQUOTED(PHP_CHMPXPX_VERSION, ["$(head -n 1 $(pwd)/ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g')"], [ PHP Extension version ])
else
	AC_SUBST([CHMPXPX_PHP_VERSION],       "0.0")
	AC_SUBST([CHMPXPX_PHP_RAW_VERSION],   "00")
	AC_SUBST([CHMPXPX_PHP_MAJOR_VERSION], "0")
	AC_SUBST([CHMPXPX_PHP_MINOR_VERSION], "0")
	AC_SUBST([CHMPXPX_EXT_PKGNAME],       "php-pecl-chmpx")
	AC_SUBST([CHMPXPX_EXT_VERSION],       "0.0.0")

	AC_DEFINE(PHP_CHMPXPX_VERSION,     "0.0.0", [ PHP Extension version ])
fi

#
# AC Macros for checking dependencies, etc
#
# [NOTE]
# The macros below are the macros that were output when I ran autoscan manually.
#
AC_CHECK_FUNCS([strncasecmp])
AC_CHECK_HEADERS([fcntl.h])
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_FUNC_MALLOC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

#
# Make changelog strings for rpm
#
if test -f $(pwd)/buildutils/make_rpm_changelog.sh; then
	AC_SUBST([CHMPXPX_RPMCHANGELOG], [$($(pwd)/buildutils/make_rpm_changelog.sh $(pwd)/ChangeLog)])
fi

#
# Set input files
#
if test -d buildutils; then
	AC_CONFIG_FILES([
		$(pwd)/buildutils/php-pecl-chmpx.spec
		$(pwd)/buildutils/chmpxpx.ini
		$(pwd)/buildutils/rules
		$(pwd)/buildutils/control.in
		$(pwd)/buildutils/copyright
		$(pwd)/buildutils/watch
		$(pwd)/buildutils/upstream/metadata
		$(pwd)/buildutils/APKBUILD.templ
	])
fi

#
# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noexpandtab sw=4 ts=4 fdm=marker
# vim<600: noexpandtab sw=4 ts=4
#
