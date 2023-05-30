#include <stdio.h>
#include <stdlib.h>

int *main();
void *insert();
void *print();

void *insert(int arr[], int *n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j <= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
void *print(int arr[], int *n)
{
    printf("Arrays after sorting in assending order :: ");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}
int *main()
{
    int n;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    insert(arr,n);
    print(arr,n);
}