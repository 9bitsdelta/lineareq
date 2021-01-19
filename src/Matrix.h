//Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

/*
 * INPUT & OUTPUT
 */

/*
 * Read a matrix from a FILE*
 */
double** fscan_mat(FILE* file, int rows, int cols);

/*
 * Print a matrix to stdout
 */
void print_mat(double** matrix, int rows, int cols);

/*
 * Clean the contents of a matrix (avoiding memory leaks)
 */
void clean_mat(double** matrix, int rows);

/*
 * ELEMENTARY TRANSFORMATIONS
 */

/*
 * Switch two rows of a matrix
 *
 * - matrix is the matrix on which the transformation is performed
 * - row1 and row2 are the rows which are to be switched
 */
void switch_row(double** matrix, int row1, int row2);

/*
 * Multiply the elements of a row with a value
 *
 * - mat is the matrix on which the transformation is performed
 * - cols is the number of columns of the matrix
 * - row is the row affected by the transformation
 * - value is the factor by which the elements of the row are multiplied
 */
void mult_row(double** matrix, int cols, int row, double value);

/*
 * Add the elements of a row, or a multiple of a row, to another row.
 *
 * - 'matrix' is the matrix on which the transformation is performed
 * - 'cols' is the number of columns of the matrix
 * - 'row_container' is the row which will store the result
 * - 'row_to_add' is the row which will be added.
 * - 'coef' is the factor by which the added row is multiplied
 */
void add_rows(double** matrix, int cols, int row_container, int row_to_add, double coef);

#endif //INOUT_H
