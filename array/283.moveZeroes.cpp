#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //快慢指针、
        //快指针遍历数组
        //慢指针指向非0数，需要就快指针和慢指针指向的值交换位置
        int slow = 0;
        for ( int fast = 0; fast < nums.size(); fast++ ) {
            if ( nums[fast] != 0 ) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        } 
        for (int i = 0; i < nums.size(); i++ ) {
            cout << nums[i] << " ";
        }

    }
};



int main() {

    vector<int> a = {0,1,0,3,12};
    Solution S ;

    S.moveZeroes(a);




    return 0;
}

