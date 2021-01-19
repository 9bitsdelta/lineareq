#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
#include "Misc.h"

extern int g_debug;

int g_stdin = 0;

int main(int argc, char** argv)
{
    /*
     * PARSING THE ARGUMENTS
     */
    if(argc==1) { g_stdin=1; }

    int i;

    for (i = 1; i < argc && argv[i][0] == '-'; i++) {
        switch (argv[i][1]) {
            case 's': g_stdin = 1; break;
            case 'v': g_debug = 1; break;
            case 'V': g_debug = 2; break;
            case 'h': print_help(); exit(EXIT_SUCCESS);
            default:
                fprintf(stderr, "Unknown option, use -h for help...\n");
                exit(EXIT_FAILURE);
        }
    }

    int rows, cols;
    double** mat;

    if (g_stdin==1)
    {
        argc=i+1;
    }

    /*
     * APPLICATION LOOP
     */

    for (; i<argc; i++)
    {
        printf_debug(1,"--File: %s\n", argv[i]);

        /*
         * READING THE FILE(S)
         */
        FILE* stream = (g_stdin==1) ? stdin : fopen(argv[i], "r") ;

        if(!stream)
        {
            fprintf(stderr, "File opening failed\n\n");
            continue;
        }

        fscanf(stream, "%d %d", &rows, &cols);

        mat = fscan_mat(stream, rows, cols);

        fclose(stream);

        printf_debug(1, "Initial Matrix:\n");
        print_mat_debug(1, mat, rows, cols);

        /*
         * SOLVE THE SYSTEM
         */
        mat = gauss_jordan(2, mat, rows, cols);

        /*
        * RESULT
        */
        printf_debug(1,"Result:\n");
        print_mat(mat, rows, cols);

        /*
         * CLEAN
         */
        clean_mat(mat, rows);
    }

    return 0;
}
