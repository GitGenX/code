#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front;
	struct node *rear;
};
struct queue *que;

struct queue * create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
	int value, option;
	que = create_queue(que);
	do
	{
		printf("\n\n ***** OPTIONS *****\n 1. Insert an element\n 2. Delete an element\n 3. Peek\n 4. Display the queue\n 5. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			printf("\n Enter the number to insert in the queue:");
			scanf("%d", &value);
			que = insert(que,value);
			break;
			case 2:
			que = delete_element(que);
			break;
			case 3:
			value = peek(que);
			if(value != -1)
				printf("\n The value at front of queue is : %d", value);
			break;
			case 4:
			que = display(que);
			break;
		}
	}while(option != 5);
	return 0;
}
struct queue * create_queue(struct queue *que)
{
	que = (struct queue*)malloc(sizeof(struct queue));
	que -> rear = NULL;
	que -> front = NULL;
	return que;
}
struct queue *insert(struct queue *que,int value)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = value;
	if(que -> front == NULL)
	{
		que -> front = ptr;
		que -> rear = ptr;
		que -> front -> next =NULL;
        que -> rear = que->front;
	}
	else
	{
		que -> rear -> next = ptr;
		que -> rear = ptr;
		que -> rear -> next = NULL;
	}
	return que;
}
struct queue *delete_element(struct queue *que)
{
	struct node *ptr;
	ptr = que -> front;
	if(que -> front == NULL)
		printf("\n UNDERFLOW");
	else
	{
		que -> front = que -> front -> next;
		printf("\n The value being deleted is : %d", ptr -> data);
		free(ptr);
	}
	return que;
}
int peek(struct queue *que)
{
	if(que->front==NULL)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
		return que->front->data;
}
struct queue *display(struct queue *que)
{
	struct node *ptr;
	ptr = que -> front;
	if(ptr == NULL)
		printf("\n QUEUE IS EMPTY");
	else
	{
		printf("\n");
		while(ptr!=que -> rear)
		{
			printf("%d\t", ptr -> data);
			ptr = ptr -> next;
		}
		printf("%d\t", ptr -> data);
	}
	return que;
}