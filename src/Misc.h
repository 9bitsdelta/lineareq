#ifndef MISC_H
#define MISC_H

/*
 * Print format to stdout when the global debug variable
 * is larger than or equal to debugLevel
 */
void printf_debug(int debugLevel, const char* format, ...);

/*
 * Print the '--help' message to stdout
 */
void print_help();

/*
 * Print a matrix to stdout when the global debug variable
 * is larger or equal to debugLevel
 */
void print_mat_debug(int debugLevel, double** matrix, int rows, int cols);

/*
 * Applies the Gauss-Jordan Elimination method to the matrix
 * - if debugLevel is less than or equal to the global debug variable then the
 * function will print every step of the process to stdout
 */
double** gauss_jordan(int debugLevel, double** matrix, int rows, int cols);

#endif //MISC_H