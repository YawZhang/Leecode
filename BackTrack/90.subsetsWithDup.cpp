#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, int startIndex, vector<bool>& used) {
        res.push_back(path);
        
       
        for(int i = startIndex; i < nums.size(); i++) {
            used[i] = true;
            if (i!=0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            path.push_back(nums[i]);
            dfs(nums, i+1, used);
            path.pop_back();
            used[i] = false;
        }
        return;

    }
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, used);
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

    vector<int> a = {5,5,5,5};

    Solution S ;

    vector<vector<int>> ans = S.subsetsWithDup(a);
    printV(ans);

    return 0;
}

