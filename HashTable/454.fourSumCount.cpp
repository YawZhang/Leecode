#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash_sum;
        int count = 0;
        //第一次循环统计前两个数组
        for(int a: A) {
            for (int b: B) {
                hash_sum[a+b]++;//将ab之和存放在哈希表中，key为其和，value为出现的次数
            }
        }

        //第二次循环，查找后两个数组之和
        for (int c: C) {
            for (int d: D) {
                if (hash_sum.find(0 - (c+d)) != hash_sum.end() ) {
                    count += hash_sum[0-(c+d)];
                }
            }
        }

        return count ;

    }
};



int main() {

    vector<int> a = {1, 2};
    vector<int> b = {-1, -2};
    vector<int> c = {-1, 2};
    vector<int> d = {0, 2};
    Solution S ;

    int ans = S.fourSumCount(a, b, c, d);
    cout << ans ;


    return 0;
}
