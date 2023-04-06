#include<bits/stdc++.h>


using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* lc, TreeNode* rc) : val(0), left(lc), right(rc) {};

};


class Solution {
public:
// 1.递归法，求对称二叉树
    // bool compare(TreeNode* lc, TreeNode* rc) {
    //     if (lc==NULL && rc==NULL) return true;
    //     else if (lc!=NULL && rc==NULL) return false;
    //     else if (lc==NULL && rc!=NULL) return false;
    //     else if (lc->val != rc->val) return false;
    //     else {
    //         bool inSame = compare(lc->right, rc->left);
    //         bool outSame = compare(lc->left, rc->right);
    //         return inSame && outSame;
    //     } 
    // }

    // bool isSymmetric(TreeNode* root) {
    //     if (!root) return false;
    //     bool isSame = compare(root->left, root->right);
    //     return isSame;
    // }

    // 2.迭代法
    bool isSymmetric(TreeNode* root) {
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()) {
            TreeNode* lc = q.front(); q.pop();
            TreeNode* rc = q.front(); q.pop();
            if (!lc && !rc)  continue;// 如果左右子树均为空在，则继续
            
            // 如果左右子树只有一个不为空，或者都不为空但数值不同，返回false
            if (lc == NULL || rc==NULL || lc->val != rc->val)  return false;
            //否则这左右子树相等的情况，继续遍历
            else {
                q.push(lc->left);
                q.push(rc->right);
                q.push(lc->right);
                q.push(rc->left);
            }
        }
        return true;
    }   
};



int main() {

    return 0;
}

