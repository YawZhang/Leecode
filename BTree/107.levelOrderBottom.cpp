#include<bits/stdc++.h>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (root) q.push(root);

        TreeNode* cur = root;

        while(!q.empty()) {
            int size = q.size();
            vector<int> lv;

            while(size--) {
                cur = q.front(); q.pop();
                lv.push_back(cur->val);

                if(cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(lv);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};



int main() {

    return 0;
}
