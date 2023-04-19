#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int candy(vector<int>& r) {
        // 
        vector<int> candy(r.size(), 1);

        for (int i = 1; i < r.size(); i++) {
            if (r[i] > r[i-1]) {
                candy[i] = candy[i-1] + 1;      
            }
        }
        for (int i = r.size()-2; i>= 0; i--) {
            if (r[i] > r[i+1]) {
                candy[i] = max(candy[i+1] + 1, candy[i]) ;
            }
        }
        int res = 0;
        for(int num: candy) {
            res += num;
        }

        return res;
    }

};



int main() {

    vector<int> a = {1, 2, 3, 4, 5};
    Solution S ;

    int ans = S.candy(a);
    cout << ans ;


    return 0;
}
