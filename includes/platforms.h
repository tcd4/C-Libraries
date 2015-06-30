#ifndef __PLATFORMS__
#define __PLATFORMS__


/**
 * @file platforms.h
 *
 * @brief contains defines for cross platform and cross language coding
 *
 * Cross Language Coding Declarations for C++ - START_DECLS, END_DECLS
 *
 * Cross Platform defines - OS_WINDOWS, WINDOWS64, OS_MAC, OS_UNIX, OS_LINUX
 */


/* cross language coding declarations for c++ */
#ifdef __cplusplus
/*< start declaration for cross language coding */
#define START_DECLS   extern "C" {
/*< end declaration for cross language coding */
#define END_DECLS     }
#else
#define START_DECLS
#define END_DECLS
#endif


/* windows defines */
#ifdef _WIN32
/*< define for Windows specfic code */
#define OS_WINDOWS     1
#else
#define OS_WINDOWS
#endif

#ifdef _WIN64
#define OS_WINDOWS     1
/*< define for Windows 64 bit specfic code */
#define WINDOWS64      1
#else
#define OS_WINDOWS
#define WINDOWS64
#endif

/* mac define */
#ifdef __APPLE__
/*< define for Mac specfic code */
#define OS_MAC         1
#else
#define OS_MAC
#endif

/* unix define */
#ifdef __unix__
/*< define for Unix specfic code */
#define OS_UNIX        1
#else
#define OS_UNIX
#endif

/* linux define */
#ifdef __linux__
/*< define for Linux specfic code */
#define OS_LINUX       1
#else
#define OS_LINUX
#endif


#endif
