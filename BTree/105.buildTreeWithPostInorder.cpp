#include<bits/stdc++.h>


using namespace std;





struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
public:

    TreeNode* Travel(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd) {
        if ((preorderEnd - preorderBegin) == 0) return NULL;
        
        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);

        if ((preorderBegin - preorderEnd) == 1) return root;

        int delimiterIndex;
        for(delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 中序
        // [start, delimiterIndex) [delimiterIndex, end]
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex; 
        
        // [delimiterIndex, end)
        int rightInorderBegin = delimiterIndex+1;
        int rightInorderEnd = inorderEnd; 

        // 后序
        // [preorderBegin + 1, preorderBegin + leftInorder.size())
        int leftPreorderBegin = preorderBegin+1;
        int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin; // 

        // {preorderBegin + leftInorder.size(), preorderEnd)
        int rightPreorderBegin = preorderBegin + 1 + delimiterIndex - inorderBegin;
        int rightPreorderEnd = preorderEnd; // 

        root->left = Travel(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = Travel(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0) return NULL;

        return Travel(preorder, 0, preorder.size(), inorder, 0, inorder.size());

    }
};



int main() {

    return 0;
}
