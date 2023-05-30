#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf(" \n");
}

void insertionsort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > current)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = current;
    }
}

int main()
{
    int n;
    int *A;
    printf("the number of array:");
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf(">>Enter the element %d\n", i + 1);
        scanf("%d", &A[i]);
    }
    printArray(A, n);
    insertionsort(A, n);
    printArray(A, n);

    return 0;
}