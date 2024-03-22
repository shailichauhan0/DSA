//Stack using array
#include<stdio.h>
#define N 5

void push(int *a,int *top);
void pop(int *a,int *top);
void display(int *a,int *top );
void peek(int *a,int *top);
int  isempty(int *top);
int  isfull(int *top);

void main()
{
    int a[N],ch,choice,t=-1;
    int *top;
    top=&t;
    do
    {
        printf("**MENU**");
        printf("Enter 1-for push,2-pop,3-display,4-peek");
        printf("Enter Choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push(a,top);
            break;
            case 2:
            pop(a,top);
            break;
            case 3:
            peek(a,top);
            break;
            case 4:
            display(a,top);
            break;
            case 5:
            if(isempty(top))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
            case 6:
            if(isfull(top))
                printf("stack is full\n");
            else
                printf("stack is not full\n");
            break;
            default:
            printf("Invalid ");
        }
        printf("\nenter 0 to exit:");
        scanf("%d",&choice);
        
    }while(choice!=0);
    return ;
}

int isempty(int *top)
{
    if(*top==-1)
    {
        return 1;
    }
    return 0;
}

int isfull(int *top)
{
    if(*top==N-1)
        return 1;
    return 0;
}

 void push(int *a,int *top)
{
    if(isfull(top))
    {
        printf("Stack overflow\n");
        return ;
    }
    else
    {
        int n;
        printf("Enter Element");
        scanf("%d",&n);
        *top+=1;
        a[*top]=n;
    }
}


void pop(int *a,int *top)
{
    if(isempty(top))
    {
        printf("Stack underflow\n");
        return ;
    }
    else
    {
        printf("%d",a[*top]);
        *top--;
    }
}

void peek(int *a,int *top)
{
    if(isempty(top))
    {
        printf("Stack Underflow\n");
        return ;
    }
    else
    {
        printf("Last element in stack is %d \n",a[*top]);
    }
}

void display(int *a,int *top)
{
    if(*top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
    int i;
    for(i=*top;i>=0;i--)
    {
       printf("%d\n",a[i]);
}
}
}


//Stack using Linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}node;

void push(node**top,int value)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    if(newnode==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    else
    {
    newnode->next=*top;
    *top=newnode;
    }
   
}


void display(node**top)
{   
    if(*top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
    node*temp=*top;
    while(temp->next!=0)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
    }
}

void pop(node**top)
{
 if(*top==NULL)
 {
     printf("Stack is empty");
 return;
 }
 else
 {
 node*temp=*top;
 *top=temp->next;
 free(temp);
 }
 
}

void peek(node**top)
{
    node*temp=*top;
    if(temp==0)
    {
        printf("Stack is empty");
        return;
    }
    printf("Element at the top of linked list is %d",temp->data);
}


int main()
{
    node*top=NULL;
    int ch,n;
    while(1)
    {
        printf("\nEnter 1-push,2-pop,3-display,4-peek");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter element u want to insert");
            scanf("%d",&n);
            push(&top,n);
            break;
            
            case 2:
            pop(&top);
            break;
            
            case 3:
            display(&top);
            break;
            
            case 4:
            peek(&top);
            break;
            
            default:
            printf("Invlaid");
            break;
            
        }
    }
return 0;
}
