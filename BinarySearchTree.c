#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
int data;
struct bst *lf,*rg;
}bst;
void insertdata(bst**,int);
void count(bst*,int*);
void leacount(bst*,int*);
void lcount(bst*,int*);
void rcount(bst*,int*);
void bcount(bst*,int*);
void maxi(bst*,int*);
void mini(bst*,int*);
// void del(bst*,int*);
void main()
{
    bst*root=NULL;
    int ch,x,c=0,leac=0,lc=0,rc=0,bc=0;
    while(1)
    {
        printf("enter data");
        scanf("%d",&x);
        insertdata(&root,x);
        printf("do you want to continue 0 or 1");
        scanf("%d",&x);
        if(x==0)
            break;
    }
    int min=root->data,max=root->data;

    while(1)
    {
         printf("1Nodes count.\n2.Leaf nodes count\n3.Count only with left node\n4.Count only with right node\n5.Nodes with both children\n6.Max node\n7.Min Node\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: count(root,&c);
                    printf("total no of nodes are %d\n",c);
                    c=0;
                    break;
            case 2:leacount(root,&leac);
                    printf("total no of leaf nodes are %d\n",leac);
                    leac=0;
                    break;
            case 3:lcount(root,&lc);
                    printf("total no of nodes who has only left child are %d\n",lc);
                    lc=0;
                    break;
            case 4:rcount(root,&rc);
                    printf("total no of nodes who has only right child are %d\n",rc);
                    rc=0;
                    break;
            case 5:bcount(root,&bc);
                    printf("total no of nodes who has both child are %d\n",bc);
                    bc=0;
                    break;
            case 6:maxi(root,&max);
                    printf("maximum node of tree is  %d\n",max);
                    break;
            case 7:mini(root,&min);
                    printf("minimum node of tree is %d\n",min);
                    break;
            // case 8:del(root,)

            case 8:exit(0);
            default:"Invalid choice";
        }
    }
}
void insertdata(bst **rt,int x)
{
    if(*rt==NULL)
    {   bst*p=(bst*)malloc(sizeof(bst));
        p->data=x;
        p->lf=NULL;
        p->rg=NULL;
        *rt=p;
        return ;
    }
    else if((*rt)->data>x)
    {
        insertdata(&(*rt)->lf,x);
    }
    else if((*rt)->data<x)
    {
        insertdata(&(*rt)->rg,x);
    }
    else
        printf("invalid choice\n");
}
void count(bst *rt,int *c)
{
    if(rt!=NULL)
    {
        (*c)++;
        count(rt->lf,c);
        count(rt->rg,c);
    }
    else
        return;
}
void leacount(bst *rt,int *c)
{
    if(rt!=NULL)
    {
      if(rt->lf==NULL &&rt->rg==NULL)
        (*c)++;
         leacount(rt->lf,c);
        leacount(rt->rg,c);
    }
}
void lcount(bst *rt,int *c)
{
    if(rt!=NULL)
    {
        if( rt->rg==NULL &&rt->lf!=NULL)
        (*c)++;
         lcount(rt->lf,c);
        lcount(rt->rg,c);
    }
}
void rcount(bst *rt,int *c)
{
    if(rt!=NULL)
       {
        if(rt->lf==NULL&&rt->rg!=NULL)
        (*c)++;
         rcount(rt->lf,c);
        rcount(rt->rg,c);
       }
}
void bcount(bst *rt,int *c)
{
    if(rt!=NULL)
       {
        if(rt->lf!=NULL && rt->rg!=NULL)
        {(*c)++;
        }
         bcount(rt->lf,c);
        bcount(rt->rg,c);
       }
    else return;
}

void maxi(bst*rt,int *max)
{
   if(rt!=NULL)
    {if(*max<rt->data)
        *max=rt->data;
        maxi(rt->lf,max);
        maxi(rt->rg,max);
    }

}
void mini(bst*rt,int *min)
{
   if(rt!=NULL)
    {if(*min>rt->data)
        *min=rt->data;
        mini(rt->lf,min);
        mini(rt->rg,min);
    }

}
