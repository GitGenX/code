#include <stdio.h>
#include <stdlib.h>

float **memAllocation(int row, int column);
void freeMemory(float **A, int row);
void inputMatrices(float **A, int row, int column);
void displayMatrices(float **mat, int row, int column);
float **multiplyMatrices(float **A, float **B, int r1, int c1, int r2, int c2);

int main()
{
    int r1, r2, c1, c2, row, column;
    float **A, **B, **mat;
    do
    {
        printf("Enter the rows and columns of the first matrices-->\t");
        scanf("%d %d", &r1, &c1);
        printf("Enter the rows and columns of the second matrices-->\t");
        scanf("%d %d", &r2, &c2);
    } while (c2 != r1);

    A = memAllocation(r1, c1);
    B = memAllocation(r2, c2);

    printf("Enter the matrix A-->\t");
    inputMatrices(A, r1, c1);
    printf("Enter the matrix B-->\t");
    inputMatrices(B, r2, c2);

    mat = multiplyMatrices(A, B, r1, c1, r2, c2);

    printf("Relult of A * B matirces is-->\n");
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

float **multiplyMatrices(float **A, float **B, int r1, int c1, int r2, int c2)
{
    float **mat;
    mat = memAllocation(r1, c2);
    int i, j, k;
    for (k = 0; k < r1; k++)
    {
        for (i = 0; i < c2; i++)
        {
            for (j = 0; j < r2; j++)
            {
                mat[k][i] += A[k][j] * B[j][i];
            }
        }
    }
    return mat;
}


/*output
Enter the rows and columns of the first matrices-->     2 2
Enter the rows and columns of the second matrices-->    2 2
Enter the matrix A-->   1 2 3 4
Enter the matrix B-->   4 3 2 1
Relult of A * B matirces is-->
8.00    5.00
20.00   13.00
*/