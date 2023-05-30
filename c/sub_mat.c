#include <stdio.h>
#include <stdlib.h>

float **memAllocation(int row, int column);
void freeMemory(float **A, int row);
void inputMatrices(float **A, int row, int column);
void displayMatrices(float **mat, int row, int column);
float **subtractionMtrices(float **A, float **B, int r1, int c1);

int main()
{
    int r1, r2, c1, c2;
    float **A, **B, **mat;
    do
    {
        printf("Enter the rows and columns of the first matrices-->\t");
        scanf("%d %d", &r1, &c1);
        printf("Enter the rows and columns of the second matrices-->\t");
        scanf("%d %d", &r2, &c2);
    } while (r1 != r2 || c1 != c2);

    A = memAllocation(r1, c1);
    B = memAllocation(r2, c2);

    printf("Enter the matrix A-->\t");
    inputMatrices(A, r1, c1);
    printf("Enter the matrix B-->\t");
    inputMatrices(B, r2, c2);

    mat = subtractionMtrices(A, B,r1,c1);

    printf("Relult of A - B matirces is-->-->\n");
    displayMatrices(mat, r1, c2);

    freeMemory(A, r1);
    freeMemory(B, r2);
    freeMemory(mat, r1);
}

float **memAllocation(int row, int column)
{
    int i;
    float **D;
    D = (float **)calloc(row, sizeof(float *));

    for (i = 0; i < row; i++)
    {
        D[i] = (float *)calloc(column, sizeof(float));
    }

    return D;
}

void freeMemory(float **A, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(A[i]);
    }
    free(A);
}

void inputMatrices(float **A, int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }
}

void displayMatrices(float **mat, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}

float **subtractionMtrices(float **A, float **B, int r1, int c1)
{
    float **mat;
    mat = memAllocation(r1, c1);
    int i, j, k;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            mat[i][j] = A[i][j] - B[i][j];
        }
    }
    return mat;
}

/*output
Enter the rows and columns of the first matrices-->     2 2
Enter the rows and columns of the second matrices-->    2 2
Enter the matrix A-->   8 9 6 5
Enter the matrix B-->   4 3 2 1
Relult of A - B matirces is-->-->
4.00    6.00
4.00    4.00
*/

