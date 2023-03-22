#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool canConstruct(string r, string m) {
        //字符串均有小写字母组成
        int nhash[26] = {0};

        if (r.size() > m.size()) {
            return false;
        }

        for (int i = 0; i < m.size(); i++) {
            nhash[m[i]-'a']++;
        }
        for (int i = 0; i < r.size(); i++) {
            nhash[r[i]-'a']--;
            
            if (nhash[r[i]-'a'] < 0 ) {
                return false;
            }
        }
        return true;
    }
};



int main() {

    string a = "aaaaaaaaaaaaa";
    string b = "aabaaaaaaaaa";
    Solution S ;

    bool ans = S.canConstruct(a, b);
    cout << ans ;


    return 0;
}

