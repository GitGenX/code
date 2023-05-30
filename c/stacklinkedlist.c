
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

struct stack *top = NULL;

struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

int main()
{
	int value, option;
	do
	{
		printf("\n ***** OPTIONS *****\n 1. PUSH\n 2. POP\n 3. PEEK\n 4. DISPLAY\n 5. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			printf("\n Enter the number to be pushed on stack: ");
			scanf("%d", &value);
			top = push(top, value);
			break;
			case 2:
			top = pop(top);
			break;
			case 3:
			value = peek(top);
			if (value != -1)
				printf("\n The value at the top of stack is: %d", value);
			else
				printf("\n STACK IS EMPTY");
			break;
			case 4:
			top = display(top);
			break;
		}
	}while(option != 5);
	return 0;
}
struct stack *push(struct stack *top, int value)
{
	struct stack *ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack));
	ptr -> data = value;
	if(top == NULL)
	{
		ptr -> next = NULL;
		top = ptr;
	}
	else
	{
		ptr -> next = top;
		top = ptr;
	}
	return top;
}
struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top == NULL)
		printf("\n STACK UNDERFLOW");
	else
	{
		top = top -> next;
		printf("\n The value being deleted is: %d", ptr -> data);
		free(ptr);
	}
	return top;
}
int peek(struct stack *top)
{
	if(top==NULL)
		return -1;
	else
		return top ->data;
}
struct stack *display(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top == NULL)
		printf("\n STACK IS EMPTY");
	else
	{
        printf("\n STACK elements-->");
		while(ptr != NULL)
		{
			printf("\n %d", ptr -> data);
			ptr = ptr -> next;
		}
	}
	return top;
}