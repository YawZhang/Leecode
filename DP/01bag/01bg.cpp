#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int zero_one_bag(int c, vector<int> weight, vector<int> value) {
        // // 1. 二维dp数组的方法 空间复杂度O(n*c)
        // // dp[i][j]代表背包容量为j时，从[0,i]取物品获得的最大价值
        // vector<vector<int>> dp(weight.size(), vector<int>(c+1, 0));

        // for (int i = weight[0]; i <= c; i++) {
        //     dp[0][i] = value[0];
        // }
        // // 开始放入背包
        // for (int i = 1; i < weight.size(); i++) {       // 遍历物品，第一个物品已经初始化
        //     for (int j = 0; j <= c; j++) {
        //         if (weight[i] > j) dp[i][j] = dp[i-1][j];   // 背包容量不够，放不下物品，当前价值不变
        //         // 当容量足够时，有两种选择：
        //         //  1.不放物品：dp[i-1][j] , 即价值不变
        //         //  2.放物品：dp[i-1][j-weight[i]] + value[i]
        //         // dp[i][j]代表此时的最大价值，因此在上面两种选择中要取max
        //         else {
        //             dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        //         }
        //     } 
        // }

        /* 2. 一维dp数组，滚动数组 */
        vector<int> dp(c+1, 0);     //dp(i)代表背包容量为i时候的能存放的最大价值

        for (int i = 0; i < weight.size(); i++) {
            for (int j = c; j >= 0; j--) {
                if (weight[i] <= j) {
                    dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
                }
            }

            for (int num :dp) {
                cout << num << " ";
            }
            cout << endl;

        }
        return dp[c];

    }
};



int main() {

    vector<int> w = {1,3,4};        // i^th的重量
    vector<int> v = {15, 20, 30};   // i^th的价值
    int c = 4;                      // 背包容量
    Solution S ;

    int ans = S.zero_one_bag(c, w, v);
    cout << ans ;


    return 0;
}

