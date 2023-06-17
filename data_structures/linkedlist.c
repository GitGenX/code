#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

struct Node *createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertAtBegining(Node** head,int data)
{
    Node* newNode = createNode(data);
    newNode->next=*head;
    *head = newNode;
}
void insertAtEnd(Node** head,int data)
{
    Node* newNode = createNode(data);
    if(*head==NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
}
void deleteNode(Node** head,int data)
{
    if(*head == NULL)
    {
        printf("List is empty.");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!=NULL && temp->data==data)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data!=data)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp == NULL)
    {
        printf("element not found inthe list.");
        return;
    }
    prev->next=temp->next;
    free(temp);    
}

void display(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    Node* temp = head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete a node\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtBegining(&head, data);
                printf("Node inserted at the beginning.\n");
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Node inserted at the end.\n");
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
