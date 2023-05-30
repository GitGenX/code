
#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",A[i]);
    }
    printf(" \n");
}

void selectionsort(int *A, int n){
    int min,temp;
    printf("..................\n");
    for (int i = 0; i < n-1; i++)
    {
        min=i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j]<A[min])
            {
                min=j;
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}

int main(){
    int n;
    int *A;
    printf("the number of array:");
    scanf("%d",&n);
    A = (int *)malloc(sizeof(int)*n);
        for (int i=0 ; i<n ; i++)
        {
            printf(">>Enter the element %d\n" , i+1);
            scanf("%d", &A[i]);
        }
    printArray(A,n);
    selectionsort(A,n);
    printArray(A,n);

    return 0;
}