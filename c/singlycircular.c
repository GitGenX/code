#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *Head = NULL;
struct node *createCircularll(struct node *);
struct node *displayLinkedlist(struct node *);
struct node *insertingAtBeginning(struct node *);
struct node *insertingAtEnding(struct node *);
struct node *deleteFromBeginning(struct node *);
struct node *deleteFromEnding(struct node *);
struct node *traversal(struct node *);
struct node *sorting(struct node *);
int main()
{
    int option;
    do
    {
        printf("\n\n * OPTIONS ***");
        printf("\n 1: Create a Circular Linked list");
        printf("\n 2: Display the Circular Linked list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: traverse the list:");
        printf("\n 8: sort the list:");
        printf("\n 9: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            Head = createCircularll(Head);
            printf("\n CIRCULAR LINKED LIST CREATED");
            break;
        case 2:
            Head = displayLinkedlist(Head);
            break;
        case 3:
            Head = insertingAtBeginning(Head);
            break;
        case 4:
            Head = insertingAtEnding(Head);
            break;
        case 5:
            Head = deleteFromBeginning(Head);
            break;
        case 6:
            Head = deleteFromEnding(Head);
            break;
        case 7:
            Head = traversal(Head);
            break;
        case 9:
            Head = sorting(Head);
            break;
        }
    } while (option != 7);
    return 0;
}
struct node *createCircularll(struct node *Head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Input your data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        if (Head == NULL)
        {
            newNode->next = newNode;
            Head = newNode;
        }
        else
        {
            ptr = Head;
            while (ptr->next != Head)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = Head;
        }
        printf("\n Input your data : ");
        scanf("%d", &num);
    }
    return Head;
}
struct node *displayLinkedlist(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    while (ptr->next != Head)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data);
    return Head;
}
struct node *insertingAtBeginning(struct node *Head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Input your data : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = Head;
    while (ptr->next != Head)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->next = Head;
    Head = newNode;
    return Head;
}
struct node *insertingAtEnding(struct node *Head)
{
    struct node *ptr, *newNode;
    int num;
    printf("\n Input your data : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = Head;
    while (ptr->next != Head)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->next = Head;
    return Head;
}
struct node *deleteFromBeginning(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    while (ptr->next != Head)
        ptr = ptr->next;
    ptr->next = Head->next;
    free(Head);
    Head = ptr->next;
    return Head;
}
struct node *deleteFromEnding(struct node *Head)
{
    struct node *ptr, *preptr;
    ptr = Head;
    while (ptr->next != Head)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return Head;
}
struct node *traversal(struct node *Head)
{
    struct node *ptr = Head;

    if (Head != NULL)
    {
        do
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        } while (ptr != Head);
    }
}
struct node *sorting(struct node *Head)
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
        
        return Head;
    }
}
/*output
 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 1

 Enter -1 to end
 Input your data : 2

 Input your data : 5

 Input your data : 4

 Input your data : 7

 Input your data : -1

 CIRCULAR LINKED LIST CREATED

 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 2
         2       5       4       7

 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 3

 Input your data : 1


 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 2
         1       2       5       4       7

 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 3

 Input your data : 3


 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 2
         3       1       2       5       4       7

 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 5


 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 2
         1       2       5       4       7

 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 6


 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 2
         1       2       5       4

 * OPTIONS ***
 1: Create a Circular Linked list
 2: Display the Circular Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: traverse the list:
 8: sort the list:
 9: EXIT

 Enter your option : 7
        1       2       5       4*/