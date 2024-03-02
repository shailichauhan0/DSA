#include<stdio.h>
int main(){
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
    for(i=0;i<n;i++)
    {
        if(a[i]==data)
        {
            printf("%d is found at %d",data,i+1);
            break;
        }
    }
    if(i==n)
    {
        printf("%d is not found",data);
    }
    return 0;
}