#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {

            if (bill == 5) five++;
            else if (bill == 10) ten++;
           
            int res = bill - 5;
            if (res >= 10) {
                if (ten != 0) {
                    ten--;
                    res -= 10;
                }
            }
            while(res > 0) {
                if (five == 0) return false;

                five--;
                res -= 5;

            }
        }
        return true;
    }
};


int main() {

    vector<int> a = {5,5,5, 10,20};
    Solution S ;

    bool ans = S.lemonadeChange(a);
    cout << ans ;


    return 0;
}

