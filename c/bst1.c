
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left_child, *right_child;
} Node;

Node *new_node(int);
Node *insert_node(Node *, int);
int search(Node *,int);
Node *min_value_node(Node *);
Node *delete_node(Node *, int);
void inOrder(Node *);

int main()
{
    int data, ch;
    Node *root_node = NULL;

    do
    {
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Exit\n");

        printf("Enter your choice :\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to be inserted-->\t");
            scanf("%d", &data);
            root_node = insert_node(root_node, data);
            printf("In-ordered-->\n");
            inOrder(root_node);
            printf("\n");
            break;
        case 2:
            printf("Enter data to be deleted-->\t");
            scanf("%d", &data);
            root_node = delete_node(root_node, data);
            printf("In-ordered-->\n");
            inOrder(root_node);
            printf("\n");
            break;
        case 3:
            printf("Enter data to be searched-->\t");
            scanf("%d", &data);
            if (search(root_node, data) == 1)
                printf("%d is prensent in the BST.\n", data);
            else
                printf("%d is not present in the BST.\n", data);
            break;
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

void inOrder(Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left_child);
    printf("%d\t", node->data);
    inOrder(node->right_child);
}

int search(Node *root_node, int data)
{
	if (root_node == NULL )
		return 0;
	if(root_node->data == data)
		return 1;
	
	if (root_node->data < data)
	return search(root_node->right_child, data);

	return search(root_node->left_child, data);
}

Node *min_value_node(Node *node)
{
    Node *current = node;

    while (current && current->left_child != NULL)
        current = current->left_child;

    return current;
}

Node *delete_node(struct node *root_node, int data)
{
    if (root_node == NULL)
        return root_node;

    if (data < root_node->data)
        root_node->left_child = delete_node(root_node->left_child, data);

    else if (data > root_node->data)
        root_node->right_child = delete_node(root_node->right_child, data);

    else
    {
        if (root_node->left_child == NULL)
        {
            struct node *temp = root_node->right_child;
            free(root_node);
            return temp;
        }
        else if (root_node->right_child == NULL)
        {
            struct node *temp = root_node->left_child;
            free(root_node);
            return temp;
        }

        struct node *temp = min_value_node(root_node->right_child);

        root_node->data = temp->data;

        root_node->right_child = delete_node(root_node->right_child, temp->data);
    }
    return root_node;
}