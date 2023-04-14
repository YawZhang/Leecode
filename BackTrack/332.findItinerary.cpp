#include<bits/stdc++.h>


using namespace std;



// class Solution {
// private:
// // unordered_map<出发机场, map<到达机场, 航班次数>> targets
//     unordered_map<string, map<string, int>> targets;
//     bool backtracking(int ticketNum, vector<string>& result) {
//         if (result.size() == ticketNum + 1) {
//             return true;
//         }
//         for (pair<const string, int>& target : targets[result[result.size() - 1]]) { // result[result.size() - 1] 代表当前机场
//         // target 代表 (下一个机场, 剩余机票数）
//             if (target.second > 0 ) { // 记录到达机场是否飞过了
//                 // 当前机场还未飞 或者说还有存票
//                 result.push_back(target.first); // 将机场压入行程中
//                 target.second--; // 当前机票销毁
//                 if (backtracking(ticketNum, result)) return true; // 递归下个机场，如果下个机场的后续行程中能形成路径，直接返回
//                 result.pop_back();  // 回溯
//                 target.second++;    // 回溯
//             }
//         }
//         return false;
//     }   
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         targets.clear();
//         vector<string> result;
//         for (const vector<string>& vec : tickets) {
//             targets[vec[0]][vec[1]]++; // 记录映射关系
//         }
//         result.push_back("JFK"); // 起始机场
//         backtracking(tickets.size(), result);
//         return result;
//     }
// };


class Solution {
public:
    vector<string> res; // 最终行程路径
    // 初始化当前机票映射哈希表 -> (当前机场string, (下一个机场string：余票数int))
    unordered_map<string, map<string, int>> targets; // 此时用map做映射使用map中存放元素是有序的

    bool dfs(int ticketNums) {
        // 当找到满足路径后直接返回，这时返回的路径一定是所有路径中最小的路径组合 -> map 的有序性
        if (res.size() == ticketNums+1) {
            return true;
        }
        string cur_airport = res[res.size()-1];// 路径末尾存放当前机场
        // map<string, int> plan_airports = targets[cur_airport]; // 当前机场的后序可飞机场 -> 已排序
        // 这里需要随时修改余票数，遍历map并随时修改需要以这样的方式进行
        //pair<const string, int>& next_airport : targets[cur_airport]
        // 否则，重新创建 map<string, int> plan_airports = targets[cur_airport];，并不会更改原target中的值
        for (pair<const string, int>& next_airport : targets[cur_airport]) {
            
            if (next_airport.second > 0) {
                // 下个机场还有余票时，可以起飞
                res.push_back(next_airport.first);
                next_airport.second--;//余票销毁一张
                if (dfs(ticketNums)) return true;
                next_airport.second++;  // 回溯
                res.pop_back();         // 回溯
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        for(const vector<string> ticket : tickets) {
            string cur_airport = ticket[0];
            string next_airport = ticket[1];
            targets[cur_airport][next_airport]++; // 将所有机票映射到哈希表中
        }
        res.push_back("JFK");

        dfs(tickets.size());
        return res;
    }
};

void printV(vector<string> a) {
    for (string x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    vector<vector<string>> a = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution S ;

    vector<string> ans = S.findItinerary(a);
    printV(ans) ;

    return 0;
}
