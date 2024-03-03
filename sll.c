//SINGLELINKEDLIST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}node;

void access(node**,node**);
void display(node*);
void ssearch(int,node*);
void unsearch(int,node*);
int count(node*);
void tsort(node*);
node* reverse(node*);
node* deletebeg(node*);
node* deleteend(node*);
void deletepos(node*);
void deletebef(node*);
node* deleteaft(node*);
node* insertbeg(node*);
node* insertend(node*);
void insertpos(node*);
node* insertbef(node*);
node* insertaft(node*);
void middle(node*, int);
void last(node*,int);
void deletelast(node*);
void deletemiddle(node*,int);
void deleteduplicate(node*);
node*removenthfromlast(node*);
node*removeelements(node*);
int ispalindrome(node*);
//node*mergetwosortedlists(node**,node**);
//node* intersectionoftwoll(node*,node*);




void main()
{
    node *head=NULL,*temp=NULL,*first=NULL,*newnode=NULL;
    int ch,x,y;
    int num;
    printf("Enter data which u want to search: ");
    scanf("%d",&num);
    while(1)
    {
        printf("***MENU***");
        printf("\nEnter 1-access,2-display,3-sort search,4-unsorted search,5-count,6-tsort,7-reverse,8-delete from beg,9-delete from end,10-delete from pos,11-delete before pos,12-delete after pos,13-insert at beg,14-insert at end,15-insert at pos,16-insert before pos,17-insert after pos,18-middle element,19-nthfromlast,20-deletelastoccurance,21-deletemiddle,22-deleteduplicate,23-removenthfromlast,24-removeelment,25-,26-mergetwosortedlist,27-intersection of two ll,28-");
        printf("\nEnter Choice: ");
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
            ssearch(num,head);
            break;
            case 4:
            unsearch(num,head);
            case 5:
            y=count(head);
            printf("Total count is %d",y);
            break;
            case 6:
            tsort(head);
            break;
            case 7:
            head=reverse(head);
            break;
            case 8:
            head=deletebeg(head);
            break;
            case 9:
            head=deleteend(head);
            break;
            case 10:
            deletepos(head);
            break;
            case 11:
            deletebef(head);
            break;
            case 12:
            head=deleteaft(head);
            break;
            case 13:
            head=insertbeg(head);
            break;
            case 14:
            head=insertend(head);
            break;
            case 15:
            insertpos(head);
            break;
            case 16:
            head=insertbef(head);
            break;
            case 17:
            head=insertaft(head);
            break;
            case 18:
            middle(head,y);
            break;
            case 19:
            last(head,y);
            break;
            case 20:
            deletelast(head);
            break;
            case 21:
            deletemiddle(head,y);
            break;
            case 22:
            deleteduplicate(head);
            break;
            case 23:
            head=removenthfromlast(head);
            break;
            case 24:
            head=removeelements(head);
            break;
            case 25:
            if(ispalindrome(head))
            printf("True");
            else
            printf("False");
            break;
            //case 26:
            //head=mergetwosortedlists(&head,&head1);
            //break;
            //case 27:
            //head=intersectionoftwoll(head,head1);
            //break;
            
            default:
            printf("Inalid Choice");
            break;
        }
        printf("\nDo You want to continue");
        scanf("%d",&x);
        if(x!=0)
        continue;
        if(x==0)
        break;
    }
}

void access(node**head,node**temp)
{
    node*newnode=NULL;
    int choice;
    while(1)
    {
    newnode=(node*)malloc(sizeof(node));
    printf("Enter data for node: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(*head==NULL && *temp==NULL)
        {
          (*temp)=*head=newnode;
        }
    else
        {
            (*temp)->next=newnode;
            *temp=newnode;
        }
    printf("DO u want to access more:");
    scanf("%d",&choice);
    if(choice==0)
    break;
    else
    continue;
    }
    (*temp)->next=NULL;
}

void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void ssearch(int num,node*head)
{
    node*temp=head;
    while(temp!=NULL && (temp->data)>num)
    {
        if(temp->data==num)
        {
            printf("Successfull search");
            return;
        }
        temp=temp->next;
    }
    printf("Not Successfull search");
}

void unsearch(int num,node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            printf("Successfully search");
            return;
        }
        temp=temp->next;
    }
    printf("Not Successfull search");
}

int count(node*head)
{
    node*temp=head;
    int c;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

void tsort(node*first)
{
    node*temp,*head;
    head=first;
    while(first!=NULL)
    {
        temp=first->next;
        while(temp!=NULL)
        {
            if((first->data)>(temp->data))
            {
                int t;
                t=temp->data;
                temp->data=first->data;
                first->data=t;
            }
            temp=temp->next;
        }
        first=first->next;
    }
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
} 

node* reverse(node*head)
{
    node*prenode,*current,*nextnode;
    prenode=NULL;
    current=nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        current->next=prenode;
        prenode=current;
        current=nextnode;
    }
    head=prenode;
    return prenode;
}

node* deletebeg(node*head)
{
  node*temp;
  temp=head;
  if(head==NULL)
  {
    printf("List is empty");
  }  
  else
  {
    head=head->next;
    printf("Deleted data is %d ",temp->data);
    free(temp);
    return head;
  }
}

node* deleteend(node*head)
{
    node*temp=head;
    node*prenode=NULL;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp->next!=NULL)
        {
            prenode=temp;
            temp=temp->next;
        }
        prenode->next=NULL;
        printf("Deleted data is %d",temp->data);
        free(temp);
        return head;
    }
}

void deletepos(node*head)
{
    node*temp=head,*nextnode;
    int pos,i=1;
    printf("Enter position:");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);   
}

void deletebef(node*head)
{
    int k;
    printf("Enter position before which u want to delete\n");
    scanf("%d",&k);
    if (head==NULL && head->data==k)
    {
        return;
    }
    else if(head->next->data==k)
    {
        head=head->next;
        return;
    }
    else
    {
       node *prenode=NULL;
       node*temp=head;
       while(temp->next!=NULL && temp->next->data!=k)
       {
        prenode=temp;
        temp=temp->next;
       }
       if(temp->next!=NULL)
       {
         prenode->next=temp->next;
       }
       return ;
    }
}

node* deleteaft(node*head)
{
    int k;
    printf("Enter the data after which u want to delete");
    scanf("%d",&k);
    node*p1=NULL,*p2=NULL;
    p1=head;
    while(p1->next!=NULL)
    {
        if(p1->data==k)
        {
            p2=p1->next;
            p1->next=p2->next;
            free(p2);
        }
        p1=p1->next;
    }
    return head;   
}

node* insertbeg(node*head)
{
    node*newnode=NULL;
    newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("MEmory is not available");
    }
    else
    {
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    }
    return head;
}

node*insertend(node*head)
{
    node*newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("Memory is not available");
    }
    else
    {
        printf("Enter data:");
        scanf("%d",&newnode->data);
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    }
    return head;
}

void insertpos(node*head)
{ node*temp=head,*newnode=NULL;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    printf("c=%d",c);

    newnode=(node*)malloc(sizeof(node));
    int i=1,pos;
    printf("Enter Position at which u want to insert");
    scanf("%d",&pos);
    if(newnode==NULL)
    {
        printf("Memory is not available");
        return;
    }
    if(pos>c)
    {
        printf("Invalid Position");
    }
    else
    {   temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        printf("Enter data");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

node* insertbef(node*head)
{
    int value;
    printf("Enter the value before which u want to insert");
    scanf("%d",&value);
    node*newnode=(node*)malloc(sizeof(node*));
    printf("Enter the the data u want to insert");
    scanf("%d",&newnode->data);
    if(newnode==NULL)
    {
        printf("MEmory is not availabe");
    }
    else
    { node*temp=head,*pre=head;
        while(temp!=NULL && temp->data!=value)
        {
            pre=temp;
            temp=temp->next;
        }
        newnode->next=pre->next;
        pre->next=newnode;   
    }
    return head;
}

node*insertaft(node*head)
{
    int value;
    printf("Enter the value after which u want to insert the data");
    scanf("%d",&value);
    node*newnode=(node*)malloc(sizeof(node));
    printf("Enter the data u want to insert");
    scanf("%d",&newnode->data);
    if(newnode==NULL)
    {
        printf("MEmory is not available");
    }
    else
    {
        node*temp=head;
    while(temp->data!=value && temp!=NULL)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
    return head;
}

void middle(node*head, int y)
{
  node *temp = head;
  if(y%2!=0)
  {
    for (int i = 0; i<y/2; i++)
    { 
      temp = temp->next;
    }
  printf ("%d", temp->data);
  }
  if(y%2==0)
  {
  for (int i = 0; i<y/2; i++)
    {
      temp = temp->next;
    }
  printf ("%d", temp->data);  
}
}

void last (node * head, int y)
{
  int n;
  scanf ("%d", &n);
  if (n > y)
    {
      return;
    }
  node *temp = head;
  for (int i = 0; i < y - n; i++)
    {
      temp = temp->next;
    }
  printf ("%d", temp->data);
}

//deletelastoccurance
void deletelast(node*head)
{
    node*temp=head,*ptr=NULL;
    int x;
    scanf("%d",&x);
    while(temp!=NULL)
    {
    if(temp->data==x)
    {
        ptr=temp;
    }
     temp=temp->next;
    }
    //if last occ is last node
    if(ptr!=NULL && ptr->next==NULL)
    {
        temp=head;
        while(temp->next!=ptr)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    //if the last occ not is the last node
    if(ptr!=NULL && ptr->next!=NULL)
    {
        ptr->data=ptr->next->data;
        temp=ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
    }
   
}

void deletemiddle(node*head, int y)
{
  node *temp = head;
  node*pre=head;
  if(y%2!=0)
  {
    for (int i = 0; i<y/2; i++)
    { 
      pre=temp;
      temp = temp->next;
    }
  printf ("%d", temp->data);
  pre->next=temp->next;
  free(temp);
  
  }
  if(y%2==0)
  {
  for (int i = 0; i<y/2+1; i++)
    {
      pre=temp;
      temp = temp->next;
    }
  printf ("%d", temp->data);  
  pre->next=temp->next;
  free(temp);
}
}

void deleteduplicate(node* head) {
    node* temp = head;

    while (temp != NULL) {
        node* current = temp;

        while (current->next != NULL) {
            if (current->next->data == temp->data) {
                node* duplicate = current->next;
                current->next = duplicate->next;
                free(duplicate);
            } else {
                current = current->next;
            }
        }

        temp = temp->next;
    }
}

node* removenthfromlast(node* head)
{
    int n;
    scanf("%d",&n);
    node*temp=head;
    int c=0,i=1;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    c=c-n;
    if(c==0)
    {
      head=head->next;
      return head;
    }
    temp=head;
    while(i<c)
    {
        i++;
        temp=temp->next;
    }
        temp->next=temp->next->next;
        return head;
}

node* removeelements(node* head){
    int val;
    scanf("%d",&val);
    node*temp=head;
    while(temp!=NULL)
    {
        if(head==NULL)
        return NULL;
        else if(head->data==val)
        {
            head=head->next;
        }
        else if (temp->next==NULL)
        return head;
        else
        {
        if((temp->next)->data==val)
        temp->next=temp->next->next;
        else
        temp=temp->next;
        }
    }
    return head;
}

int ispalindrome(node* head){
node *h2=NULL,*temp,*p,*ptr=head;
int flag;
while(ptr!=NULL)
{
   p=(node*)malloc(sizeof(node));
   p->data=ptr->data;
    p->next=h2;
    h2=p;
    ptr=ptr->next;
}
while(head!=NULL)
{
    if(head->data==h2->data)
    flag=1;
    else
    {flag=0;
    break;}
    head=head->next;
    h2=h2->next;
}
if(flag==1)
return 1;
else
return 0;
}

// node*mergetwosortedlists(node**head,node*head1){
//     if(head==NULL)
//     return head1;
//     if(head1==NULL)
//     return head;

//     node*mergedList;
//     node* temp1=head;
//     node* temp2=head1;

//     if(temp1->data <= temp2->data){
//         mergedList=temp1;
//         temp1=temp1->next;
//     }
//     else
//     {
//          mergedList=temp2;
//         temp2=temp2->next;
//     }

//     node*current=mergedList;
//     while(temp1!=NULL && temp2!=NULL)
//     {
//     if(temp1->data <= temp2->data){
//         current->next=temp1;
//         temp1=temp1->next;
//     }
//     else
//     {
//         current->next=temp2;
//         temp2=temp2->next;
//     }
//     current=current->next;
//     }

//     if(temp1!=NULL)
//     {
//         current->next=temp1;
//     }
//     else
//     {
//         current->next=temp2;
//     }
//     return mergedList;
// }

/*
node* intersectionoftwoll(node *head,node *head1) {
    node *temp1=head,*temp2=head1;
    while(head!=NULL)
    {
        temp2=head1;
        while(temp2!=NULL)
        {
            if(temp2==head)
            return temp2;
            else
            temp2=temp2->next;
        }
        head=head->next;
    }
    return head;
}
*/







