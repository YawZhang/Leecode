#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(nlogn)
        int maxMinNum = -1; // 最小众数
        int count = 0;      // 当前出现频率
        int maxCount =0;    // 最大频率

        // O(n)
        for(int i = 0; i < nums.size(); i++) {
            count = 0;
            if (nums[i] % 2 == 0) {
                count++;
                while(i > 0 && i<nums.size()-1 && nums[i+1] == nums[i] ){
                    count++;
                    i++;
                }
                if (maxCount < count) {
                    maxMinNum = nums[i];
                    maxCount = count+1;
                }
            }
        }
        return maxMinNum;
    }
};


int main() {

    vector<int>  a = {10000};
    Solution S ;

    int ans = S.mostFrequentEven(a);
    cout << ans ;


    return 0;
}
