#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    void reverseString(vector<char>& s) {
        printString(s);
        int j = s.size()-1;
        for (int i = 0; i < (s.size()/2); i++) {
            char tmp = s[i];
            s[i] = s[j];
            s[j--] = tmp;
        }
        printString(s);
    }

    void printString(vector<char> a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};



int main() {

    vector<char> a = {'h','e','l','l','o'};
    Solution S ;

    S.reverseString(a);


    return 0;
}
