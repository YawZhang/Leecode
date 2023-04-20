#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);

        dp[2] = 1; // dp[i]代表拆分数字i能够得到的最大乘积

        for (int i = 3; i <= n; i++) { 
            // i 代表数字i， 外层循环代表计算2~n的所有乘积
            for(int j = 1; j <= i/2; j++) {
                // 内层循环代表计算当前数字i的所有可能乘积，取最大值
                // j <= i / 2 ，代表在两数相乘时，j x (i-j) = (i-j) x j
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};



int main() {

    int a = 10;
    Solution S ;

    int ans = S.integerBreak(a);
    cout << ans ;


    return 0;
}
