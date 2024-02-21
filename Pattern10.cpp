#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
//outer loop
for(int i=1;i<=n;i++)
{
    //space
    for(int j=1;j<=n-i;j++)
    {
        cout<<" ";
    }
    //stars
    for(int j=1;j<=2*i-1;j++)
    {
        cout<<"*";
    }
    cout<<endl;
}
//outer loop
for(int i=n-1;i>=1;i--)
{
    //space
    for(int j=1;j<=n-i;j++)
    {
        cout<<" ";
    }
    //stars
    for(int j=1;j<=2*i-1;j++)
    {
        cout<<"*";
    }
    cout<<endl;
}
return 0;
}


//OutPut
// 4
//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *

