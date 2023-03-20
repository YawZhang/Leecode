#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};//用数组初始化哈希表
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;//统计字符s[i]出现的次数，若出现hash[s[i]]++
        }
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a']--;//统计字符t[i]在t中出现的次数，若出现，hash--
        }

        // 当此时hash表中所有元素为0时，证明两个字符串为字母异位词
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) return false;
        }

        return true;

    }
};



int main() {

    string a = "abc";
    string b = "cba";
    Solution S ;

    bool ans = S.isAnagram(a, b);
    cout << ans ;


    return 0;
}
