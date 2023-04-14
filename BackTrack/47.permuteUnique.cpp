#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;


    void dfs(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        int nhash[21] = {0};

        for (int i = 0; i < nums.size(); i++ ) {
            if (used[i] == true) continue; // 当前树枝已经用过该元素了，跳过
            
            if (nhash[nums[i]] == 1) continue; // 同一树层去重
            nhash[nums[i]] = 1;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
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

    vector<int> a = {1,3,2};
    Solution S ;

    vector<vector<int>> ans = S.permuteUnique(a);
    printV(ans) ;


    return 0;
}