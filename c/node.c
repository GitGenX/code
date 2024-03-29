#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void traverselinkedlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("-->%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 41;
    third->next = forth;

    forth->data = 12;
    forth->next = NULL;

    traverselinkedlist(head);
    return 0;
}