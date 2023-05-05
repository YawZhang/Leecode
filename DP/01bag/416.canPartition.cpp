#include<bits/stdc++.h>


using namespace std;



class Solution {
public:

    /* 记忆化搜索 */
    int dfs(int i, int c, vector<int>& nums) {
    // int dfs(int i, int c, vector<int>& nums, vector<vector<int>>& cache) {
        if ( i<0 ) return 0;
        int ans  = 0;
        if (nums[i] > c)  {
            return cache[i-1][c];
        }
        ans = max(dfs(i-1, c, nums, cache), dfs(i-1, c - nums[i], nums, cache) + nums[i]);
        cache[i][c] = ans;
        return ans;
    }
    
    // int dfs(int i, int c, vector<int>& nums) {
    //     if ( i<0 ) return 0;
    //     if (nums[i] > c) return dfs(i-1, c, nums);
    //     return max(dfs(i-1, c, nums), dfs(i-1, c - nums[i], nums) + nums[i]);;
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }

        if (sum % 2 == 1 ) return false;
        sum /= 2; // 当前目标值，即背包容量

        /* 回溯 */
        // return dfs(nums.size()-1, sum, nums) == sum; 

        /* 记忆化搜索 */
        // vector<vector<int>> cache(nums.size(), vector<int>(sum+1, 0));
        return dfs(nums.size()-1, sum, nums) == sum; 


        /* 一维滚动数组*/
        // sum /= 2; // 当前目标值，即背包容量
        // vector<int> dp(sum+1, 0);

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = sum; j >= 0; j--) {
        //         if (nums[i] <= j) {
        //             dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        //         }
        //     }
        // }
        // return dp[sum] == sum;
    }
};


int main() {

    vector<int> a = {1,2,5};
    Solution S ;

    bool ans = S.canPartition(a);
    cout << ans ;


    return 0;
}
