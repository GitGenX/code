#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("Enter the size of the array.\n");
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));
	printf("Start entering all the elements::\n");
	for (int a = 1; a < n; a++)
		scanf("%d\n", &arr[a]);

	for (int i = 2; i < n; i++)
	{
		int current = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > current)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
	}

	printf("Arrays after sorting in assending order :: ");
	for (int i = 0; i < n; i++)
		printf("%d  ", arr[i]);

	return 0;
}