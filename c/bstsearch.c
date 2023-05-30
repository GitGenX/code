#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *newnode(int);
struct node *insertelement(struct node *, int);
struct node *searchelement(struct node *, int);
struct node *minValuenode(struct node *);
struct node *deleteelement(struct node *, int);
void *inorder(struct node *);

int main()
{
    int num, ch;
    do
    {
        printf("1.insert the element:\n");
        printf("2.search the element:\n");
        printf("3.delete the element:\n");

        printf("Enter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data to be inserted-->\t");
            scanf("%d", &num);
            root = insertelement(root, num);
            printf("Inorder->");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Enter data to be searched-->\t");
            scanf("%d", &num);
            if (searchelement(root, num) == 1)
                printf("%d is prensent in the BST.\n", num);
            else
                printf("%d is not present in the BST.\n", num);
            break;
        case 3:
            printf("Enter the elemenyt has to be deleted:\n");
            scanf("%d", &num);
            root = deleteelement(root, num);
            printf("Inorder->");
            inorder(root);
            printf("\n");
        default:
            break;
        }
    } while (ch != 4);
}

struct node *newnode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insertelement(struct node *root, int value)
{
    if (root == NULL)
    {
        return newnode(root);
    }
    if (root->data < value)
    {
        root->right = insertelement(root->right, value);
    }
    else
        root->left = insertelement(root->left, value);
}

struct node *searchelement(struct node *root, int num)
{
    if (root == NULL || root->data == num)
        return root;
    if (root->data < num)
        return searchelement(root->right, num);
    else
        return searchelement(root->left, num);
}

struct node *deleteelement(struct node *root, int num)
{
    if (root == NULL)
    {
        return root;
    }
    if (num < root->data)
    {
        root->left = deleteelement(root->left, num);
    }
    else if (num > root->data)
        root->right = deleteelement(root->right, num);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValuenode(root->right);
        root->data = temp->data;
        root->right = deleteelement(root->right, temp->data);
    }
}
struct node *minValuenode(struct node *root)
{
    struct node *current = root;

    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
/*void *inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}*/
void *inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}