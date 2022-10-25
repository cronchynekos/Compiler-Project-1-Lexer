/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#ifndef CONSTANTS_H__
#define CONSTANTS_H__

// Enable (1) or disable (0) logging. 
// Logging should always be enabled for this project.
#define ENABLE_LOGGING 1

// Assertions make use of the ASSERT(expression) macro from assertions.h. 
// If this flag is set to 0, then all assertions will not be compiled into 
// the final executable. You can use this ASSERT macro to ensure your code 
// is behaving the way you expect it to and then you may easily turn off 
// all assertions and not have them effect the resulting executable here.
#define ASSERTIONS_ENABLED 1

// The debug break stops the program and waits for a debbuger such as 
// GDB to attach. The debug breaks are built into each assertion, as 
// long as they are enabled.
#define DEBUG_BREAK_ENABLED 1

// Static assertions make use of the STATIC_ASSERT(expression) macro from 
// assertions.h. The purpose of STATIC_ASSERT is to assert facts that are 
// known at compile time and not during execution. An example of this may 
// be to ensure that a structure is the expected size during compilation.
#define STATIC_ASSERTIONS_ENABLED 1

#endif