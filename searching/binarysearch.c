// Binary Search in C

#include <stdio.h>

int binarySearch(int a[], int data, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (a[mid] == data)
      return mid;

    // Search the left half
    if (a[mid] > data)
      return binarySearch(a, data, low, mid - 1);

    // Search the right half
    return binarySearch(a,data, mid + 1, high);
  }
  return -1;
}

int main() {
    int n;
    int i;
    printf("Enter array size");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int data;
    printf("Enter data to want to search");
    scanf("%d",&data);
  int x= binarySearch(a, data, 0, n - 1);
  if (x== -1)
    printf("Not found");
  else
    printf("Element is found at index %d", x);
}