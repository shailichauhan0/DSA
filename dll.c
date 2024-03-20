//DOUBLYLINKEDLIST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node*pre;
}node;

void access(node**,node**);
void display(node*);
int count(node*);
void search(node*,int);
node*reverse(node*);
node*insertbeg(node*);
node*insertend(node*);
void insertpos(node*);
//void insertbef(node*);
void insertaft(node*);
node*deletebeg(node*);
node*deleteend(node*);
// void deletepos(node*);
// void deletebef(node*);
 void deleteaft(node*);

void main()
{
    node *head=NULL,*temp=NULL,*newnode=NULL;
    int ch,x,y;
    int num;
    scanf("%d",&num);
    while(1)
    {
        printf("*MENU\n");
        printf("1-for access,2 for display");
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
             insertpos(head);
             break;
            //  case 9:
            //  insertbef(head);
            //  break;
             case 10:
             insertaft(head);
             break;
             case 11:
             head=deletebeg(head);
             break;
             case 12:
             head=deleteend(head);
             break;
            //  case 13:
            //  deletepos(head);
            //  break;
            //  case 14:
            //  deletebef(head);
            //  break;
             case 15:
             deleteaft(head);
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
  newnode->pre=NULL;
  newnode->next=NULL;
  if(*head==NULL && *temp==NULL)
  *temp=(*head)=newnode;
  else
 {
  (*temp)->next=newnode;
  newnode->pre=*temp;
  *temp=newnode;
 }
 printf("do you want to access more: 1for yes 0 for no");
 scanf("%d",&ch);
 if (ch==1)
 continue;
 if(ch==0)
   break;
}
 (*temp)->next=NULL;
}

void display(node *head)
{node*temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        if(temp==head)
        break;
    }
}

int count (node*head)
{
     int c=0;
    node*temp = head;
    while (temp!= NULL) {
        c++;
        temp=temp->next;
    }
    return c;
}

void search(node*head,int num)
{
     if(head==NULL)
    {
        return;
    }
    struct node*temp;
    temp=head;
        while(temp!=NULL)
        {
        if(temp->data==num)
       { printf("successfull");
        return;
       }
        temp=temp->next;
    }  
printf("Not succssfull");

}

node*reverse(node*head)
{
    node* current = head;
    node* temp = NULL;

    while (current != NULL) {
        temp = current->pre;
        current->pre= current->next;
        current->next = temp;
        current = current->pre;
    }
    if (temp != NULL)
    {
        head = temp->pre;
    }
    else
    {
        head=current;
    }
return head;
}

node* insertbeg(node*head)
{
    node*newnode=NULL;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    if(newnode==NULL)
    {
        printf("Memory is not required");
        return head;
    }
    else if(head==NULL)
    {
        newnode->next=newnode->pre=NULL;
        return head;
    }
    else
    {
        node*temp=head;
        newnode->next=temp;
        temp->pre=newnode;
        newnode->pre=NULL;
        head=newnode;
        return head;
    }


}

 node* insertend(node*head)
 {
    node*newnode=NULL;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter Data");
    scanf("%d",&newnode->data);
    if(newnode==NULL)
    {
        printf("MEmory is not available");
    }
    else if(head==NULL)
    {
        newnode->pre=newnode->next=NULL;
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
        newnode->next=NULL;
    }
    return head;

 }

 void insertpos(node*head)
{
    node*newnode=NULL;
    int pos;
    printf("Enter position");
    scanf("%d",&pos);
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    if(newnode==NULL)
    {
        printf("MEmory is not available");
    }
    else if(head==NULL || pos==1)
    {
        newnode->pre=newnode->next=NULL;
        head=newnode;
    }
    else
    {
        node*temp=head;
        int c=1;
        while(c!=pos-1 && temp->next!=NULL)
        {
            temp=temp->next;
            c++;
        }
        newnode->next=temp->next;
        newnode->pre=temp;
        temp->next->pre=newnode;
        temp->next=newnode;
    }
}

//  void insertbef(node*head)
//  {
    
//  }

 void insertaft(node*head)
 {
    node*newnode=NULL;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&newnode->data);
    int pos;
    printf("Enter pos");
    scanf("%d",&pos);
    if(newnode==NULL)
    {
        printf("Memory is not available");
    }
    else
    {
    node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->pre=newnode;
    temp->next=newnode;
    newnode->pre=temp;
    }
 }

 node* deletebeg(node*head)
 {
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else{
        node*temp=head;
        head=head->next;
        head->pre=NULL;
        free(temp);
    }
    return head;

 }

 node* deleteend(node*head)
 {
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->pre->next=NULL;  //read it
        free(temp);
    }
    return head;
 }

// void deletepos(node*head)
// {

// }

// void deletebef(node*head)
// {

// }

 void deleteaft(node*head)
 {
    int item;
    printf("Enter data after which u want to delete the data");
    scanf("%d",&item);
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        node*temp=head;
        while(temp->data!=item && temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp=temp->next;
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        free(temp);

    }
    
 }
