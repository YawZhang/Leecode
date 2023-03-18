#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
//   方法1：从前往后进行快慢指针遍历，最后用慢指针来resize字符串，复杂度O(N)
    // bool backspaceCompare(string s, string t) {
    //     //快慢指针
    //     //慢指针输出a，b的退格字符串
    //     int slow_s = 0;
    //     int slow_t = 0;
    //     for ( int fast = 0; fast < s.size(); fast++ ) {

    //         if ( s[fast] != '#' ) {
    //             s[slow_s] = s[fast];
    //             slow_s++;
    //         }
    //         else if (slow_s != 0){
    //             slow_s--;
    //         }
    //     }
    //     s.resize(slow_s);

    //     for ( int fast = 0; fast < t.size(); fast++ ) {
    //         if ( t[fast] != '#' ) {
    //             t[slow_t] = t[fast];
    //             slow_t++;
    //         }
    //         else if (slow_t != 0){
    //             slow_t--;
    //         }
    //     }
    //     t.resize(slow_t);

    //     return s==t;
    // }

//  方法2：从尾到头进行遍历，不跟新string内容
    bool backspaceCompare(string s, string t) {
        int skipS = 0;//记录s中‘#’的数量
        int skipT = 0;//记录t中‘#’的数量
        int slow_s = s.size() - 1;
        int slow_t = t.size() - 1;
        while (1) {
            //当慢指针指到头，停止循环

            while ( slow_s > -1 ) { //只有当slow_s 大于1时，指针才能回退两格
                if ( s[slow_s] == '#' ) {
                    skipS++;
                }
                else {
                    if (skipS > 0) skipS--;//“#”不在开头的时候，回退长度+1；
                    else break;
                }
                slow_s--;
            }//不然不退

            while ( slow_t > -1 ) { //知道遍历完字符串，退出循环
                if ( t[slow_t] == '#' ) {//当遇到“#”，
                    skipT++;//记录需要回退的长度
                }
                else {
                    if (skipT>0) skipT--;//如果存在回退长度，当即指针回退一格，实现过程即不break，继续一次循环使指针-1
                    else break;//当没有遇到“#”,每次都break，比较一次字符
                }
                slow_t--;
            }//不然不退


            if (slow_s < 0 || slow_t < 0) break; // S 或者T 遍历到头了,另一个字符串有剩余元素

            if (s[slow_s] != t[slow_t]) return false;
            slow_s--;//比较完当前字符后，指针-1，继续查找“#”
            slow_t--;
            
        } 
    // 说明S和T同时遍历完毕，此时存在两种情况
    // 1、全部比较完成，确实相同
    // 2、其中一个字符串未遍历完元素，则二者必不相同
    if (slow_s == -1 && slow_t == -1) return true;
    return false;
    }
};



int main() {


    string a = "";
    string b = "a";

    Solution S ;

    bool ans = S.backspaceCompare(a, b);
    cout << ans ;
    return 0;
}
