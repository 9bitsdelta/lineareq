#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"

/*
 * INPUT & OUTPUT
 */

double** fscan_mat(FILE* file, int rows, int cols
{
    double** mat;
    mat = malloc(sizeof(double*)*rows);
    for (int y = 0; y < rows; y++)
    {
        mat[y] = malloc(sizeof(double)*cols);
        for (int x = 0; x < cols; x++)
        {
            fscanf(file, "%lf", &mat[y][x]);
        }
    }
    return mat;
}

void print_mat(double** matrix, int rows, int cols)
{
    for(int y=0; y<rows; y++)
    {
        for (int x = 0; x<cols; x++)
        {
            printf("%g ", matrix[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

void clean_mat(double** matrix, int rows)
{
    for (int y = 0; y < rows; y++)
    {
        free(matrix[y]);
    }
    free(matrix);
}

/*
 * ELEMENTARY TRANSFORMATIONS
 */

void switch_row(double** matrix, int row1, int row2)
{
    double* extra;
    extra = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = extra;
}

void mult_row(double** matrix, int cols, int row, double value)
{
    for(int x=0; x<cols; x++)
    {
        matrix[row][x]*=value;
    }
}

void add_rows(double** matrix, int cols, int row_container, int row_to_add, double coef)
{
    for(int x=0; x<cols; x++)
    {
        matrix[row_container][x] += coef * matrix[row_to_add][x];
    }
}