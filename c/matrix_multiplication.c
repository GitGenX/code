#include<stdio.h>
#include<stdlib.h>

int ** mem_Alc(int r,int c);
void readMat(int **arr,int r,int c);
void displayMat(int **arr,int r,int c);
void addMat(int **arr1,int **arr2,int **arr3,int p,int r,int q);

void main()
{
   	int **arr1,**arr2,**arr3,r1,c1,r2,c2,i,j;  
   	step1: 
   	printf("Enter rows and columns of first matrix:\n");
   	scanf("%d%d",&r1,&c1);
   	printf("\nEnter rows and columns of second matrix:\n");
   	scanf("%d%d",&r2,&c2);
   
   	if(c1!=r2)
   	{
      		printf("\nCannot perform matrix multiplication.\n");
      		goto step1;
   	}
   	else
   	{
      		arr1=mem_Alc(r1,c1);
      		arr2=mem_Alc(r2,c2);
      		arr3=mem_Alc(r1,c2);
         
      		printf("\nEnter the elements of the first matrix:\n");
      		readMat(arr1,r1,c1);
      		
      		printf("\nEnter the elements of the second matrix:\n");
      		readMat(arr2,r2,c2);
      		
      		printf("\nThe elements of the first matrix are as follows:\n");
      		displayMat(arr1,r1,c1);
      		
      		printf("\nThe elements of the second matrix are as follows:\n");
      		displayMat(arr2,r2,c2);
      		
      		addMat(arr1,arr2,arr3,r1,c2,r2);
      		
      		printf("\nThe result of multiplication of the two matrices is as follows:\n");
      		displayMat(arr3,r1,c2);
   	}
}

int ** mem_Alc(int r,int c)
{
	int **arr,i;
	
	arr=(int **)calloc(r,sizeof(int *));
	for(i=0;i<r;i++)
   	{
      		arr[i]=(int *)calloc(c,sizeof(int));
   	}
   	return arr;
}

void readMat(int **arr,int r,int c)
{
   	int i,j;
   	
   	for(i=0;i<r;i++)
   	{
      		for(j=0;j<c;j++)
      		{
         		scanf("%d",&arr[i][j]);
      		}
   	}
}
void displayMat(int **arr,int r,int c)
{
   	int i,j;
   	
   	for(i=0;i<r;i++)
   	{
      		for(j=0;j<c;j++)
      		{
         		printf("%d\t",arr[i][j]);
      		}
      		printf("\n");
   	}
}

void addMat(int **arr1,int **arr2,int **arr3,int p,int r,int q)
{
   	int i,j,k;
   	
   	for(i=0;i<p;i++)
   	{
      		for(j=0;j<r;j++)
      		{
				arr3[i][j]=arr1[i][j]+arr2[i][j];       
      		}
   	}
}