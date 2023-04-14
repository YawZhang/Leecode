#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    bool isPrime(int x) {
        if (x == 1 || x==0) return false;
        for (int i = 2; i <= (sqrt(x)); i++) {
            if ( x % i == 0) return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int max = 0;
        for (int i = 0; i < n ; i++) {
            int j = n- i -1;
            if (isPrime(nums[i][i])) {
                max = (nums[i][i] > max ? nums[i][i] : max);
            }
            if (isPrime(nums[i][j])) {
                max = (nums[i][j] > max ? nums[i][j] : max);
            }
        }
        return max;
    }
};


int main() {

    vector<vector<int>> a = {{1,2,3, 4}, {8, 5,17,7},{91, 9,11,10}, {4, 6, 7, 8}};
    Solution S;

    bool ans = S.isPrime(1);
    cout << ans ;


    return 0;
}
