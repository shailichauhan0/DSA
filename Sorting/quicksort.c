#include<stdio.h>
void printArray(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int partition(int A[],int low,int high)
{
    int pivot=A[low];
    int start=low;
    int end=high;
    int temp,t;
    while(start<end)
    {
        while(A[start]<=pivot)
        {
            start++;
        }
        while(A[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            temp=A[start];
            A[start]=A[end];
            A[end]=temp;
        }
    }
    t=A[low];
    A[low]=A[end];
    A[end]=t;
    return end;
}


/************High as pivot Element*************/ 
// int partition(int arr[],int low,int high)
// {
//    //For random no as pivot element.
//    // int x=rand()%(high-low+1)+low;
//    // swap(arr[x],arr[high]);
//   int pivot=arr[high];
//   int i=(low-1);
//   for(int j=low;j<=high;j++)
//   {
//     if(arr[j]<pivot)
//     {
//       i++;
//       swap(arr[i],arr[j]);
//     }
//   }
//   swap(arr[i+1],arr[high]);
//   return (i+1);
// }

void quicksort(int A[],int low,int high)
{  
    if(low<high)
    {
        int partitioni=partition(A,low,high);
        quicksort(A,low,partitioni-1);//Sort Left Subarray
        quicksort(A,partitioni+1,high);//Sort Right Subarray
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
    quicksort(A,0,n-1);
    printArray(A,n);
    return 0;
}