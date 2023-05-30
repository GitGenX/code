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
// struct node *insert(struct node *, int);
void *preorder(struct node *);
void *inorder(struct node *);
void *postorder(struct node *);
struct node *search(struct node *,int );

void main()
{
    int size, num, ch;

    printf("Enter the size:");
    scanf("%d", &size);
    printf("Enter %d numbers:", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &num);
        root = insertelement(root, num);
    }
    printf("Preorder traversal result-->\n");
    preorder(root);
    printf("\nInorder traversal result-->\n");
    inorder(root);
    printf("\nPostorder traversal result-->\n");
    postorder(root);
    printf("\n");
    do
    {
        printf("1. Delete Element\n");
        printf("2. Search Element\n");
        printf("3. Exit\n");

        printf("Enter your choice :\t");
        scanf("%d", &ch);

        switch (ch)
        {
        /*case 1:
            printf("Enter data to be deleted-->\t");
            scanf("%d", &data);
            root_node = delete_node(root_node, data);
            printf("In-ordered-->\n");
            inOrder(root_node);
            printf("\n");
            break;*/
        case 2:
            printf("Enter data to be searched-->\t");
            scanf("%d", &num);
            if (search(root, num) == 1)
                printf("%d is prensent in the BST.\n", num);
            else
                printf("%d is not present in the BST.\n", num);
            break;
        case 3:
            break;
        default:
            printf("Please enter correct option!!\n\n");
            break;
        }
    } while (ch != 3);
}
/*
struct node *insert(struct node *root, int num)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->left = NULL;
    ptr->right = NULL;

    if (root == NULL)
    {
        root = ptr;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = root;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (nodeptr->data > num)
            {
                nodeptr = nodeptr->left;
            }
            else
                nodeptr = nodeptr->right;
        }
        if (parentptr->data > num)
        {
            parentptr->left = ptr;
        }
        else
            parentptr->right = ptr;
    }
    return root;
}
*/
struct node *newnode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insertelement(struct node *root, int num)
{
    if (root == NULL)
    {
        return newnode(num);
    }
    if (num < root->data)
    {
        root->left = insertelement(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = insertelement(root->right, num);
    }
    return root;
}

void *preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void *inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void *postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}
struct node *search(struct node *root,int num)
{
    if (root==NULL || root->data==num)
        return root;
    if(root->data<num)
        return search(root->right,num);
    return search(root->left,num);
}