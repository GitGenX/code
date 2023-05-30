#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, min, j;
    int *array;
    printf("The no of elements >> ");
    scanf("%d", &n);
    array = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        printf(">>Enter the element %d\n", i + 1);
        scanf("%d", &array[i]);
    }
    for (i = 0; i < n; ++i)
    {
        min = i;
        for (j = i + 1; j < n; ++j)
        {
            if (array[j] < array[min])
                min = j;
        }
        if (min != i)
        {
            int temp;
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    printf("In ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("--> %d\n", array[i]);
    };
    for (i = 0; i < n; ++i)
    {
        min = i;
        for (j = i + 1; j < n; ++j)
        {
            if (array[j] > array[min])
                min = j;
        }
        if (min != i)
        {
            int temp;
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    printf("In descending order::\n");
    for (i = 0; i < n; i++)
    {
        printf("--> %d\n", array[i]);
    };
}
/*output
The no of elements >> 5
>>Enter the element 1
7
>>Enter the element 2
9
>>Enter the element 3
2
>>Enter the element 4
4
>>Enter the element 5
1
In ascending order:
--> 1
--> 2
--> 4
--> 7
--> 9
In descending order::
--> 9
--> 7
--> 4
--> 2
--> 1*/