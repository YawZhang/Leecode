#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void backTracking(vector<int> c, int t, int startIndex) {
        if (sum >= t) {
            if (sum == t) {
                res.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i < c.size(); i++) {
            path.push_back(c[i]);
            sum += c[i];
            backTracking(c, t, i);
            path.pop_back();
            sum -= c[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        backTracking(c, t, 0);
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

    vector<int> a = {2, 3, 6, 7};
    int target = 7;

    Solution S ;

    vector<vector<int>> ans = S.combinationSum(a, target);
    printV(ans);

    return 0;
}
