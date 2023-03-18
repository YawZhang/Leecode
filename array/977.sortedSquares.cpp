#include<bits/stdc++.h>


using namespace std;



class Solution {
public:

// 方法1：采用内置算法，对平方后的数组进行排序，时间复杂度O(n + nlogn)
    // vector<int> sortedSquares(vector<int>& nums) {
    //     //将int
    //     for ( int i = 0; i < nums.size(); i++) {
    //         nums[i] *= nums[i];
    //     }

    //     sort(nums.begin(), nums.end()); 
    //     return nums;
    // }

// 方法2：采用双指针，直接进行排序
    vector<int> sortedSquares(vector<int>& nums) {
        //思路
        //原数组已有序，由于负数的存在，两端的数平方大，而中间数平方小
        //因此，只需要创建一个空数组，和双指针指向原数组的头尾
        //1.比较两个指针的平方
        
        
        vector<int> ans(nums.size());//构造新数组
        int i = 0; int j = nums.size() - 1;//左右指针
        int k = ans.size() - 1;

        while ( i <= j ) {
            //  1.比较两个指针的平方
            //  2.大数从后往前插入
            //  3.大数的指针向内移动一位
            if ( ( (nums[i] * nums[i]) > (nums[j] * nums[j])) ) {
                ans[k] = nums[i] * nums[i];
                i++;
            }
            else {
                ans[k] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;
    }
};



int main() {
    vector<int> a = {-7,-3,-2, 2,3,11};
    Solution S ;

    vector<int> ans = S.sortedSquares(a);
    for (int i = 0; i< ans.size(); i++) {
        cout << ans[i] << " " ;
    }


    return 0;
}
