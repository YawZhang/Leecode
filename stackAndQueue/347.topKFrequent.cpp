#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs ) {
            return lhs.second > rhs.second;
        }
    };// 这是为仿函数的写法


    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 创建map哈希表统计所有元素出现频率
        unordered_map<int, int> m; 
        for (int i = 0; i < nums.size(); i++ ) {
            m[nums[i]]++;
        }

        // 对频率进行排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫描所有频率的数值
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            pri_que.push(*it);//将每个元素放入堆
            if (pri_que.size() > k) {
                pri_que.pop();// 保持小顶堆大小为k
            }
        }

        vector<int> res(k);

        for ( int i = k-1; i >= 0; i--) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }


        return res;
    }
};

void printVector(vector<int> a) {
    for (int i = 0; i<a.size(); i++) {
        cout << a[i] << " " ;
    }
    cout << endl << "================" << endl;
}

int main() {

    vector<int> a = {1, 2, 3, 4, 5, 2, 2,3,2 ,4 ,5};
    int k = 2;

    Solution S ;

    vector<int> ans = S.topKFrequent(a, k);
    printVector(ans) ;


    return 0;
}
