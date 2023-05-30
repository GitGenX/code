#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *Head = NULL;
struct node *createDoublyCircularll(struct node *);
struct node *displayLinkedlist(struct node *);
struct node *insertingAtBeginning(struct node *);
struct node *insertingAtEnding(struct node *);
struct node *deleteFromBeginning(struct node *);
struct node *deleteFromEnding(struct node *);
struct node *deleteGivenNode(struct node *);
struct node *traversal(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n\n * OPTIONS ***");
        printf("\n 1: Create a doubly circular linked list");
        printf("\n 2: Display the doubly circular linked list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a given node");
        printf("\n 8: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Head = createDoublyCircularll(Head);
            printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
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
            Head = deleteGivenNode(Head);
            break;
        }
    } while (option != 8);
    return 0;
}
struct node *createDoublyCircularll(struct node *Head)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Input your data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (Head == NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->prev = newNode;
            newNode->data = num;
            newNode->next = newNode;
            Head = newNode;
        }
        else
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = num;
            ptr = Head;
            while (ptr->next != Head)
                ptr = ptr->next;
            newNode->prev = ptr;
            ptr->next = newNode;
            newNode->next = Head;
            Head->prev = newNode;
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
    newNode->prev = ptr;
    ptr->next = newNode;
    newNode->next = Head;
    Head->prev = newNode;
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
    newNode->prev = ptr;
    newNode->next = Head;
    Head->prev = newNode;
    return Head;
}
struct node *deleteFromBeginning(struct node *Head)
{
    struct node *ptr, *temp;
    ptr = Head;
    while (ptr->next != Head)
        ptr = ptr->next;
    ptr->next = Head->next;
    temp = Head;
    Head = Head->next;
    Head->prev = ptr;
    free(temp);
    return Head;
}
struct node *deleteFromEnding(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    while (ptr->next != Head)
        ptr = ptr->next;
    ptr->prev->next = Head;
    Head->prev = ptr->prev;
    free(ptr);
    return Head;
}
struct node *deleteGivenNode(struct node *Head)
{
    struct node *ptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);
    ptr = Head;
    if (ptr->data == val)
    {
        Head = deleteFromBeginning(Head);
        return Head;
    }
    else
    {
        while (ptr->data != val)
            ptr = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return Head;
    }
}
/*output
 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 1

 Enter -1 to end
 Input your data : 5

 Input your data : 4

 Input your data : 1

 Input your data : 2

 Input your data : -1

 CIRCULAR DOUBLY LINKED LIST CREATED

 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 2
         5       4       1       2

 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 3

 Input your data : 3


 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 2
         3       5       4       1       2

 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 4

 Input your data : 6


 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 2
         3       5       4       1       2       6

 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 5


 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 2
         5       4       1       2       6

 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 6


 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 2
         5       4       1       2

 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 7

 Enter the value of the node which has to be deleted : 4


 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 2
         5       1       2

 * OPTIONS ***
 1: Create a doubly circular linked list
 2: Display the doubly circular linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Delete a node from the beginning
 6: Delete a node from the end
 7: Delete a given node
 8: EXIT

 Enter your option : 8*/