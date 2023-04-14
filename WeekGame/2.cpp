#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res(nums.size());

        for (int i = 0; i<nums.size(); i++) {
            long long sum = 0;  
            for (int j = 0; j<nums.size(); j++) {
                if ((i != j) && nums[i] == nums[j]) {
                    sum += abs(j-i);
                };
            }
            res[i] = sum;
        }
        return res;

    }
};

void printV( vector<long long> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
}


int main() {

    vector<int> a = {1, 3, 1, 1, 2};
    Solution S ;

    vector<long long> ans = S.distance(a);
    printV(ans);


    return 0;
}
