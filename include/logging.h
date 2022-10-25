/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#ifndef LOGGING_H__
#define LOGGING_H__

// Please feel free to use the logging utilities in this file to make your 
// debugging easier!

#ifdef __cplusplus
extern "C" {
#endif

    #include <constants.h>
    #include <stdio.h>

    // These logging macros are included for your convenience.

    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_YELLOW  "\x1b[33m"
    #define ANSI_COLOR_BLUE    "\x1b[34m"
    #define ANSI_COLOR_MAGENTA "\x1b[35m"
    #define ANSI_COLOR_CYAN    "\x1b[36m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

    // If logging is enabled, then the macros are declared as the following. The 
    // macros just pass the arguments to the fprintf function which is modified 
    // to log with some color and format.
    #ifdef ENABLE_LOGGING
    #define INFO_LOG(_f, ...) fprintf(stderr, ANSI_COLOR_GREEN "[Info]: " \
        ANSI_COLOR_RESET _f "\n", ##__VA_ARGS__);

    #define WARNING_LOG(_f, ...) fprintf(stderr, ANSI_COLOR_YELLOW "[Warning]: " \
        ANSI_COLOR_RESET _f "\n", ##__VA_ARGS__);

    #define WARNING_LOGV(_f, ...) fprintf(stderr, ANSI_COLOR_YELLOW "[Warning]: " \
        ANSI_COLOR_RESET _f " at line %d in %s\n", __LINE__, __FILE__, ##__VA_ARGS__);

    #define ERROR_LOG(_f, ...) fprintf(stderr, ANSI_COLOR_RED "[Error]: " \
        ANSI_COLOR_RESET _f "\n", ##__VA_ARGS__);

    #define ERROR_LOGV(_f, ...) fprintf(stderr, ANSI_COLOR_RED "[Error]: " \
        ANSI_COLOR_RESET _f " at line %d in %s\n", __LINE__, __FILE__, ##__VA_ARGS__);
    #else
    // Here, logging is disabled, so all the macros expand to do nothing.
    #define INFO_LOG(_f, ...)
    #define WARNING_LOG(_f, ...)
    #define WARNING_LOGV(_f, ...)
    #define ERROR_LOG(_f, ...)
    #define ERROR_LOGV(_f, ...)
    #endif

#ifdef __cplusplus
}
#endif

#endif