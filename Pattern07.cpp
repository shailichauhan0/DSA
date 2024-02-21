#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
//outer loop
for(int i=0;i<n;i++)
{
    //space
    for(int j=0;j<n-i-1;j++)
    {
        cout<<" ";
    }
    //stars
    for(int j=0;j<2*i+1;j++)
    {
        cout<<"*";
    }
    //space
    for(int j=0;j<n-i-1;j++)
    {
        cout<<" ";
    }
    cout<<endl;
}
}

//    OutPut
//       *
//      ***
//     *****
//    *******
//   *********