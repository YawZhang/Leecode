#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        //按x_start升序排序
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& ints) {
        sort( ints.begin(), ints.end(), cmp );// 按开始区间升序排列

        int res = 0;
        int end = ints[0][1];     // 交集结束
        for(int i = 1; i < ints.size(); i++) {
            if (ints[i][0] < end) {
                // 如果有交集
                res++;//删除该集合
                end = min(ints[i][1], end);
                continue;
            }
            // 否则
            end = ints[i][1];
        }
        return res;
    }
};



int main() {
    string sysin ;
    cin >> sysin;

    int count = 0;
    vector<vector<int>> a;
    vector<int> b;
    for (int i = 0; i < sysin.size(); i++) {
        if (sysin[i] <= '9' && sysin[i] >= '0') {
            b.push_back(sysin[i] - '0');
            count++;
            if (count == 2) {
                count = 0;
                a.push_back(b);
                b.clear();
            }
        }
    }
    // vector<int> a = {1, 2, 3, 4, 5};
    Solution S ;

    int ans = S.eraseOverlapIntervals(a);
    cout << ans ;


    return 0;
}
