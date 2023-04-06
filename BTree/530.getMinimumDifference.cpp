#include<bits/stdc++.h>


using namespace std;

class TreeNode {
public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(NULL), right(NULL) {};
        TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        int minV = INT_MAX;
        TreeNode* pre = NULL;

        TreeNode* cur = root;

        while(cur!=NULL || !st.empty()) {
            if (cur!=NULL) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                // st.pop();
                cur = st.top();
                st.pop();
                
                if (pre!=NULL) {
                    minV = min(minV, cur->val-pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return minV;
    }
};



int main() {

    return 0;
}
