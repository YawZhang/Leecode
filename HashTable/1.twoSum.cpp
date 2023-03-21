#include<bits/stdc++.h>
#include <iostream>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> num_hash;

        for (int i = 0; i < nums.size(); i++) {
            int s = target - nums[i];//在哈希表中找是否存在匹配的s，与nums[i]构成target
            if (num_hash.find(s) != num_hash.end()) {
                //若找到了s，则立即返回两个数的下标
                return {num_hash.find(s)->second, i};
            }
            num_hash.insert(pair<int, int> (nums[i], i));//s不在哈希表中，则立即插入遍历过的元素nums[i]
        }
        return {};
    }
};


int main() {

    vector<int> a = {1, 2, 5, 6, 4};
    int t = 9;
    Solution S ;

    vector<int> ans = S.twoSum(a, t);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}
