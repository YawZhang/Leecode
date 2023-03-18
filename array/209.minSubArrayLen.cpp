#include<bits/stdc++.h>


using namespace std;

// #define NT32_MAX = 10**10;

class Solution {
public:
// 方法1：暴力解法
    // int minSubArrayLen(int t, vector<int>& nums) {
    //     int i = 0;

    //     int minSize = INT32_MAX;
    //     while( i < nums.size()) {
    //         int ans = 0;
    //         for ( int j = i; j< nums.size(); j++) {
    //             ans += nums[j];
    //             if (ans >= t) {
    //                 minSize = minSize > (j-i+1) ? (j-i+1) : minSize;
    //                 break;
    //             }
    //         }
 
    //         i++;
    //     }
    //     return minSize < INT32_MAX ? minSize : 0 ;
    // }

// 方法2：滑动窗口
    int minSubArrayLen(int t, vector<int>& nums) {
        int i = 0;
        int minSize = INT32_MAX;
        int sum = 0;
        //循环中为终止指针
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while ( sum >= t ) {//只有当窗口内sum满足target时才进行更新起始指针
            //暴力解法相当于每次将起始指针更新到0
            //滑动窗口解法相当于每次将起始指针后移一位,减少了不必要的子集计算
                minSize = min(minSize, (j-i+1));
                sum -= nums[i];
                i++;//更新起始指针
            } 
        }

        return minSize < INT32_MAX ? minSize : 0 ;
    }
};



int main() {

    vector<int> a = {1,1,1};
    int t = 4;
    Solution S ;

    int ans = S.minSubArrayLen(t, a);
    cout << ans ;


    return 0;
}

