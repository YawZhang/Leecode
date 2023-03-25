#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    // 反转子串
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i<j; i++, j--) {
            swap(s[i] , s[j]);
        }
    }

    // 去除冗余空格
    void removeExtraSpace(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' '){
                if (slow!=0 ) s[slow++] = ' ';//如果slow不在字符串开头，就加个空格
                while(fast < s.size() && (s[fast] != ' ')) {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    //插入新字串
    void insertSubString(string& s, string& t, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
                t.push_back(s[i]);
            }
        if (start > -1)  t.push_back(' ');
    }


    string reverseWords(string s) {
        string t;
        //去重冗余空格
        removeExtraSpace(s);
        
        //反转子串
        for (int j = s.size()-1; j>=0; j--) {
            if (s[j] == ' ') continue;
            int i = j;
            while (i>=0 && s[i] != ' ') {
                i--;
            }//此时(i, j]为子串
            
            insertSubString(s, t, i , j);

            j = i;

        }
        return t;
    }
};






int main() {
    string a =  "  hello   world ";
    printf("%d\n", a.size());
    Solution S ;
    cout << a << endl;
    string ans = S.reverseWords(a);
    printf("%d\n", ans.size());
    cout << ans<< endl;


    return 0;
}
