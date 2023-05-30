#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *Head = NULL;
struct node *create(struct node *);
struct node *traverse(struct node *);
struct node *insertatfirst(struct node *);
struct node *displayLinkedList(struct node *);

int main(int argc, char const *argv[])
{
    int option;
    do
    {
        printf("\n1.create a linked list.\n");
        printf("\n2.traverse a linked list.\n");
        printf("\n3.insert a number at first.\n");
        printf("\n4.Display.\n");

        scanf("%d", &option);
        switch (option)
        {
        case 1:
            Head = create(Head);
            printf("linked list created.");
            break;
        case 2:
            Head = traverse(Head);
            break;
        case 3:
            Head = insertatfirst(Head);
            break;
        case 4:
            Head = insertatfirst(Head);
            break;
        }
    } while (option != 5);
    return 0;
}

struct node *create(struct node *Head)
{
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to stop.");
    printf("Enter the number:");
    scanf("%d", &num);

    while (num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (Head == NULL)
        {
            newnode->next = NULL;
            Head = newnode;
        }
        else
        {
            ptr = Head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("\nInput your data:");
        scanf("%d", &num);
    }
    return 0;
}
struct node *traverse(struct node *Head)
{
    struct node *ptr;
    if (ptr = NULL)
    {
        printf("Empty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
    }
    return Head;
}
struct node *insertatfirst(struct node *Head)
{
    struct node *ptr;
    int number;
    printf("Enter a number:");
    scanf("%d", &number);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = number;
    ptr->next = Head;
    Head = ptr;

    return Head;
}

struct node *displayLinkedList(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return Head;
}