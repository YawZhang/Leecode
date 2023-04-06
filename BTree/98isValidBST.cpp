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
    long long maxV = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool left = isValidBST(root->left);
        if (root->val > maxV) {
            maxV = root->val;
        }
        else return false;
        bool right = isValidBST(root->right);
        return right && left;
    }
};



int main() {

    return 0;
}
