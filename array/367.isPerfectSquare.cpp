#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool isPerfectSquare(int x) {
        int l = 0; int r = x;
        while (l <= r) {
            long long  m = (l + r) / 2;
            if (m*m > x) {
                // m^2 > x
                //目标值在[left..mid-1]
                r = m - 1;
            }
            else if (m*m < x)  {
                // x > m^2
                //目标值在[mid..right]
                l = m + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};



int main() {

    int a = 14;
    Solution S ;

    bool ans = S.isPerfectSquare(a);
    cout << ans ;


    return 0;
}

