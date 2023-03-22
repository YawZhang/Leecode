#include<bits/stdc++.h>


using namespace std;

void printTwoVector(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());//先对数组进行排序，方便用双指针进行移动求值

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return results;//排完序后，如果最小数都大于0，直接退出

            //a去重
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i+1;
            int right = nums.size() - 1;
            while( left < right ) {
                if ((nums[i] + nums[left] + nums[right]) > 0) right--;//大了，c指针收缩
                else if ((nums[i] + nums[left] + nums[right]) < 0) left++;//小了，b指针收缩
                else {
                    //反之，a+b+c = 0;找到了三元组，开始对三元组中的b和c去重
                    results.push_back(vector<int>{nums[i] , nums[left] , nums[right]});
                    while(left < right && nums[right] == nums[right-1]) right--;//c去重
                    while (left < right && nums[left] == nums[left+1]) left++;//b去重
                    
                    //此时，b和c与插入进去的三元组相同，需要再完成一次指针收缩
                    right--; left++;
                }
            }
            cout << "hello world! " << endl;
        }
        return results;


    }
};




int main() {

    vector<int> a = {-1,0,1,2,-1,-4};
    Solution S ;

    vector<vector<int>> ans = S.threeSum(a);
    printTwoVector(ans);


    return 0;
}
