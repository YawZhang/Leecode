#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        // dp(i,j) 代表(i,j)坐标的可能路径数
        // dp(i,j) = dp(i-1, j) + dp(i, j-1)
        int m = ob.size()+1;
        int n = ob[0].size()+1;

        int dp[m][n] = {0}; // 初始化二维数组
        for (int i = 0; i < n+1; i++) {
            dp[0][i] = 0;
        } 
        for (int i = 0; i < m+1; i++) {
            dp[i][0] = 0;
        } 
        dp[1][1]= 1;
        for(int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (i == 1 && j == 1) continue;
                if ( ob[i-1][j-1] == 1) {
                    dp[i][j] = 0;
                }
                else if (ob[i-1][j-1] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                
            }
        }
        return dp[m-1][n-1]; 
    }
};



int main() {
    string sysin ;
    cin >> sysin;

    int count = 0;
    vector<vector<int>> a;
    vector<int> b;
    for (int i = 0; i < sysin.size(); i++) {
        if (sysin[i] <= '9' && sysin[i] >= '0') {
            b.push_back(sysin[i] - '0');
            count++;
            if (count == 2) {
                count = 0;
                a.push_back(b);
                b.clear();
            }
        }
    }

    Solution S ;

    int ans = S.uniquePathsWithObstacles(a);
    cout << ans ;


    return 0;
}
