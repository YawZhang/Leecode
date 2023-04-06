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
    // 迭代版 中序遍历，当左右子树都为空的时候return深度
    // int minDepth(TreeNode* root) {
    //     int res = 0;
    //     queue<TreeNode*> q;

    //     if (root) q.push(root);

    //     TreeNode* cur = root;
    //     while(!q.empty()) {
    //         int size = q.size();
    //         while (size--) {
    //             cur = q.front(); q.pop();
    //             if (!cur->left && !cur->right) return res;
    //             if (cur->left) q.push(cur->left);
    //             if (cur->right) q.push(cur->right);
    //         }
    //         res += 1;
    //     }
    //     return res;
    // }

    // 递归版 左右中，后序遍历
    int getDepth(TreeNode* cur) {
        // 1.确认递归输入参数：要求的是深度，因此输入参数为当前节点
        // 2.确定终止条件：当当前节点为空的时候，返回深度0
        if (cur==NULL) return 0;

        // 3.开始单层递归条件
        int ld = getDepth(cur->left);   // 左
        int rd = getDepth(cur->right);  // 右

        // 当两个子树有一个不为空的时候，该节点的深度都是为不为空的子树+1
        if (cur->left==NULL && cur->right!=NULL) {
            return 1 + rd;
        }
        if (cur->left!=NULL && cur->right==NULL) {
            return 1 + ld;
        }
        // 当两个子树都为空或不为空的时候，返回左右子树最小值+1
        // 若两个子树均为空，左右子树深度最小值都是0，0+1
        // 若两个子树均不为空，左右子树深度的最小值均存在，取最小+1
        return 1 + min(ld, rd);
    }

    int minDepth(TreeNode* root) {
        int depth = getDepth(root);
        return depth;
    }
};


int main() {
    string p = "";
    int a = 5;
    string apth = to_string(a);
    p += '-';
    p += '>';
    p += (char)a;
    cout << p << endl;

    return 0;
}
