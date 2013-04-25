/*
 * platform.h
 *
 * This header attempts to discern target platform and compiler features and
 * such, and provide global definitions to easily discern these features.
 *
 *  Created on: March 31, 2013
 *      Author: joshua
 */

#ifndef GLOBAL_PLATFORM_HPP_
#define GLOBAL_PLATFORM_HPP_

#undef PLATFORM_C89
#undef PLATFORM_C90
#undef PLATFORM_C94
#undef PLATFORM_C11
#undef PLATFORM_C
#undef PLATFORM_CPP
#undef PLATFORM_CPP11
#undef PLATFORM_CPP89
#undef PLATFORM_EMBEDDED
#undef PLATFORM_TARGET
#undef PLATFORM_LINUX
#undef PLATFORM_WINDOWS
#undef PLATFORM_BIT
#undef PLATFORM_16BIT
#undef PLATFORM_32BIT
#undef PLATFORM_64BIT
#undef PLATFORM_GNU

/* Check for various C standards. This should handle every C compiler, as it is
 * part of the language specification that these should be defined.
 */
#if defined(__STDC__) || defined(__STDC_VERSION__)
#	define PLATFORM_C = 1
#	if defined(__STDC__)
#		define PLATFORM_C89 = 1
#		undef PLATFORM_C
#		define PLATFORM_C = 89
#	endif
#	if defined(__STDC_VERSION__) && (7- __STDC_VERSION__ -7 == 14)
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		undef PLATFORM_C
#		define PLATFORM_C = 90
#	endif
#   if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199409L)
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		define PLATFORM_C94 = 1
#		undef PLATFORM_C
#		define PLATFORM_C = 94
#	endif
#   if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199901L)
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		define PLATFORM_C94 = 1
#		define PLATFORM_C99 = 1
#		undef PLATFORM_C
#		define PLATFORM_C = 99
#	endif
#   if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L)
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		define PLATFORM_C94 = 1
#		define PLATFORM_C11 = 1
#		undef PLATFORM_C
#		define PLATFORM_C = 11
#	endif
#endif

#if defined(__cplusplus)
#	undef PLATFORM_C89
#	undef PLATFORM_C90
#	undef PLATFORM_C94
#	undef PLATFORM_C11
#	undef PLATFORM_C
#	define PLATFORM_CPP = 1
#	if __cplusplus == 199711L
#		define PLATFORM_CPP98 = 1
#		define PLATFORM_CPP = 98
#	endif
#	if __cplusplus == 199707L
#		undef PLATFORM_CPP98
#		define PLATFORM_CPP98 = 1
#		undef PLATFORM_CPP
#		define PLATFORM_CPP = 98
#	endif
#	if __cplusplus == 201103L
#		undef PLATFORM_CPP98
#		define PLATFORM_CPP98 = 1
#		undef PLATFORM_CPP11
#		define PLATFORM_CPP11 = 1
#		undef PLATFORM_CPP
#		define PLATFORM_CPP = 11
#	endif
#	if defined(__GXX_EXPERIMENTAL_CXX0X__)
#		undef PLATFORM_CPP98
#		define PLATFORM_CPP98 = 1
#		undef PLATFORM_CPP11
#		define PLATFORM_CPP11 = 1
#		undef PLATFORM_CPP
#		define PLATFORM_CPP = 11
#	endif
#endif

#if defined(__embedded_cplusplus)
#	define PLATFORM_EMBEDDED = 1
#	undef PLATFORM_CPP
#	define PLATFORM_CPP = 1
#endif

#if defined(__gnu_linux__)
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#	define PLATFORM_GNU = 1
#endif

#if defined(__linux__)
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#endif

#if defined(linux)
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#endif

#if defined(__linux)
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#endif

#if defined(_WIN16)
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_16BIT = 1
#	define PLATFORM_TARGET = windows
#	define PLATFORM_BIT = 16
#endif

#if defined(_WIN32)
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_32BIT = 1
#	define PLATFORM_TARGET = windows
#	define PLATFORM_BIT = 32
#endif

#if defined(__WIN32__)
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_32BIT = 1
#	define PLATFORM_TARGET = windows
#	define PLATFORM_BIT = 32
#endif

#if defined(_WIN64)
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_BIT = 64
#	undef PLATFORM_32BIT
#	define PLATFORM_64BIT = 1
#	define PLATFORM_TARGET = windows
#endif

#if defined(__WINDOWS__)
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_TARGET = windows
#endif

#if defined(__TOS_WIN__)
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_TARGET = windows
#endif

#endif /* GLOBAL_PLATFORM_HPP_ */
