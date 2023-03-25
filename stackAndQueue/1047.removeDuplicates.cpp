#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    // 栈中存放匹配字符串，最后重置s
    // string removeDuplicates(string s) {
    //     if (s.size() == 1) return s;
        
    //     stack<char> k ;
    //     for(int i = 0; i< s.size(); i++) {
    //         if ( (k.empty()) || (s[i] != k.top())) {
    //             k.push(s[i]);
    //         }
    //         else k.pop();
    //     }
    //     if (!k.empty()) {
    //         int kSize = k.size();
    //         for (int i = kSize-1; i >= 0; i--) {
    //             s[i] = k.top();
    //             k.pop();
    //         }
    //         s.resize(kSize);
    //         return s;
    //     }
    //     else return "";
    // }

    // 用字符串作栈
    string removeDuplicates(string s) {
        string result;
        for (char c : s) {
            if ( result.empty() || c != result.back()) {
                result.push_back(c);
            }
            else result.pop_back();
        }
        return result;
    
    }
};



int main() {

    string  a = "abbaca";
    Solution S ;

    string ans = S.removeDuplicates(a);
    cout << ans ;


    return 0;
}

