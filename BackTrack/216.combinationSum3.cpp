#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTracking(int k, int n, int startIndex, int sum) {
        if (path.size() == k) {
            if (sum == n) res.push_back(path);
            return;
        }

        for (int i = startIndex; i < (10 - k + path.size() + 1); i++ ) {
            sum += i;
            path.push_back(i);
            backTracking(k, n, i+1, sum);
            path.pop_back();
            sum -= i;
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 1, 0);
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

    int n = 7;
    int k = 3;
    Solution S ;

    vector<vector<int>> ans = S.combinationSum3(3, 7);
    printV(ans);


    return 0;
}
