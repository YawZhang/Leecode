#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mt) {


        if ( mt.size() == 0 || mt[0].size() == 0 ) return {};
        int h = mt.size();
        int w = mt[0].size(); 
        
         

        vector<int> ans(w*h);

        int startX = 0; int startY = 0;
        int i = 0; int j = 0;
        int offset = 1;
        int loop = min(w, h) / 2;//循环圈数
        int count = 0;

        while ( loop-- ) {
            for ( j = startY; j < w - offset; j++) {
                ans[count++]  = mt[startX][j];   
            }
            for ( i = startX; i < h - offset; i++) {
                ans[count++]  = mt[i][j];   
            }
            for ( ; j > startY; j--) {
                ans[count++]  = mt[i][j];   
            }
            for ( ; i > startX; i--) {
                ans[count++]  = mt[i][j];   
            }

            startX++;
            startY++;
            offset++;

        }

        if ( min(w, h) % 2 == 1) {
            if ( w > h ) {
                //高更短，横着插最后一行
                for ( int k = startY; k < w - offset + 1; k++) {
                    ans[count++] = mt[startX][k];
                }
            } 
            else {
                // 宽更短，竖着插最后一样
                for ( int k = startX; k < h - offset + 1; k++ ) {
                    ans[count++] = mt[k][startY];
                }
            }
        }
        return ans;

    }
};

void printVector(vector<int> a) {
    for (int i = 0; i<a.size(); i++) {
        cout << a[i] << " " ;
    }
    cout << endl << "================" << endl;
}

int main() {

    vector<vector<int>> a = {};
    Solution S ;

    vector<int> ans = S.spiralOrder(a);
    printVector(ans) ;


    return 0;
}
