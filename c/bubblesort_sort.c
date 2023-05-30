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
	printf("Start entering all the elements::\n");
	for (int a = 0; a < n; a++)
		scanf("%d\n", &arr[a]);
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
	printf("\nArrays after sorting in assending order :: \n");
	for (int i = 0; i < n; i++)
		printf("%d  ", arr[i]);

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
	printf("Arrays after sorting in dessending order :: \n");
	for (int i = 0; i < n; i++)
		printf("%d  ", arr[i]);
	return 0;
}
/*output
Enter the size of the array.
5
Start entering all the elements::
7
4
6
5
1
Arrays after sorting in assending order :: 
1  4  5  6  7  
Arrays after sorting in dessending order :: 
7  6  5  4  1  
*/