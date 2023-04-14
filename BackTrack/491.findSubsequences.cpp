#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
        }

        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if (path.size() != 0 && nums[i] < path.back()) continue;

            if (uset.find(nums[i]) != uset.end()) continue;

            uset.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        if (nums.size() > 1) dfs(nums, 0);
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

    vector<int> a = {4, 6, 7,7};

    Solution S ;

    vector<vector<int>> ans = S.findSubsequences(a);
    printV(ans);

    return 0;
}
