#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree = NULL;

struct node *insertElement(struct node *, int);
void preOrderTraversal(struct node *);
void inOrderTraversal(struct node *);
void postOrderTraversal(struct node *);

int main()
{
    int val, n;
    // struct node *ptr;
    printf("How many numbers--> ");
    scanf("%d", &n);
    printf("Enter %d numbers-->", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        tree = insertElement(tree, val);
    }
    printf("Preorder traversal result-->\n");
    preOrderTraversal(tree);
    printf("\nInorder traversal result-->\n");
    inOrderTraversal(tree);
    printf("\nPostorder traversal result-->\n");
    postOrderTraversal(tree);
    printf("\n");
}
struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}
void preOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
}
void inOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inOrderTraversal(tree->left);
        printf("%d\t", tree->data);
        inOrderTraversal(tree->right);
    }
}

void postOrderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}