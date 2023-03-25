#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    // 暴力匹配

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) return false;

        for (int i = 1; i <= s.size()/2; i++) {
            if ((s.size() % i) == 0 ) {
                bool match = true;
                for (int j = i; j < s.size(); j++) {
                    if (s[j] != s[j-i]) {
                        match =  false;
                        break;
                    }
                }
                if (match) return true;
            }

           
        }
        return false;
    }


    // // 移动匹配
    // bool repeatedSubstringPattern(string s) {
    //     string a(s+s);
    //     a.erase(a.begin());
    //     a.erase(a.end()-1);
    //     if (a.find(s) != std::string::npos) return true;
    //     return false;
    // }


    // KMP算法
    void getNext(int* next, string s ) {
        //初始化
        int j = 0;
        next[0] = j;

        //开始查找前缀表
        for (int i = 1; i < s.size(); i++) {
            //当前后缀不相同时，指针回退
            while ( j>0 && s[i] != s[j]) {
                j = next[j-1];
            }
            //当前后缀相同时，指针前进
            if ( s[i] == s[j]) {
                j++;
            }
            // 给前缀表幅值
            next[i] = j;

        }
    }


    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) return false;//边界条件控制

        int next[s.size()];
        getNext(next, s);//构建前缀表
        int nlen = next[s.size()-1];
        int sublen = s.size() - nlen;
        if ((nlen != 0) && (s.size() % sublen == 0)) return true;
        return false;
    }
};



int main() {

    string a = "abab";
    Solution S ;
    cout << a << endl;
    bool ans = S.repeatedSubstringPattern(a);
    cout << ans ;


    return 0;
}
