#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp(i,j) 代表(i,j)坐标的可能路径数
        // dp(i,j) = dp(i-1, j) + dp(i, j-1)
        
        int dp[m][n] = {0}; // 初始化二维数组
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        } 
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        } 
        for(int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1]; 
    }
};


int main() {

    int m = 3;
    int n = 7;

    Solution S;

    int ans = S.uniquePaths(m, n);
    cout << ans ;


    return 0;
}
