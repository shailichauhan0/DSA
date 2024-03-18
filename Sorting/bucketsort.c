#include <stdio.h>

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
 
//Implementing bucket sort 
void bucketsort(int array[], int n,int k) 
{  
    int bucket[k+1];  
 
    //Initializing buckets to zero
    for (int i = 0; i <= k; i++)  
    bucket[i] = 0;  
 
    // Pushing elements in their corresponding buckets
    for (int i = 0; i < n; i++)  
    bucket[array[i]]++;

    int j=0;  
    for (int i = 0; i <= k; i++)  
    { 
        while (bucket[i] > 0)  
        {      
            array[j++] = i;  
            bucket[i]--;   
        }  
    }  
}  

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    int k = 0;  
    // Find the maximum element in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (A[i] > k) {
            k = A[i];
        }
    }

    printArray(A, n);
    bucketsort(A, n,k);
    printArray(A, n);

    return 0;
}