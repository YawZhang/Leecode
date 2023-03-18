#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        //牛顿法
        // ans = (ans + x/ans) / 2
        // 当ans 
        long long  ans = x;
        while ( ans*ans > x ) {
            ans = ( ans + x/ans ) / 2; 
            cout << ans << endl;
        } 
        return (int)ans;
    }
};	




int main() {

    int x = 48;
    Solution S ;
    int ans = S.mySqrt(x);

    cout << ans << endl;
}