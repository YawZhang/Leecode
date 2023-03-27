# 二叉树

## 基本概念

### 二叉树的种类

在解题过程中主要有两种形式：满二叉树和完全二叉树

- **满二叉树**：二叉树只有度为0或者2的结点，且度为0的结点在同一层
- **完全二叉树**：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置
- **二叉搜索树：**有序树
- **平衡二叉搜索树：**又称AVL(Adelson-Velsky and Landis)树，它是一棵空树或者左右两个子树高度差的*绝对值*不超过1
- **红黑树**

### 二叉树的存储方式：

有根节点和左右孩子，可以链式存储，也可以顺序存储。

实现代码如下：

```cpp
class TreeNode { // 链式存储
public:
    int val;// 根节点元素
    TreeNode* left;
    TreeNode* right:
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
}
```

### 二叉树的遍历方式

- 深度优先遍历
  - 前序遍历（递归法，迭代法）
  - 中序遍历（递归法，迭代法）
  - 后序遍历（递归法，迭代法）
- 广度优先遍历
  - 层次遍历（迭代法）

前中后序遍历方式主要看中间节点遍历的位置，

- 前序遍历：==中==左右
- 中序遍历：左==中==右
- 后序遍历：左右==中==



## 二叉树遍历

### 144 前序遍历

遍历顺序：中左右

遍历方式：递归版和迭代版

递归版相对好实现

```cpp
class Solution{
public:
    void preorder(TreeNode* cur, vector<int>& vec) {
        if (cur) {// 当前节点存在时
            vec.push_back(cur->val);	// 中
            preorder(cur->left, vec); 	// 左
            preorder(cur->right, vec);	// 右
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> res;
        preorder(root, res);
        return res;
    }
};
```

迭代版本：观察前序遍历实例可以发现，遍历过程是

- 先访问父节点，再访问左节点，循环过程，直到没有左节点
- 开始访问右节点，重复上一过程，循环遍历
- 因此访问过程可以用栈（先进后出）来保存要访问的节点顺序，栈顶元素为中间节点

```cpp
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if(root == NULL) return {};
		
		TreeNode* cur = root;
		st.push(cur);//栈顶元素保存中间节点
		while(!st.empty()) { // 如果栈为空，说明还有节点没未访问到，继续遍历
			// 此时栈顶元素保存的是中间节点，因此需要先访问，再遍历其左右节点
			cur = st.top();
			st.pop();
			res.push_back(cur->val); // 中 
			
			// 由于栈的先进后出原则，需要先将右节点压入栈中，再将左节点入栈
			if(cur->right) st.push(cur->right);
			if(cur->left) st.push(cur->left);
		}
		return res;
	}
};
```



### 94 中序遍历

遍历顺序：左中右

遍历方式：递归版和迭代版

递归版，实现如下：

```cpp
class Solution {
public:
	void inorder(TreeNode* cur, vector<int>& res) {
		if (cur) { // 中序遍历，左中右
			inorder(cur->left, res);  // 左
			res.push_back(cur->val);  // 中
			inorder(cur->right, res); // 右
		}
	}


	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
};
```

迭代版：同样是使用栈来保存需要访问的节点顺序，栈顶元素为父节点（访问的左孩子，可以视作那一层的父节点）

- 观察中序遍历遍历过程可知，先一直找左节点，直到无左孩子的左节点
- 再之后访问父节点，再遍历其右节点，重复上一过程
- 栈顶元素为父节点

```cpp
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		
		TreeNode* cur = root;
		while(cur != NULL || !st.empty()) {
            // 当栈不为空的时候，说明还有节点未访问，继续比那里
            // 当前节点不为空只是在处理边界条件，可以用单独一个语句 if(!root) return {};
			if (cur!=NULL) {
                // 如果当前中间节点存在，继续访问其左孩子
				st.push(cur); // 栈中保存中间节点
				cur = cur->left; // 遍历左节点
			}
            else {//否则，左节点不存在，访问栈顶元素（中间节点即父节点）
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
		}
        return res;
	}
};
```



### 145 后序遍历

遍历顺序：左右中

遍历方式：递归版和迭代版(栈初始版)、迭代版（标记法）

递归版

```cpp
class Solution {
public:
	void postorder(TreeNode* cur, vector<int>& vec) {
		if(cur) {
			postorder(cur->left, vec);
			postorder(cur->right, vec);
			vec.push_back(cur->val);
		}
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorder(root, res);
		return res;
	}
};
```

迭代版：观察前序遍历和后序遍历的区别，这是中间节点放前面还是放后面遍历，因此，可以在前序遍历的基础上，调换左右孩子遍历顺序，保存的遍历结果为倒叙的后序遍历，因此再反转一下即可。

```cpp
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if (!root) return {};
		
		TreeNode* cur = root;
		st.push(cur);
		while(!st.empty()) {
			cur = st.top();
			st.pop();
			res.push_back(cur->val); 	// 中
			if(cur->left) st.push(cur->left); // 左
			if(cur->right) st.push(cur->right); // 右
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
```

迭代版（标记法）

为了统一迭代版 三种遍历写法

```cpp
class Solution {
public:
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
}
```

