#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    

    vector<int> partitionLabels(string S) {
        int hash[27] = {0}; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        
        int start = 0;
        int end = 0;
        vector<int> res;

        for (int i = 0; i < S.size(); i++) {
            end = max(end, hash[S[i] - 'a']);
            if (end == i) {
                res.push_back(end- start + 1);
                start = i+1;
            }
        }
        return res;
    }
};



int main() {

    string a = "eccbbbbdec";
    Solution S ;

    vector<int>  ans = S.partitionLabels(a);
    for(int s : ans) {
        cout << s << " " ;
    }


    return 0;
}

