#include <stdio.h>

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void heapify(int *A, int n, int i) {
    int temp;
    int largest = i;
    int l = 2 * i ;  // Note: index of left child
    int r = 2 * i + 1;  // Note: index of right child

    if (l < n && A[l] > A[largest]) {
        largest = l;
    }
    if (r < n && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, n, largest);
    }
}

void heapsort(int *A, int n) {
    int temp;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }

    // One by one extract an element from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        // Call max heapify on the reduced heap
        heapify(A, i, 0);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, n);

    heapsort(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
