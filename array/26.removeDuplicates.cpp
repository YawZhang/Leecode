#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //快慢指针
        //慢指针表示保存非重复元素
        //快指针遍历整个数组
        int slow = 0;
        for ( int fast = 0; fast < nums.size(); fast++) {
            if ( nums[fast] != nums[slow] ) {
                slow++;
                nums[slow] = nums[fast];
            }//此时慢指针指向最后一个非重复元素的索引，即size-1
        }
        return slow + 1;

    }
};



int main() {

    vector<int> a = {0,0,1,1,1,2,2,3,3,4};
    Solution S ;

    int ans = S.removeDuplicates(a);
    cout << ans ;


    return 0;
}
