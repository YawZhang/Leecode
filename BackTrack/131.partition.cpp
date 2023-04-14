#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<string>> res;
    vector<string> p;
    bool isPalindromicString(string s, int startIndex, int endIndex) {
        
        for ( int i = startIndex; i <= endIndex; i++) {
            if (s[i] != s[endIndex--]) return false;
        }
        return true;
    }

    void dfs(string s, int z) {
        if(z >= s.size()) {
            res.push_back(p);
            return;
        }
        // 开始遍历，
        for (int i = z; i < s.size(); i++) {
            // 如果子串是回文串，保存该子串，开始遍历下一个
            if (isPalindromicString(s, z, i)) {
                string ss = s.substr(z, i-z+1); 
                p.push_back(ss);// 保存当前切割子串
            }
            else continue;
            
            dfs(s, i+1);
            p.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};

void printV(vector<vector<string>> s) {
    for (int i = 0; i < s.size(); i++ ) {
        for(int j = 0; j < s[i].size(); j++) {
            cout << s[i][j] << " " ;
        }
        cout << endl;
    }
}

int main() {

    vector<int> a = {1, 2, 3, 4, 5};
    string s = "aab";
    Solution S ;

    // bool ans = S.isPalindromicString(s, 1, 2);
    vector<vector<string>> ans = S.partition(s);
    printV(ans);
    // cout << ans ;

    return 0;
}

