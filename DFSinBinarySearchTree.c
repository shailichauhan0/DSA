#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
int data;
struct bst *left,*right;
}bst;

void insertdata(bst**,int);
void preorder(bst*);
void inorder(bst*);
void postorder(bst*);
void main()
{
    bst*root=NULL;
    int ch,x;
    while(1)
    {
        printf("\n1.insert data\n2.Pre order\n3.In order\n4.post order\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter data");
                    scanf("%d",&x);
                    insertdata(&root,x);
                    break;
            case 2:preorder(root);
                    break;
            case 3:inorder(root);
                    break;
            case 4:postorder(root);
                    break;
            case 5:exit(0);
        }
    }
}
void insertdata(bst **rt,int x)
{
    if(*rt==NULL)
    {   bst*p=(bst*)malloc(sizeof(bst));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        *rt=p;
        return ;
    }
    else if((*rt)->data>x)
    {
        insertdata(&(*rt)->left,x);
    }
    else if((*rt)->data<x)
    {
        insertdata(&(*rt)->right,x);
    }
    else
        printf("invalid choice");
}

void preorder(bst *rt)
{
    if(rt==NULL)
    {
        return;
    }
    else
    {
        printf("%d\t",rt->data);
        preorder(rt->left);
        preorder(rt->right);
    }
}
void inorder(bst *rt)
{
    if(rt==NULL)
    {
        return;
    }
    else
    {
        inorder(rt->left);
        printf("%d\t",rt->data);
        inorder(rt->right);
    }
}

void postorder(bst *rt)
{
    if(rt==NULL)
    {
        return;
    }
    else
    {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d\t",rt->data);
    }
}
