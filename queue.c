//Queue using array
#include<stdio.h>
#include<stdlib.h>
#define max 5
int isempty(int *queue,int rear)
{
    if(rear==-1)
        return 1;
    return 0;
}

int isfull(int *queue,int rear)
{
    if(rear==(max-1))
        return 1;
    return 0;
}

void pfront(int *queue,int front,int rear)
{
    if(isempty(queue,rear))
    {
        printf("Queue is empty\n");
        return ;
    }
    printf("Element at front is: %d\n",queue[front]);
}

void prear(int *queue,int rear)
{
    if(isempty(queue,rear))
    {
        printf("Queue is empty\n");
        return ;
    }
    printf("Element at rear is: %d\n",queue[rear]);
}

void display(int *queue,int front,int rear)
{
    if(isempty(queue,rear))
    {
        printf("queue is empty\n");
        return ;
    }
    for(;front<=rear;front++)
    {
        printf("%d",queue[front]);
    }
    printf("\n");
}

int enque(int *queue,int front,int rear)
{
    if (isfull(queue,rear))
    {
        printf("Queue is full\n");
        return ;
    }
    int el;
    printf("Enter element to add:");
    scanf("%d",&el);
    queue[++rear]=el;
    return rear;
}

int deque(int *queue,int front,int rear)
{
    if(isempty(queue,rear))
    {
        printf("Queue is empty\n");
        return front;
    }
    return ++front;
}

int main()
{
    int queue[max],front=-1,rear=-1,ch;
    do
    {
        printf("**MENU**");
        printf("Enter 1-enque,2-deque,3-rear,4-front,5-display,6-isempty,7-isfull");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
            rear=enque(queue,front,rear);
            if(rear!=-1 && front ==-1)
            {
                front=rear-1;
            }
            break;
            }
            case 2:
            {
                front=deque(queue,front,rear);
                if(front>rear)
                {
                    front =rear=-1;
                }
            
            break;
            }
            
            case 3:
            {
                prear(queue,rear);
                break;
            }
            
            case 4:
            {
                pfront(queue,front,rear);
                break;
            }
            
            case 5:
            {
                display(queue,front,rear);
                break;
            }
            
            case 6:
            {
                if(isempty(queue,rear))
                printf("Queue is empty\n");
                else
                printf("queue is not empty\n");
                break;
            }
            
            case 7:
            {
                if(isfull(queue,rear))
                printf("Queue is full\n");
                else
                printf("Queue is not full\n");
                break;
            }
            
            case 8:
            {
                exit(0);
            }
            
            default:
            printf("Invalid Choice\n");
        }
        
    }while(1);
return 0;
}

//Queue Using Linked List
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}Q;

void Insert (Q** FRONT,Q** REAR)
{
    Q* temp;
    temp=(Q*) malloc(sizeof(Q*));

    if(temp == NULL)
    {
        printf("Stack is empty \n");   
    }
    else if(*REAR== NULL)
    {
        printf("Enter info\n");
        scanf("%d",&temp->info);
        temp->next=NULL;
        *FRONT=temp;
        *REAR=temp;
    }
    else
    {  
        printf("Enter info \n");
        scanf("%d",&temp->info);
        (*REAR)->next = temp;
        temp->next = NULL;
        *REAR = temp;
    }
}

void dequeue(Q** FRONT , Q** REAR)
{
    if(*FRONT == NULL)
    {
        printf("Under flow\n");
    }
    else
    {
        Q* p =*FRONT;
        *FRONT=p->next;
        printf("Deleted elem id %d \n",p->info);
        free(p);
    }
}

void DISPLAY (Q* FRONT ,Q* REAR)
{
    if(FRONT==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {    
        Q* p;
        p=FRONT;
        while(p!= NULL)
        {
            printf("%d\n",p->info);
            p=p->next;
        }
    }
}

int main ()
{
    Q* FRONT = NULL;
    Q* REAR = NULL;
    int ch;
    do
    {
        printf("Enter choice \n 1 - for push \n 2 - for pop \n 3 - for display\n ");
        scanf("%d",&ch); 
        switch(ch)
        {
            case 1 :
             Insert (&FRONT , &REAR);
            break;
            case 2 :
             dequeue (&FRONT,&REAR);
            break;
            case 3 :
             DISPLAY(FRONT,REAR);
            break;
            default:
            printf("wrong choice \n");
            exit(0);
        }
    }
    while(1);
return 0;
}

