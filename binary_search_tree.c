#include<stdio.h>
#include<stdlib.h>
typedef struct bstnode
{
    int data;
    struct bstnode *left, *right;
}node;
node *root = NULL;

node *insert(node *root, int value)
{
    if(root == NULL)
    {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    
}


int main()
{
    int value, option;
    while(1)
    {
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            scanf("%d",&value);
            root = insert(root, value);
            break;
        }
    }
}
