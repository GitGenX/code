#include <stdio.h>
#include <stdlib.h>

int *queue, max;
int front = -1, rear = -1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
	int option, value;
	printf("Enter the maximum size of the queue :\t");
	scanf("%d",&max);
	queue = (int*)calloc(max,sizeof(int));
	do
	{
		printf("\n\n ***** OPTIONS *****\n 1. Insert an element\n 2. Delete an element\n 3. Peek\n 4. Display the queue\n 5. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			insert();
			break;
			case 2:
			value = delete_element();
			if (value != -1)
				printf("\n The number deleted is : %d", value);
			break;
			case 3:
			value = peek();
			if (value != -1)
				printf("\n The first value in queue is : %d", value);
			break;
			case 4:
			display();
			break;
		}
	}while(option != 5);
	return 0;
}
void insert()
{
	int num;
	printf("\n Enter the number to be inserted in the queue : ");
	scanf("%d", &num);
	if(rear == max-1)
	{
		printf("\n OVERFLOW");
		return;
	}
	else if(front == -1 && rear == -1)
		front = rear = 0;
	else
		rear++;
	queue[rear] = num;
}
int delete_element()
{
	int value;
	if(front == -1 || front>rear)
	{
		printf("\n UNDERFLOW");
		return -1;
	}
	else
	{
		value = queue[front];
		front++;
		if(front > rear)
			front = rear = -1;
		return value;
	}
}
int peek()
{
	if(front==-1 || front>rear)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
	{
		return queue[front];
	}
}
void display()
{
	int i;
	printf("\n");
	if(front == -1 || front > rear)
		printf("\n QUEUE IS EMPTY");
	else
	{
        printf("\n QUEUE elements-->");
		for(i = front;i <= rear;i++)
			printf("\t %d", queue[i]);
	}
}