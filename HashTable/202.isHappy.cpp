#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> result;
   

        while (1) {
            sum = getSum(n);

            if ( sum == 1 ) return true;

            if (result.find(sum) != result.end()) {
                return false;
            }
            else result.insert(sum);
            n = sum;

        }
        return true;
        
    }
    int getSum(int n) {
        int sum = 0;
        while(n>0) {
            int cur = n%10;//个位数
            n /= 10;
            sum += cur*cur;
        }
        return sum;
    }
};



int main() {

    int a = 19;
    Solution S ;

    bool ans = S.isHappy(a);
    cout << ans ;


    return 0;
}

