#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        //按x_start排序
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);//按x_start排序
        int res = 1;
        int start = points[0][0];   // 交集开始
        int end = points[0][1];     // 交集结束
        for(int i = 1; i < points.size(); i++) {
            if (points[i][0] <= end) {
                start = points[i][0];
   
                continue;
            }
            res++;
            start = points[i][0];
            end = points[i][1];
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

    // vector<vector<int>> a = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    Solution S ;

    int ans = S.findMinArrowShots(a);
    cout << ans ;


    return 0;
}

