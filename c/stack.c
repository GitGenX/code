#include <stdio.h>
#include <stdlib.h>

int top=-1,max;

void push(int *stack, int value);
int pop(int *stack);
int peek(int *stack);
void display(int *stack);

int main() 
{
	int *stack, value, option;
	printf("Enter the maximum size of the stack :\t");
	scanf("%d",&max);
	stack = (int*)calloc(max,sizeof(int));
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
			push(stack, value);
			break;
			case 2:
			value = pop(stack);
			if(value != -1)
				printf("\n The value deleted from stack is: %d", value);
			break;
			case 3:
			value = peek(stack);
			if(value != -1)
				printf("\n The value stored at top of stack is: %d", value);
			break;
			case 4:
			display(stack);
			break;
		}
	}while(option != 5);
	return 0;
}
void push(int *stack, int value)
{
	if(top == max-1)
	{
		printf("\n STACK OVERFLOW");
	}
	else
	{
		top++;
		stack[top] = value;
	}
}
int pop(int *stack)
{
	int value;
	if(top == -1)
	{
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else
	{
		value = stack[top];
		top--;
		return value;
	}
}
int peek(int *stack)
{
	if(top == -1)
	{
		printf("\n STACK IS EMPTY");
		return -1;
	}
	else
		return (stack[top]);
}
void display(int *stack)
{
	int i;
	if(top == -1)
		printf("\n STACK IS EMPTY");
	else
	{
        printf("\n STACK elements-->");
		for(i=top;i>=0;i--)
			printf("\n %d",stack[i]);
		printf("\n");
	}
}