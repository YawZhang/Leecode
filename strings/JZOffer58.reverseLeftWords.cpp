#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    
    void reverse(string& s, int start, int end) {
        int j = end;
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseLeftWords(string s, int n) {
        reverse(s, 0, s.size()-1);//整体翻转

        //局部翻转

        reverse(s, 0, s.size()-n-1);
        reverse(s, s.size()-n, s.size() -1);
        
        return s;
    }
};



int main() {

    string a = "abcdefg";
    int k = 2;
    Solution S ;

    string ans = S.reverseLeftWords(a, k);
    cout << ans ;


    return 0;
}
