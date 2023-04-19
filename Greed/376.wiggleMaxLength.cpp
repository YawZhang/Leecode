#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return nums.size();
        int maxSubNum = 1;
        // 当前序列趋势 0:初始化 1:上升 -1:下降
        int trend = 0; //
        for (int i = 1; i < nums.size(); i++ ) {
            if (nums[i] > nums[i-1] && trend != 1) {
                // 序列上升，但前面序列不上升
                trend = 1;
                maxSubNum++;
            }
            else if (nums[i] < nums[i-1] && trend != -1 ) {
                // 当前序列下降，但前面序列不下降
                trend = -1;
                maxSubNum++;
            }
        }
        return maxSubNum;
    }
};



int main() {

    vector<int> a = {1,1};
    Solution S ;

    int ans = S.wiggleMaxLength(a);
    cout << ans ;


    return 0;
}
