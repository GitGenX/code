#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left_child, *right_child;
} Node;

Node *new_node(int);
Node *insert_node(Node *, int);
void ascending(Node *);
void descendin(Node *);

int main()
{
    int n, data, ch;
    Node *root_node = NULL;

    do
    {
        printf("1. Insert Element\n");
        printf("2. Ascending order\n");
        printf("3. Decending order\n");
        printf("4. Exit\n");

        printf("Enter your choice :\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("How many numbers-->\t");
            scanf("%d", &n);
            printf("Enter %d numbers-->\n", n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root_node = insert_node(root_node, data);
            }
            break;
        case 2:
            printf("Ascending order-->\t");
            ascending(root_node);
            printf("\n");
            break;
        case 3:
            printf("Descending order-->\t");
            descendin(root_node);
            printf("\n");
        case 4:
            break;
        default:
            printf("Please enter correct option!!\n\n");
            break;
        }
    } while (ch != 4);
}

Node *new_node(int data)
{
    Node *temp = (Node *)calloc(data, sizeof(Node));
    temp->data = data;
    temp->left_child = temp->right_child = NULL;
    return temp;
}

Node *insert_node(Node *node, int data)
{
    if (node == NULL)
    {
        return new_node(data);
    }
    else if (data <= node->data)
    {
        node->left_child = insert_node(node->left_child, data);
    }
    else if (data > node->data)
    {
        node->right_child = insert_node(node->right_child, data);
    }
    return node;
}

void ascending(Node *node)
{
    if (node == NULL)
        return;
    ascending(node->left_child);
    printf("%d\t", node->data);
    ascending(node->right_child);
}
void descendin(Node *node)
{
    if (node == NULL)
        return;
    descendin(node->right_child);
    printf("%d\t", node->data);
    descendin(node->left_child);
}
