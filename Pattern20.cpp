#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s=0;
    //For first half
    for(int i=0;i<n;i++)
    {
        //Stars
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }

        //Spaces
        for(int j=0;j<s;j++)
        {
            cout<<" ";
        }

        //Stars
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        s +=2;
        cout<<endl;
    }

    //For Second Half
    s=2*n-2;
    for(int i=1;i<=n;i++)
    {
        //Stars
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }

        //Spaces
        for(int j=0;j<s;j++)
        {
            cout<<" ";
        }

        //Stars
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        s -=2;
        cout<<endl;
    }
    return 0;
}


//OutPut
// 5
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********