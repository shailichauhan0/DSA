#include<stdio.h>
void printArray(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void bubblesort(int*A,int n)
{
    int i;
    int j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
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
    bubblesort(A,n);
    printArray(A,n);
    return 0;
}

//OPTIMIZED ONE
// #include<stdio.h>
// void printArray(int *A,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         printf("%d ",A[i]);
//     }
//     printf("\n");
// }
// void bubblesort(int*A,int n)
// {
//     int i;
//     int j;
//     int flag=0;
//     for(i=0;i<n-1;i++)
//     {
//         flag=0;
//         for(j=0;j<n-1-i;j++)
//         {
//             if(A[j]>A[j+1])
//             {
//                 int temp=A[j];
//                 A[j]=A[j+1];
//                 A[j+1]=temp;
//                 flag=1;
//             }
//         }
//         if (flag==0)
//         break;
//     }
// }
// int main(){

//     int n;
//     scanf("%d",&n);
//     int A[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&A[i]);
//     }
//     printArray(A,n);
//     bubblesort(A,n);
//     printArray(A,n);
//     return 0;
// }




