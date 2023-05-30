#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *Head = NULL;
struct node *createDoublyll(struct node *);
struct node *displayLinkedlist(struct node *);
struct node *insertionAtBeginning(struct node *);
struct node *insertionAtEnding(struct node *);
struct node *insertionAfterNode(struct node *);
struct node *deleteFromBeginning(struct node *);
struct node *deleteFromEnding(struct node *);
struct node *traversal(struct node *);
struct node *deleteGivenNode(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n\n * OPTIONS ***");
        printf("\n 1: Create a Doubly Linked list");
        printf("\n 2: Display the Linked list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node after a given node");
        printf("\n 6: Delete a node from the beginning");
        printf("\n 7: Delete a node from the end");
        printf("\n 8: Traverse list");
        printf("\n 9: Delete form a given node:");
        printf("\n 10: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Head = createDoublyll(Head);
            printf("\n DOUBLY LINKED LIST CREATED!!!");
            break;
        case 2:
            Head = displayLinkedlist(Head);
            break;
        case 3:
            Head = insertionAtBeginning(Head);
            break;
        case 4:
            Head = insertionAtEnding(Head);
            break;
        case 5:
            Head = insertionAfterNode(Head);
            break;
        case 6:
            Head = deleteFromBeginning(Head);
            break;
        case 7:
            Head = deleteFromEnding(Head);
            break;
        case 8:
            Head = traversal(Head);
            break;
        case 9:
            Head = deleteGivenNode(Head);
            break;
        }
    } while (option != 10);
    return 0;
}
struct node *createDoublyll(struct node *Head)
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
            newNode->prev = NULL;
            newNode->data = num;
            newNode->next = NULL;
            Head = newNode;
        }
        else
        {
            ptr = Head;
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = num;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = NULL;
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
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return Head;
}
struct node *insertionAtBeginning(struct node *Head)
{
    struct node *newNode;
    int num;
    printf("\n Input your data : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    Head->prev = newNode;
    newNode->next = Head;
    newNode->prev = NULL;
    Head = newNode;
    return Head;
}
struct node *insertionAtEnding(struct node *Head)
{
    struct node *ptr, *newNode;
    int num;
    printf("\n Input your data : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = Head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = NULL;
    return Head;
}
struct node *insertionAfterNode(struct node *Head)
{
    struct node *newNode, *ptr;
    int num, val;
    printf("\n Input your data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = Head;
    while (ptr->data != val)
        ptr = ptr->next;
    newNode->prev = ptr;
    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    return Head;
}
struct node *deleteFromBeginning(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    Head = Head->next;
    Head->prev = NULL;
    free(ptr);
    return Head;
}
struct node *deleteFromEnding(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->prev->next = NULL;
    free(ptr);
    return Head;
}
struct node *deleteGivenNode(struct node *Head)
{
    struct node *ptr = Head, *temp = Head;
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    while (temp->data != value)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("\nCannot delete");
        }
        else if (temp->next->next == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            ptr = temp->next;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            free(ptr);
        }
    }
    return Head;
}

struct node *traversal(struct node *Head)
{
    struct node *ptr = Head;
    if (ptr == NULL)
    {
        printf("empty list");
    }
    else
    {
        printf("printing values.......\n");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
        return Head;
    }
}
/*output
* OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 1

 Enter -1 to end
 Input your data : 1

 Input your data : 2

 Input your data : 3

 Input your data : 4

 Input your data : -1

 DOUBLY LINKED LIST CREATED!!!

 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 2
         1       2       3       4

 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 3

 Input your data : 0


 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 2
         0       1       2       3       4

 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 4

 Input your data : 5


 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 5

 Input your data : 6

 Enter the value after which the data has to be inserted : 3


 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 2
         0       1       2       3       6       4       5

 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 6


 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 2
         1       2       3       6       4       5

 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 7


 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 2
         1       2       3       6       4


 Enter -1 to end
 Input your data : 1

 Input your data : 2

 Input your data : 3

 Input your data : 4

 Input your data : -1

 DOUBLY LINKED LIST CREATED!!!

 * OPTIONS ***
 1: Create a Doubly Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Traverse list
 9: EXIT

 Enter your option : 8
printing values.......
        1       2       3       4

*/