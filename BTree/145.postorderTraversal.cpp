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
    // 解法一：递归版  
    // void postorder(TreeNode* cur, vector<int>& vec) {
    //     if (cur) {
    //         // 后序遍历  左右中
    //         postorder(cur->left, vec);
    //         postorder(cur->right, vec);
    //         vec.push_back(cur->val);
            
    //     }
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     postorder(root, res);
    //     return res;
    // }

    // 解法二：迭代版
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode*> st;
    //     // 后序遍历，左右中

    //     if (root == NULL ) return {};

    //     st.push(root);

    //     while(!st.empty()) {
    //         // 后序遍历，相当于前序遍历将中左右变成中右左，res存放的是倒叙的后序遍历结果，最后将res翻转一下即可
    //         TreeNode* cur = st.top();
    //         st.pop();

    //         res.push_back(cur->val); // 中
    //         if (cur->left) st.push(cur->left); // 左 
    //         if(cur->right) st.push(cur->right);// 右
    //     }
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    // 解法三：标记法（迭代版）
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if (!root) return {};
		st.push(root);
		
		while(!st.empty()) {
			TreeNode* cur = st.top();
			if (cur!=NULL) {// 当前中间节点存在
				st.pop();
				st.push(cur);
				st.push(NULL); // 中节点
				
				if (cur->right) st.push(cur->right); // 右
				if (cur->left) st.push(cur->left);	 // 左
			}
			else {
				st.pop();
				cur = st.top();
			    st.pop();
				res.push_back(cur->val);
			}
		}
		return res;
	}
};



int main() {

    return 0;
}
