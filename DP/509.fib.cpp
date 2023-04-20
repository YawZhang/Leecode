#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;

        int dp[n+1];    // 1.确定dp数组
                        // 2.确定递推公式
        dp[0] = 1;      // 3.dp初始化
        dp[1] = 1;      
                        // 4.dp遍历顺序：前序遍历
        for(int i = 2; i <= n; i++) {
                        // 5.举例推到递推数组
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};



int main() {

    int a = 2;
    Solution S ;

    int ans = S.fib(a);
    cout << ans ;


    return 0;
}
