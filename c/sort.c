#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *Head = NULL;
struct node *createLinkedList(struct node *);
struct node *displayLinkedList(struct node *);
struct node *sort(struct node *);
int main(int argc, char *argv[])
{
    int n;

    printf("\n 1: Create a Linked list");
    Head = createLinkedList(Head);
    printf("\n LINKED LIST CREATED");
    printf("\n 2: Display the Linked list");
    Head = displayLinkedList(Head);
    printf("\n 10:sorting");
    Head = sort(Head);

    return 0;
}

struct node *sort(struct node *Head)
{
    struct node *ptr, *index = NULL;
    int temp;
    ptr = Head;
    if (ptr == NULL)
    {
        printf("empty list");
    }
    else
    {
        while (ptr != NULL)
        {
            index = ptr->next;
            while (ptr != NULL)
            {
                if (ptr->data > index->data)
                {
                    temp = ptr->data;
                    ptr->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            printf("%d",ptr->data);
            ptr = ptr->next;
        }
    }
}