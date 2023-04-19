#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]){
            // 如果身高相同，k小的排前面
            return a[1] < b[1];
        }

        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), cmp); // 按身高大小排序
        // 此时保证该元素身高都不大于前面元素身高，进而可以按属性进行插入
        vector<vector<int>> que;

        for(vector<int> pp : p) {
            int position = pp[1];

            // 如果当前大于元素的个数<队列的元素, 则需要插入到队列相应位置
            if (position < que.size()) que.insert(que.begin() + position, pp);

            // 如果当前大于元素的个数>=队列的元素, 则直接放到队尾
            else que.push_back(pp);
            
        }
        return que;
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

    Solution S ;

    vector<vector<int>> ans = S.reconstructQueue(a);
    printTwoVector(ans) ;


    return 0;
}
