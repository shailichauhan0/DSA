#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int pos)
{
    int B[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        B[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = B[i];
}

void radixsort(int arr[], int n)
{
    int max= getMax(arr, n);
    for (int pos = 1; max / pos > 0; pos*= 10)
        countSort(arr, n, pos);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    radixsort(arr, n);
    printArray(arr, n);
    return 0;
}
