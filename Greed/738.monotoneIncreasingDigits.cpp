#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string nums = to_string(n);
        if (nums.size() == 1) return n;
        int flag = nums.size();
        for (int i = nums.size() -1; i > 0; i--) {
            if (nums[i-1] > nums[i]) {
                flag = i;
                nums[i-1]--;
            }
        }
        
        for (int i = flag; i < nums.size(); i++) {
            nums[i] = '9';
        }
        return stoi(nums);
    }
};



int main() {

    int a = 332;
    Solution S ;

    int ans = S.monotoneIncreasingDigits(a);
    cout << ans ;


    return 0;
}
