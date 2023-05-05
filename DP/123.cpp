#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;

        int dp[n+1][2];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = -prices[0]; // 第 i-1 天 持有股票
        dp[1][1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-2][1] - prices[i-1]); // 前一次持有 , 前一次未持有,需买入
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] + prices[i-1]); // 前一次未持有, 前一次持有, 需卖出
        }
        return dp[n][1];
    }
};


int main() {

    vector<int> a = {1,2,3,0,2};
    Solution S ;

    int ans = S.maxProfit(a);
    cout << ans ;


    return 0;
}
