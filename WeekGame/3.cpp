#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> res(distance.size(), 0);
        

        for(int i = 1; i < s.size(); i++ ) {
            int ss = s[i]-'a';
            if (res[ss] == -1) res[ss] = i;
            else {
                if ((i - res[ss]) != distance[ss]) return false;
            }
        }
        
        return true;
    }
};




int main() {

    vector<int> a = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string d = "abaccb";

    Solution S ;

    bool ans = S.checkDistances(d, a);
    cout << ans ;

    return 0;
}
