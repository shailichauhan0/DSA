#include<stdio.h>

void printArray(int *A, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void countsort(int *A, int n, int k) {
    int max = k + 1;  // Assuming k is the maximum element in the array
    int count[max];
    int B[n];

    // Initialize count array
    for (int i = 0; i < max; i++) {
        count[i] = 0;
    }

    // Count occurrences of each element in the input array
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Modify count array to store actual position of the elements
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        B[--count[A[i]]] = A[i];
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    int k = 0;  // Assuming k is the maximum element in the array

    // Find the maximum element in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (A[i] > k) {
            k = A[i];
        }
    }

    printArray(A, n);
    countsort(A, n, k);
    printArray(A, n);

    return 0;
}
