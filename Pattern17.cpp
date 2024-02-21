#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        //Space
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }

         //Alphabets
        char ch='A';
        int s=(2*i+1)/2;
        for(int j=1;j<=2*i+1;j++)
        {
            cout<<ch;
            if(j<=s)
            ch++;
            else
            ch--;
        }
        //Space
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }

return 0;
}


//Output
// 5
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA