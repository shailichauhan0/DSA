#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char ch='a';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           cout<<ch<<" ";
           ch++;
        }
        cout<<endl;
    }   
return 0;
}


//OutPut
// 4
// a b c d
// e f g h
// i j k l
// m n o p