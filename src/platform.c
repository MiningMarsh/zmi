/*
 * platform.c
 *
 * Checks to make sure the compile is on a compatible platform.
 *
 *  Created on: August 2, 2013
 *      Author: Joshua Songy
 */

#include <stdlib.h>
#include "platform.h"

#if !defined(PLATFORM_WINDOWS) && !defined(PLATFORM_LINUX)
#	error "Only windows and linux build targets supported."
#endif
