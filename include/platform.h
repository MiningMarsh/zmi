/*
 * platform.h
 *
 * This header attempts to discern target platform and compiler features
 * and provide global definitions to easily provide code to a specific target.
 *
 * This file is meant to be compatible with as many compilers as possible.
 * Because of this, classic comments have been used throughout the file.
 *
 *  Created on: March 31, 2013
 *      Author: Joshua Songy
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_ 1

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

/* 
 * Check for various C standards. This should handle every C compiler, as it is
 * part of the language specification that these should be defined.
 */
#if defined(__STDC__) || defined(__STDC_VERSION__)
#	define PLATFORM_C = 1
#	if defined(__STDC__)
#		undef PLATFORM_C89
#		undef PLATFORM_C
#		define PLATFORM_C89 = 1
#		define PLATFORM_C89 = 1
#		define PLATFORM_C = 89
#	endif
#	if defined(__STDC_VERSION__) && (7- __STDC_VERSION__ -7 == 14)
#		undef PLATFORM_C89
#		undef PLATFORM_C90
#		undef PLATFORM_C
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		define PLATFORM_C = 90
#	endif
#   if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199409L)
#		undef PLATFORM_C89
#		undef PLATFORM_C90
#		undef PLATFORM_C94
#		undef PLATFORM_C
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		define PLATFORM_C94 = 1
#		define PLATFORM_C = 94
#	endif
#   if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199901L)
#		undef PLATFORM_C89
#		undef PLATFORM_C90
#		undef PLATFORM_C94
#		undef PLATFORM_C99
#		undef PLATFORM_C
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		define PLATFORM_C94 = 1
#		define PLATFORM_C99 = 1
#		define PLATFORM_C = 99
#	endif
#   if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L)
#		undef PLATFORM_C89
#		undef PLATFORM_C90
#		undef PLATFORM_C94
#		undef PLATFORM_C99
#		undef PLATFORM_C11
#		undef PLATFORM_C
#		define PLATFORM_C89 = 1
#		define PLATFORM_C90 = 1
#		define PLATFORM_C94 = 1
#		define PLATFORM_C99 = 1
#		define PLATFORM_C11 = 1
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
#		undef PLATFORM_CPP98
#		undef PLATFORM_CPP
#		define PLATFORM_CPP98 = 1
#		define PLATFORM_CPP = 98
#	endif
#	if __cplusplus == 199707L
#		undef PLATFORM_CPP98
#		undef PLATFORM_CPP
#		define PLATFORM_CPP98 = 1
#		define PLATFORM_CPP = 98
#	endif
#	if __cplusplus == 201103L
#		undef PLATFORM_CPP98
#		undef PLATFORM_CPP11
#		undef PLATFORM_CPP
#		define PLATFORM_CPP98 = 1
#		define PLATFORM_CPP11 = 1
#		define PLATFORM_CPP = 11
#	endif
#	if defined(__GXX_EXPERIMENTAL_CXX0X__)
#		undef PLATFORM_CPP98
#		undef PLATFORM_CPP11
#		undef PLATFORM_CPP
#		define PLATFORM_CPP98 = 1
#		define PLATFORM_CPP11 = 1
#		define PLATFORM_CPP = 11
#	endif
#endif

/*
 * Check to see if we are on an embedded platform.
 */
#if defined(__embedded_cplusplus)
#	undef PLATFORM_CPP
#	undef PLATFORM_EMBEDDED
#	define PLATFORM_EMBEDDED = 1
#	define PLATFORM_CPP = 1
#endif

/*
 * Check to see if we are compiling for GNU/Linux.
 */
#if defined(__gnu_linux__)
#	undef PLATFORM_LINUX
#	undef PLATFORM_TARGET
#	undef PLATFORM_GNU
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#	define PLATFORM_GNU = 1
#endif

/*
 * Check to see if we are compiling for Linux.
 */
#if defined(__linux__)
#	undef PLATFORM_LINUX
#	undef PLATFORM_TARGET
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#endif

#if defined(linux)
#	undef PLATFORM_LINUX
#	undef PLATFORM_TARGET
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#endif

#if defined(__linux)
#	undef PLATFORM_LINUX
#	undef PLATFORM_TARGET
#	define PLATFORM_LINUX = 1
#	define PLATFORM_TARGET = linux
#endif

/*
 * Check to see if we are compiling for 16bit windows.
 */
#if defined(_WIN16)
#	undef PLATFORM_WINDOWS
#	undef PLATFORM_TARGET
#	undef PLATFORM_BIT
#	undef PLATFORM_16BIT
#	undef PLATFORM_32BIT
#	undef PLATFORM_64BIT
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_16BIT = 1
#	define PLATFORM_TARGET = windows
#	define PLATFORM_BIT = 16
#endif

/*
 * Check to see if we are compiling for 32bit windows.
 */
#if defined(_WIN32)
#	undef PLATFORM_WINDOWS
#	undef PLATFORM_TARGET
#	undef PLATFORM_BIT
#	undef PLATFORM_16BIT
#	undef PLATFORM_32BIT
#	undef PLATFORM_64BIT
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_32BIT = 1
#	define PLATFORM_TARGET = windows
#	define PLATFORM_BIT = 32
#endif

/*
 * Check to see if we are compiling for 32bit windows.
 */
#if defined(__WIN32__)
#	undef PLATFORM_WINDOWS
#	undef PLATFORM_TARGET
#	undef PLATFORM_BIT
#	undef PLATFORM_16BIT
#	undef PLATFORM_32BIT
#	undef PLATFORM_64BIT
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_32BIT = 1
#	define PLATFORM_TARGET = windows
#	define PLATFORM_BIT = 32
#endif

/*
 * Check to see if we are compiling for 64bit windows.
 */
#if defined(_WIN64)
#	undef PLATFORM_WINDOWS
#	undef PLATFORM_TARGET
#	undef PLATFORM_BIT
#	undef PLATFORM_16BIT
#	undef PLATFORM_32BIT
#	undef PLATFORM_64BIT
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_BIT = 64
#	define PLATFORM_64BIT = 1
#	define PLATFORM_TARGET = windows
#endif

/*
 * Check to see if we are compiling for windows.
 */
#if defined(__WINDOWS__)
#	undef PLATFORM_WINDOWS
#	undef PLATFORM_TARGET
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_TARGET = windows
#endif

/*
 * Check to see if we are compiling for windows.
 */
#if defined(__TOS_WIN__)
#	undef PLATFORM_WINDOWS
#	undef PLATFORM_TARGET
#	define PLATFORM_WINDOWS = 1
#	define PLATFORM_TARGET = windows
#endif

#endif /* PLATFORM_H_ */
