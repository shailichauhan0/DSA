#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // int size = 2 * n - 1;
    // int a[size][size];
    // int start = 0;
    // int end = size - 1;

    // while (n != 0) {
    //     start = 0; 
    //     end = size - 1; 

    //     for (int i = start; i <= end; i++) {
    //         for (int j = start; j <= end; j++) {
    //             if (i == start || i == end || j == start || j == end) {
    //                 a[i][j] = n;
    //             }
    //         }
    //     }

    //     // Printing the matrix
    //     for (int i = 0; i < size; i++) {
    //         for (int j = 0; j < size; j++) {
    //             cout << a[i][j] << " ";
    //         }
    //         cout << endl;
    //     }

    //     n--; 
    // }
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<2*n-1;j++)
            {
                int top=i;
                int left=j;
                int right=(2*n-2)-j;
                int bottom=(2*n-2)-i;
                cout<<(n-min(min(top,bottom),min(right,left)));
            }
            cout<<endl;
        }
    return 0;
}



//OutPut
// 6
// 66666666666
// 65555555556
// 65444444456
// 65433333456
// 65432223456
// 65432123456
// 65432223456
// 65433333456
// 65444444456
// 65555555556
// 66666666666