#define _MATHEAD_H_

#include <stdio.h>
#include <stdlib.h>

int r1, r2, c1, c2, row, column;
float **A, **B, **mat;

float **memAllocation(int row, int column);
void freeMemory(float **A, int row);
void inputMatrices(float **A, int row, int column);
void displayMatrices(float **mat, int row, int column);

float **addMatrices(float **A, float **B, int r1, int c1);
float **subtractionMtrices(float **A, float **B, int r1, int c1);
float **multiplyMatrices(float **A, float **B, int r1, int c1, int r2, int c2);

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
// Matrix addition
float **addMatrices(float **A, float **B, int r1, int c1)
{
    mat = memAllocation(r1, c1);
    int i, j;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            mat[i][j] = A[i][j] + B[i][j];
        }
    }
    return mat;
}
// Matrix subtraction
float **subtractionMtrices(float **A, float **B, int r1, int c1)
{
    mat = memAllocation(r1, c1);
    int i, j, k;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            mat[i][j] = B[i][j] - A[i][j];
        }
    }
    return mat;
}
// Matrix multiplication
float **multiplyMatrices(float **A, float **B, int r1, int c1, int r2, int c2)
{
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