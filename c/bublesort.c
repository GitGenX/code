#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n = 0;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Start entering all the element:\n");
    for (int a = 0; a < n; a++)
        scanf("%d\n", &arr[a]);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
    printf("sorted array:");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    return 0;
}