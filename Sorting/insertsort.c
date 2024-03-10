#include<stdio.h>
void printArray(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void insertsort(int*A,int n)
{
    int i;
    int j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0 && A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
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
    insertsort(A,n);
    printArray(A,n);
    return 0;
}