//CIRCULARLINKEDLIST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void access(node**,node**);
void display(node*);
int count(node*);
void search(node*,int);
node* reverse(node*);
node* insertbeg(node*);
node* insertend(node*);
void insertpos(node**);
node* deletebeg(node*);
node* deleteend(node*);
void deletepos(node**);
node* rotate(node*);
int detectloop(node*);

void main()
{
    node *head=NULL,*temp=NULL,*newnode=NULL;
    int ch,x,y;
    int num;
    scanf("%d",&num);
    while(1)
    {
        printf("*MENU\n");
        printf("1-for access,2 for display,3-count,4-search,5-reverse,6-insert at beg,7-insert at end,8-insert at pos,9-delete from beg,10-delete from end,11-delete from pos,12-rotate,13-detectlooporcycle");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            access(&head,&temp);
            break;
            case 2:
            display(head);
            break;
            case 3:
            y=count(head);
            printf("%d",y);
            break;
            case 4:
            search(head,num);
            break;
            case 5:
            head=reverse(head);
            break;
            case 6:
            head=insertbeg(head);
            break;
            case 7:
            head=insertend(head);
            break;
            case 8:
            insertpos(&head);
            break;
            case 9:
            head=deletebeg(head);
            break;
            case 10:
            head=deleteend(head);
            break;
            case 11:
            deletepos(&head);
            break;
            case 12:
            head=rotate(head);
            break;
            case 13:
            if(detectloop(head))
            printf("LOOP is found");
            else
            printf("Loop is not found");
            break;
            default:
            printf("Invalid choice");
            break;
        }
        printf("\nDO u want to continue");
        scanf("%d",&x);
        if(x==0)
        break;
    }
}

void access(node**head,node**temp)
{
  node*newnode=NULL;
  int ch;
  while(1)
  {newnode=(node*)malloc(sizeof(node));
  printf("Enter data");
  scanf("%d",&newnode->data);
  if(*head==NULL && *temp==NULL)
  *temp=(*head)=newnode;
  else
 {
  (*temp)->next=newnode;
  *temp=newnode;
 }
 printf("do you want to access more: 1for yes 0 for no");
 scanf("%d",&ch);
 if (ch==1)
 continue;
 if(ch==0)
   break;
}
 (*temp)->next=*head;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int count(node*head)
{
    int c=0;
    if (head==0)
    {
        printf("No node");
    }
    else
    {   
    node*temp=head;
    do
    {   //c++;
        temp=temp->next;
        c++;
    }
    while(temp!=head);
}
return c;
}

void search(node *head,int num)
{   
    if(head==NULL)
    {
        return;
    }
    struct node*temp;
    temp=head;
        do
    {   if(temp->data==num)
       { printf("successfull");
        return;
       }
        temp=temp->next;
    }  while(temp!=head);
printf("Not succssfull");

}

node* reverse(node*head)
{
    if(head==NULL)
    {
        return head;
    }
    node*prenode,*currentnode,*nextnode;
    prenode=NULL,nextnode=NULL;
    currentnode=head;
   do
    {
        nextnode=currentnode->next;
        currentnode->next=prenode;
        prenode=currentnode;
        currentnode=nextnode;
    }while(currentnode!=head);
head->next=prenode;
return prenode;
}
node* insertbeg(node*head)
{
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    if(newnode==NULL)
    {
        printf("Memory is not available");
    }
    else if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
    }
    return head;
}

node*insertend(node*head)
{
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    if(newnode==NULL)
    {
        printf("Memory is not available");
    }
    else if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    return head;
}

void insertpos(node**head)
{
        node*temp=*head,*newnode=NULL;
    int c=0;
        do
        {  c++;
           temp=temp->next;
        }while(temp!=*head);
        printf("c=%d\n",c);
    
    newnode=(node*)malloc(sizeof(node));
    int pos,i=1;
    printf("Enter position:");
    scanf("%d",&pos);
            if(pos>c||pos<0)
            {
                printf("Invalid choice");
            }
            else if(pos==1)
            {
               *head=insertbeg(*head);
            }
            else if(pos==c)
            {
                *head=insertend(*head);
            }
            else
            {
                temp=*head;
                while(i<pos-1)
                {
                    temp=temp->next;
                    i++;
                }
            printf("Enetr data u want to insert");
            scanf("%d",&newnode->data);
            newnode->next=temp->next;
            temp->next=newnode;
            }
}

node*deletebeg(node*head)
{
    if(head==NULL)
    {
        printf("Underflow");
    }
    if(head->next==head)
    { 
        free(head);
        return NULL;
    }
       node*temp=head;
       while(temp->next!=head)
       {
           temp=temp->next;
       }
       temp->next=head->next;
       node* newhead=head->next;
       free(head);
       return newhead;   
}

node*deleteend(node*head)
{
     if(head==NULL)
    {
        printf("Underflow");
    }
    if(head->next==head)
    {
        free(head);
        return NULL;
    }
    node*pre=NULL;
    node*temp=head;
    while(temp->next!=head)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=head;
    free(temp);
    return head;
}

void deletepos(node**head)
{
     node* temp,*nextnode;
    temp=*head;
     int c=0;
        do
        {  c++;
           temp=temp->next;
        }while(temp!=*head);
        printf("c=%d\n",c);
    int pos,i=1;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos>c)
    {
        printf("Invalid");
    }
    else if(pos==1)
    {
      *head=deletebeg(*head); 
    }
    else if(pos==c)
    {
        *head=insertend(*head);
    }
    else
    {
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
}

node* rotate(node*head)
{   node*temp=head,*pre=NULL;
    int c=0,k;
    printf("Enter k");
    scanf("%d",&k);
    while(c<k)
    {
        temp=temp->next;
        c++;
    }
    head=temp;
    pre=temp;
    while(pre->next!=temp)
    {
        pre=pre->next;
    }
    pre->next=NULL;
    return head;
}

int detectloop(node*head)
{
    node*temp=head,*ptr=head;
    while(temp!=NULL && ptr!=NULL &&    ptr->next!=NULL)
    {
        ptr=ptr->next;
        temp=temp->next->next;
    if(temp==ptr)
    {
        return 1;
    }
    }
    return 0;
}


