#include<bits/stdc++.h>


using namespace std;

/*

54 螺旋矩阵

给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mt) {
        
        int m = mt.size();
        int n = mt[0].size();
        if (m==0 || n==0) return {};
        vector<int> a(m*n);
        int count = 0;

        int startX = 0; int startY = 0;
        int i = 0; int j = 0;
        int offset = 1;
        int loop = (min(m, n)) / 2;
        while ( loop-- ) {
            //处理上边
            for ( j = startY; j < n - offset; j++) {
                a[count++] = mt[startX][j];
            }//此时 i=startX, j=n-offset;

            //处理右边
            for ( i = startX; i < m - offset; i++) {
                a[count++] = mt[i][j];
            }// i=m-offset, j=n-offset;

            //处理下边
            for ( ; j > startY; j-- ) {
                a[count++] = mt[i][j];
            }//i=m-offset, j=startY
            
            //处理左边
            for ( ; i > startX; i-- ) {
                a[count++] = mt[i][j];
            }//i=startX, j=n-offset;

            startX++;
            startY++;
            offset++;
        }
        
        //如果是宽为短边,则需要横着插入最后一行
        if ( (m % 2 == 1) && (min(m, n) == m)) {
            for ( int k = startY; k < n - offset+1; k++)
                a[count++] = mt[startX][k];
        }
        //如果长为短边,则需要竖着插入最后一列
        else if ((n % 2 == 1) && (min(m, n) == n)) {
            for ( int k = startX; k < m - offset+1; k++)
                a[count++] = mt[k][startY];
        }
        return a;
    }
};



void printVector(vector<int> a) {
    for (int i = 0; i<a.size(); i++) {
        cout << a[i] << " " ;
    }
    cout << endl << "================" << endl;
}

int main() {

    vector<vector<int>> aa = { {3, 2} };
    Solution S ;

    vector<int>  ans = S.spiralOrder(aa);
    printVector(ans);

    return 0;
}

