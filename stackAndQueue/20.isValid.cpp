#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
//解法一：左括号入栈
    // bool isValid(string s) {
    //     stack<char> a;
    //     for ( int i = 0; i < s.size(); i++) {
    //         if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
    //             a.push(s[i]);
    //         }
    //         else if (s[i] == ')') {
    //             if (a.empty() || a.top() != '(') {
    //                 return false;
    //             }
    //             a.pop();
    //         }
    //         else if (s[i] == ']') {
    //             if (a.empty() || a.top() != '[') {
    //                 return false;
    //             }
    //             a.pop();
    //         }
    //         else if (s[i] == '}') {
    //             if (a.empty() || a.top() != '{') {
    //                 return false;
    //             }
    //             a.pop();
    //         }
    //     }
    //     return a.empty()
    // }


    // 解法二：右括号入栈法
    bool isValid(string s) {
        // 边界条件控制
        if (s.size() % 2 != 0) return false;//奇数字符串大小肯定无法完成括号匹配
        stack<int> a ;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') a.push(')'); 
            else if (s[i] == '[') a.push(']'); 
            else if (s[i] == '{') a.push('}');
            else if (a.empty() || s[i] != a.top()) return false;
            else a.pop(); 
        }
        return a.empty();
    }
};



int main() {

   string a = "()";
    Solution S ;

    bool ans = S.isValid(a);
    cout << ans ;


    return 0;
}
