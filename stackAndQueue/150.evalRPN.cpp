#include<bits/stdc++.h>


using namespace std;



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> nums;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long nums2 = nums.top(); nums.pop();
                long long nums1 = nums.top(); nums.pop();
                
                if (tokens[i] == "+") nums.push(nums1+nums2);
                if (tokens[i] == "-") nums.push(nums1-nums2);
                if (tokens[i] == "*") nums.push(nums1*nums2);
                if (tokens[i] == "/") nums.push(nums1/nums2);
            }
            else {
                nums.push(stoll(tokens[i]));
            }
        }
        return (int)nums.top();
    }
};



int main() {

    vector<string> a = {"2","1","+","3","*"};
    Solution S ;

    int ans = S.evalRPN(a);
    cout << ans ;



}
