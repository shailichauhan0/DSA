#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int spaces=2*(n-1);
    for(int i=1;i<=n;i++)
    {
        //numbers
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        //space
        for(int j=1;j<=spaces;j++)
        {
            cout<<" ";
        }
        //numbers
          for(int j=i;j>=1;j--)
        {
            cout<<j;
        }
        cout<<endl;
        spaces-=2;
    }
    return 0;
}

// OutPut
// 5
// 1        1
// 12      21
// 123    321
// 1234  4321
// 1234554321