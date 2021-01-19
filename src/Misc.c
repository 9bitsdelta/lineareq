#include <stdio.h>
#include <stdarg.h>

#include "Misc.h"
#include "Matrix.h"

int g_debug = 0;

void printf_debug(int debugLevel, const char* format, ...)
{
    if(g_debug >= debugLevel)
    {
        va_list arg;
        va_start(arg, format);
        vprintf(format, arg);
        va_end(arg);
    }
}

void print_mat_debug(int debugLevel, double** matrix, int rows, int cols)
{
    if(g_debug >= debugLevel)
    {
        print_mat(matrix, rows, cols);
    }
}

void print_help()
{
    printf("Usage: lineareq [option] <files>"
           "\n"
           "\nCalculate systems of linear equations"
           "\n"
           "\nOptions:"
           "\n  -v    run verbose"
           "\n  -V    run very verbose"
           "\n  -s    use standard input instead of files"
           "\n  -h    show this message and exit"
           "\n"
           );
}

double** gauss_jordan(int debugLevel, double** matrix, int rows, int cols)
{
    /*
     * GETTING THE PRIMARY EQUATIONS
     */
    int sq = (rows <= cols-1) ? rows : cols-1;

    for (int diag = 0; diag < sq; diag++)
    {

        //CHECK TO SEE IF WE SIT ON AN ELEMENT THAT IS NULL, switch_row() IF IT IS

        if (matrix[diag][diag] == 0)
        {
            for(int under = diag + 1;;under++)
            {
                if (under == rows)
                {
                    fprintf(stderr,"No non-null element found on column %d\n", diag+1);
                    return matrix;
                }
                if (matrix[under][diag] != 0)
                {
                    switch_row(matrix, under, diag);
                    print_mat_debug(debugLevel, matrix, rows, cols);
                    break;
                }
            }
        }

        /*
         * ELIMINATION PROCESS
         */
        for (int target = 0; target < rows; target++)
        {
            if(matrix[target][diag]==0) continue;

            if(target==diag) continue;


            add_rows(matrix, cols, target, diag, -matrix[target][diag]/matrix[diag][diag]);
            print_mat_debug(debugLevel, matrix, rows, cols);

            if (matrix[diag][diag]==1) continue;

            mult_row(matrix, cols, diag, 1 / matrix[diag][diag]);
            print_mat_debug(debugLevel, matrix, rows, cols);
        }
    }
    return matrix;
}

