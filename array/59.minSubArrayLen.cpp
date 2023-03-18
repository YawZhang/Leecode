#include<bits/stdc++.h>


using namespace std;

void printVector(vector<vector<int>> a);

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n ,vector<int>(n));
        int startX = 0; int startY = 0;
        int j = 0; int i = 0;
        int loop = n/2;
        int offset = 1;//循环的边数，或者叫边循环终止偏移量（遵循左闭右开原则）
        int count = 1;//需要填的数
        while( loop-- ) {
            //开始进入每圈填值
            for ( j = startY; j<n-offset; j++) {//处理上边
                a[startX][j] = count++;
            }//此时 i=startX, j=n-offset;
            
            for( i = startX; i < n - offset; i++) {//处理右边
                a[i][j] = count++;
            }//此时 i=n-offset, j=n-offset;

            for( ; j > startY; j--) {//处理下边
                a[i][j] = count++;
            }//此时 i=n-offset, j=startY;

            for( ; i > startX; i--) {//处理左边
                a[i][j] = count++;
            }//此时 i=startX, j=startY;
            
            printVector(a);
            //准备处理下一圈
            startX++;
            startY++;
            offset++;
            i++;
            j++;
        }
        if ( n%2 == 1) {
            a[startX][startY] = count++;
        }

        return a;
    }
};


void printVector(vector<vector<int>> a) {
        for (int i = 0; i<a.size(); i++) {
            for ( int j = 0; j < a[0].size(); j++) {
                cout << a[i][j] << " " ;
            }
            cout << endl;
        }
        cout << "================" << endl;
}

int main() {

    // vector<int> a = {1, 2, 3, 4, 5};
    int n = 4;

    Solution S ;

    vector<vector<int>> ans = S.generateMatrix(n);
    printVector(ans);


    return 0;
}

