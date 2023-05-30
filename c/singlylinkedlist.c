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
struct node *insertionAtBeginning(struct node *);
struct node *insertionAtEnding(struct node *);
struct node *insertionAfterNode(struct node *);
struct node *deleteFromBeginning(struct node *);
struct node *deleteFromEnding(struct node *);
struct node *deleteGivenNode(struct node *);
struct node *traverse(struct node *);
struct node *sort(struct node *);

int main(int argc, char *argv[])
{
    int option;
    do
    {
        printf("\n 1: Create a Linked list");
        printf("\n 2: Display the Linked list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node after a given node");
        printf("\n 6: Delete a node from the beginning");
        printf("\n 7: Delete a node from the end");
        printf("\n 8: Delete a given node");
        printf("\n 9: Traverse list:");
        printf("\n 10:sorting");
        printf("\n 11: Exit");
        printf("\n\nEnter your option:");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Head = createLinkedList(Head);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            Head = displayLinkedList(Head);
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
            Head = deleteGivenNode(Head);
            break;
        case 9:
            Head = traverse(Head);
            break;
        case 10:
            Head = sort(Head);
            break;
        }
    } while (option != 11);

    return 0;
}
struct node *createLinkedList(struct node *Head)
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
            newNode->next = NULL;
            Head = newNode;
        }
        else
        {
            ptr = Head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("\n Input your data : ");
        scanf("%d", &num);
    }
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
struct node *insertionAtBeginning(struct node *Head)
{
    struct node *newNode;
    int num;
    printf("\n Input your data : ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = Head;
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
    newNode->next = NULL;
    ptr = Head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newNode;
    return Head;
}

struct node *insertionAfterNode(struct node *Head)
{
    struct node *newNode, *ptr, *preptr;
    int num, val;
    printf("\n Input your data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = Head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return Head;
}
struct node *deleteFromBeginning(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    Head = Head->next;
    free(ptr);
    return Head;
}
struct node *deleteFromEnding(struct node *Head)
{
    struct node *ptr, *preptr;
    ptr = Head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return Head;
}
struct node *deleteGivenNode(struct node *Head)
{
    struct node *ptr, *preptr;
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
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return Head;
    }
}
struct node *traverse(struct node *Head)
{
    struct node *ptr;
    ptr = Head;
    if (ptr == NULL)
    {
        printf("empty list");
    }
    else
    {
        printf("printing values.......");
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
        return Head;
    }
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
            while (index != NULL)
            {
                if (ptr->data > index->data)
                {
                    temp = ptr->data;
                    ptr->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            ptr = ptr->next;
        }
        return Head;
    }
}

/*output
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:1

 Enter -1 to end
 Input your data : 1

 Input your data : 2

 Input your data : 3

 Input your data : 4

 Input your data : -1

 LINKED LIST CREATED
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:2
         1       2       3       4
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:3

 Input your data : 0

 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:2
         0       1       2       3       4
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:4

 Input your data : 5

 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:2
         0       1       2       3       4       5
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:5

 Input your data : 10

 Enter the value after which the data has to be inserted : 2

 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:2
         0       1       2       10      3       4       5
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:6

 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:2
         1       2       10      3       4       5
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:7

 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:2
         1       2       10      3       4
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:8

 Enter the value of the node which has to be deleted : 10

 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:2
         1       2       3       4
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Exit

Enter your option:9
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Traverse list:
 10:sorting
 11: Exit

Enter your option:1

 Enter -1 to end
 Input your data : 4

 Input your data : 2

 Input your data : 7

 Input your data : 3

 Input your data : 1

 Input your data : -1

 LINKED LIST CREATED
 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Traverse list:
 10:sorting
 11: Exit

Enter your option:10

 1: Create a Linked list
 2: Display the Linked list
 3: Add a node at the beginning
 4: Add a node at the end
 5: Add a node after a given node
 6: Delete a node from the beginning
 7: Delete a node from the end
 8: Delete a given node
 9: Traverse list:
 10:sorting
 11: Exit

Enter your option:2
         1       2       3       4       7
*/