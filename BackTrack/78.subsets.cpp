#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, int startIndex) {
        res.push_back(path);
        // if (startIndex >= nums.size()) {
        //     return;
        // }
        for (int i = startIndex; i<nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        dfs(nums, 0);
        return res;
    }
};

void printV( vector<vector<int>> a) {
    cout << "nums size = " << a.size() << endl;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<int> a = {1,2,3};

    Solution S ;

    vector<vector<int>> ans = S.subsets(a);
    printV(ans);

    return 0;
}

