#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
//  1.暴力解法
    // int removeElement(vector<int>& nums, int val) {
    //     int len = nums.size();
    //     for (int i = 0; i < len; i++) {
    //         if (nums[i] == val) {
    //             for (int j = i; j < len-1; j++) {
    //                 nums[j] = nums[j+1];//i后面所有元素前移
    //             }
    //             i--;
    //             len--;
    //         }
    //     }
    //     return len;


    // }

    int removeElement(vector<int>& nums, int val) {
        int slow = 0;//慢指针
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {//当快指针指向的值不等于目标值
                nums[slow] = nums[fast];//则将快指针的值赋给慢指针
                slow++;//慢指针+1
            }//快指针也+1

        }
        return slow;
    }
};



int main() {

    vector<int> a = {0,1,2,2,3,0,4,2};
    int b = 2;
    Solution S ;

    int ans = S.removeElement(a, b);
    cout << ans ;


    return 0;
}
