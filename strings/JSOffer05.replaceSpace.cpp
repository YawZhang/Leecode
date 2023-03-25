#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;//统计空格数，确定需要扩容的大小
        for (int i = 0; i< s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }

        int oldSize = s.size();
        s.resize(oldSize + count*2);
        for (int i = s.size()-1,  j = oldSize -1; j >=0; i--, j-- ) {
            if (s[j] == ' '){
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i -= 2;
            }
            else {
                s[i] = s[j];
            }

        }

        return s;
    }
};


void printString(string a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }


int main() {

    string a = "We are happy.";
    Solution S ;
    printString(a);
    string ans = S.replaceSpace(a);
    printString(ans);


    return 0;
}
