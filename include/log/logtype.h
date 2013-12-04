/*
 * log/Type.h
 *
 * Defines an enumeration determining what kind of message is logged.
 *
 */

#ifndef LOG_LOGTYPE_H_
#define LOG_LOGTYPE_H_ 1

enum logtype {
	MWarning = 1,
	MNull = 0,
	MError = 2,
	MFatal = 3,
	MOk = 4
};

#endif /* LOG_LOGTYPE_H_ */
