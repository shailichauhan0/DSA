#include<stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    //Calculating the size of the temporary array B
    int s=high-low+1;
    int B[s];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
  int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printArray(A, n);
    mergeSort(A, 0, n-1);
    printArray(A, n);
    return 0;
}

//For string
// #include<stdio.h>
// #include<string.h>
// void printArray(char *A, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%c ", A[i]);
//     }
//     printf("\n");
// }

// void merge(char A[], int mid, int low, int high)
// {
//     int i, j, k;
//     i = low;
//     j = mid + 1;
//     k = low;

//     //Calculating the size of the temporary array B
//     int s=high-low+1;
//     char B[s];

//     while (i <= mid && j <= high)
//     {
//         if (A[i] < A[j])
//         {
//             B[k] = A[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             B[k] = A[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         B[k] = A[i];
//         k++;
//         i++;
//     }
//     while (j <= high)
//     {
//         B[k] = A[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }
    
// }

// void mergeSort(char A[], int low, int high){
//     int mid; 
//     if(low<high){
//         mid = (low + high) /2;
//         mergeSort(A, low, mid);
//         mergeSort(A, mid+1, high);
//         merge(A, mid, low, high);
//     }
// }

// int main()
// {
//   char A[100];
//     scanf("%s", A);
//     printf("Before: ");
//     printArray(A, strlen(A));
//     mergeSort(A, 0, strlen(A) - 1);
//     printf("After: ");
//     printArray(A, strlen(A));
//     return 0;
// }