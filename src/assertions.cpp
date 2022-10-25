/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#include <assertions.h>
#include <logging.h>

void reportAssertionFailure(const char *expression, const char *file, unsigned int line)
{
    fprintf(stderr, ANSI_COLOR_RED "[ASSERTION FAILED]:" ANSI_COLOR_RESET
        " %s failed in %s on line %d\n", expression, file, line);
}
