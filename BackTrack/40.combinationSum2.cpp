#include<bits/stdc++.h>


using namespace std;



class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& c, int t, int startIndex, int sum, vector<bool>& used) {
        if (sum == t) {
            res.push_back(path);
            return;
        }
        
        for (int i = startIndex; i < c.size() && sum + c[i] <= t; i++) {
            if (i > 0 && c[i] == c[i-1] && used[i-1] == false) 
            {
                continue;
            }
            used[i] = true;
            path.push_back(c[i]);
            dfs(c, t, i+1, sum + c[i], used);
            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<bool> used(c.size(), false);
        path.clear();
        res.clear();
        sort(c.begin(), c.end());
        dfs(c, t, 0, 0, used);
        return res;
    }
};

void printV( vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<int> a = {10,1,2,7,6,1,5};
    int target = 8;

    Solution S ;

    vector<vector<int>> ans = S.combinationSum2(a, target);
    printV(ans);

    return 0;
}
