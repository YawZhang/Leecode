#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<int> intersection(vector<int>& s, vector<int>& t) {
        unordered_set<int> result_set;
        int  num_hash[1001] = {0};

        for (int i = 0; i < s.size(); i++) {
            num_hash[s[i]] = 1;
        }

        for (int i = 0; i < t.size(); i++) {
            if (num_hash[t[i]] == 1) {
                result_set.insert(t[i]);
            }
        }
        return vector<int> (result_set.begin(), result_set.end());

    }
};



int main() {

    vector<int> a = {4,9,5};
    vector<int> b = {9,4,9,8,4};
    Solution S ;

    vector<int> ans = S.intersection(a, b);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}

