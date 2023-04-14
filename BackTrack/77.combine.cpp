#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backTracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= (n - k + path.size() + 1); i++ ) {
            path.push_back(i);
            backTracking(n, k , i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k , 1);
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

    int n = 1;
    int k = 1;
    Solution S ;

    vector<vector<int>> ans = S.combine(n, k);
    printV( ans) ;


    return 0;
}