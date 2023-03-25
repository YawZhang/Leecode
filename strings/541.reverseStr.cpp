#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.size() == 1) return s;
        int k2 = 2*k;
        int slen = s.size();
        int i = 0;
        while (i< s.size()) {
            int i0 = i;

            if ((slen -i) < k) {
                int j = slen - 1;//双指针
                while(i<(i0 + (s.size() - i0)/2)) {
                    swap(s[i++], s[j--]);
                }
            }
            else {
                int j = k+i0-1;
                while ( i < (i0+k/2)) {
                    swap(s[i++], s[j--]);
                }
                if ((slen -i0) < k2 && (slen-i0)>=k) {
                    i = slen; 

                }
            }
            i = i0 + k2;
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
    // string b = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjq";
    // printf("%d\n", b.size());
    // string a =  "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    string a = "abcdefg";
    printf("%d\n", a.size());
    int k = 2;
    Solution S ;
    printString(a);
    string ans = S.reverseStr(a, k);
    printString(ans);


    return 0;
}
