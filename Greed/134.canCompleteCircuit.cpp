#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    // 局部最优：当前剩余的油>下一个加油站的消耗
    // 整体最优：环路行驶一周，可以结束绕行

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int oil = 0;// 当前油量
        for (int i = 0; i < gas.size(); i++) {
            int j = i+1;
            oil = gas[i] - cost[(i+1) % gas.size()];
            while(j != i) {
                oil += (gas[j] - cost[(j+1) % gas.size()]);
                j++;    
                j = j % gas.size();
            }
            if (oil >= 0) return i;
        }
        return -1;
    }
};


int main() {

    // vector<int> a = {1, 2, 3, 4, 5};
    // vector<int> b = { 3, 4, 5, 1, 2};
    // Solution S ;

    // int ans = S.canCompleteCircuit(a, b);
    // cout << ans ;

    string s = "abc";
    s.insert(0, "a");
    cout << s << endl;


    return 0;
}
