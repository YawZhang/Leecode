#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    // 暴力求解算法，时间复杂度为O(n*m)
    // int strStr(string h, string n) {
    //     if (h.size() < n.size()) return -1;

    //     for (int i = 0; i <= h.size()-n.size()+1; i++) {
    //         int j = 0;
    //         int k = i;
    //         while(j<n.size() && h[k] == n[j]) {
    //             k++;
    //             j++;
    //         }
    //         if (j==n.size()) return i;
    //     }
    //     return -1;
    // }

    // KMP算法，时间复杂度O(n+m)
    void getNext(int* next, string s) {
        // 初始化，目的是第一个字符没有前缀后缀
        int j = -1;
        next[0] = j;//初始化next数组初始值为-1，即所有最长相等前后子串长度-1；

        for (int i = 1; i < s.size(); i++) {
            // 当前后缀末尾不相同时，
            while ( j > -1 && s[i] != s[j+1]) {
                j = next[j];//j回退找前一个最长相等前后子串长度
            }

            // 如果前后缀末尾相同，i和j同时++
            if (s[i] == s[j+1]) {
                j++;//此时在这里对i++,因为执行完这个预计，会进入下个循环，i++
            }
            next[i] = j; //将j（前缀长度）赋给next[i]
        }
    }
    
    
    int strStr(string h, string n) {
        //先处理边界条件
        if (h.size() < n.size()) return -1;

        //初始化next数组
        int next[n.size()];
        getNext(next, n);
        int i = 0;
        while(i != n.size()) {
            cout << next[i] << " ";
            i++;
        }
        cout << endl;

        // 开始从文本串中查找模式串
        int j = -1;
        for (int i = 0; i < h.size(); i++) {
            //如果当前字符与模式串字符不匹配，找前缀表的上一个位置
            while( j > -1 && h[i] != n[j+1]) {
                j = next[j];
            }

            if (h[i] == n[j+1]) {
                j++;
            }

            if (j == (n.size()-1)) {
                return i - n.size()+1;
                // 这个+1是因为 
                // - i此时指向的文本串中匹配到的模式串的最后一个字符的位置
                // - 而头指针从0开始，因此需要+1
            }
        }
        return -1;
    }
};


int main() {

    string a = "leetcode";
    string b = "leeto";
    Solution S ;

    int ans = S.strStr(a, b);
    cout << ans ;
    

    return 0;
}
