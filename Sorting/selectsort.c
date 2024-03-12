#include<stdio.h>
void printArray(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void selectsort(int*A,int n)
{
    int i;
    int j;
    int temp,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
    }
}
int main(){

    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printArray(A,n);
    selectsort(A,n);
    printArray(A,n);
    return 0;
}