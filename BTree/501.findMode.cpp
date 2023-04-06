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
    unordered_map<int, int> um;
    TreeNode* pre;
    int size = 0;
    int maxsize = 0;
    vector<int> res;

    void Travel(TreeNode* cur) {
        if (!cur) return;

        Travel(cur->left);

        // 中
        if (pre==NULL) {
            size=1;
        }
        else if (pre->val == cur->val) {
            size++;
        }
        else size = 0;
        pre = cur;
        um[pre->val]++;
        
        if (maxsize == size) res.push_back(pre->val);
        else if (size > maxsize) {
            maxsize = size;
            res.clear();
            res.push_back(pre->val);
        }

        Travel(cur->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        Travel(root);
        return res;
    }
};



int main() {

    return 0;
}
