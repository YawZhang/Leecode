#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<string> res;
    string path;

    void backTracking(string digits, int dlen, int dStart, int aStrat) {
        if (path.size() == dlen) {
            res.push_back(path);
            return;
        }

        for (int i = dStart; i < dlen; i++) {
            int n = digits[i] - '0';
            if (n == 7) {
                for (int j = aStrat; j < 4; j++) {
                    int d = 97 + j + (n-2)*3 ;
                    char alpha = d;
                    path += alpha;
                    backTracking(digits, dlen, i+1, 0);
                    path.pop_back();
                }
            }
            else if (n == 8) {
                for (int j = aStrat; j < 3; j++) {
                    int d = 97 + j + (n-2)*3 + 1;
                    char alpha = d;
                    path += alpha;
                    backTracking(digits, dlen, i+1, 0);
                    path.pop_back();
                }
            }
            else if (n == 9) {
                for (int j = aStrat; j < 4; j++) {
                    int d = 97 + j + (n-2)*3 + 1;
                    char alpha = d;
                    path += alpha;
                    backTracking(digits, dlen, i+1, 0);
                    path.pop_back();
                }
            }
            else {
                for (int j = aStrat; j < 3; j++) {
                    int d = 97 + j + (n-2)*3;
                    char alpha = d;
                    path += alpha;
                    backTracking(digits, dlen, i+1, 0);
                    path.pop_back();
                }
            }
            
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        int dsize = digits.size();
        if (dsize == 0 ) return {};

        backTracking(digits, dsize, 0, 0);

        return res;

    }
};

void printV(vector<string> a) {
    for (int i = 0; i< a.size(); i++) {
        cout << a[i]  << endl;
    }
}

int main() {

    string a = "9";

    Solution S ;

    vector<string> ans = S.letterCombinations(a);
    printV(ans) ;


    return 0;
}
