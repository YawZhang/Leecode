#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;


    void dfs(vector<int> nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++ ) {
            if (used[i] == true) continue; // 当前树枝已经用过该元素了，跳过
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
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

    vector<int> a = {1};
    Solution S ;

    vector<vector<int>> ans = S.permute(a);
    printV(ans) ;


    return 0;
}
