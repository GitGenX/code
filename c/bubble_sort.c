#include<stdio.h>
#include<stdlib.h>
void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",A[i]);
    }
    printf(" \n");
}
void swap(int *a,int *b)
{
	int temp = *a;
	*a =*b;
	*b =temp;
}
void bubblesort(int *A,int n){
    for(int i=0;i<n-1;i++)
		for(int j=i+1; j<n;j++)
			if(A[i] > A[j])
        swap(&A[i],&A[j]);
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
    bubblesort(A,n);
    printArray(A,n);

    return 0;
}