#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        vector<vector<int>> results;
        if (nums.size()<4) return results;

        sort(nums.begin(), nums.end());
        int nlen = nums.size();
        int e1 = nlen - 3;
        int e2 = nlen - 2;
        for (int i = 0; i < e1; i++) {
            // 1级剪枝
            if ((nums[i] >=0 && nums[i]> t)) break;//当t为正数,数组最小数都为正

            if (i > 0 && nums[i] == nums[i-1]) continue;//a去重

            for( int j = i+1; j < e2; j++ ) {
                // 2级剪枝
                if (nums[i]  + nums[j] > t && nums[i] + nums[j] > 0) break;

                if (j > i+1 && nums[j] == nums[j-1] ) continue;//b去重


                int left = j+1;
                int right = nlen-1;

                

                while  (left < right) {
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[left];
                    int d = nums[right];
                    if ( (long) nums[i] + nums[j] + nums[left] + nums[right] > t) right--;
                    else if ( (long)nums[i] + nums[j] + nums[left] + nums[right] < t) left++; 
                    else {
                        results.push_back(vector<int>{nums[i] , nums[j] , nums[left] , nums[right]});
                        while(left < right && nums[right]==nums[right-1]) right--;
                        while(left < right && nums[left]==nums[left+1]) left++; 
                        right--;
                        left++;
                    }
                    
                }
            }
        }
        return results;
    }
};

void printTwoVector(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<int> a = {-2,-1,-1,1,1,2,2};
    int t = 0;
    Solution S ;

    vector<vector<int>> ans = S.fourSum(a,t);
    printTwoVector(ans) ;


    return 0;
}
