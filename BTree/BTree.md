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
				cur = cur->left; // 遍历左节点 // 左
			}
            else {//否则，左节点不存在，访问栈顶元素（中间节点即父节点）
                cur = st.top();
                st.pop();
                res.push_back(cur->val);	// 中
                cur = cur->right;			// 右
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



```
vector<int> postorderTraversal(TreeNode* root) {
	if (!root) return {};
	vector<int> res;
	stack<TreeNode*> s;
	
	s.push(root);
	while(!s.empty()) {
    	TreeNode* cur = s.top();
        if (cur!=NULL) {
        	s.pop();
			s.push(cur);
			s.push(NULL);
			if(cur->right) s.push(cur->right);
			if(cur->left) s.push(cur->left);
		}
		else {
			s.pop();
			cur = s.top();
			s.pop();
			res.push_back(cur->val);
			
		}
	}
}
```



## 104 二叉树的最大深度

**题目：**

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

**思路：**

节点高度：该节点到叶子最长简单路径的节点数或者边数（初始时0还是1）

节点深度：该节点到根节点的最简单路径的节点数或者边数

求解树的最大高度：后序遍历

求解数的最大深度：前序遍历

因此根据题意，本质上是求根节点的高度，有两种方法可以求解递归法和迭代法

- 递归法，前序遍历
- 迭代法，层次遍历

解法一：递归法

```cpp
int maxDepth(TreeNode* root) {
	if (!root) return 0;
    int leftHeight = maxDepth(root->left);	// 左
    int rightHeight = maxDepth(root->right);// 右
    int height = max(leftHeight, rightHeight) + 1;//中
    return height;
}
```

解法二：迭代法

```cpp
class　Solution {
public:
	int maxDepth(TreeNode* root) {
    	int height = 0;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()) {
			int size = q.size();
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            height++;
        }
        return height;
    }
};
```



## 111 二叉树最小深度

**题目：**
给定一二叉树，找出其最小深度。

最小深度是指根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

**提示：**

- 树中节点数的范围在 `[0, 105]` 内
- `-1000 <= Node.val <= 1000`

**思路：**
题目求深度，仍然是求节点的高度，不过节点是最小高度，因此有两种遍历方式来进行求解

- **递归版**，后序遍历，左右中，终止条件为两个都不为空或者都为空的时候，返回最小子树的深度+1
- **迭代版**，层次遍历，终止的条件为当左右子树都为空的时候，就截止计数

解法一：递归版 后序遍历

- 1.确定递归输入：求该节点的深度，因此传入参数为该节点
- 2.确定终止条件：当该节点为NULL，停止迭代，返回深度0
- 3.开始单层递归
  - 计算左右子树深度
  - 当左右子树有一个不为空，返回非空子树的深度+1
  - **当左右子树全为空或者全都非空的时候，返回左右子树最小深度+1**

```cpp
class Solution {
public:
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
```

解法二：迭代版 层次遍历 

- 用栈或者队列去保存每层节点
- 若当前层节点至少存在非空子树，则继续遍历，深度加1
- 若当前层有节点没有非空子树，则立即返回，return 深度

```cpp
class Solution {
public:
	int minDepth(TreeNode* root) {
		int dep = 0;// 千万记得给初始化高度赋值，不然编译器会随机赋初值
		queue<TreeNode*> q;
		if (root) q.push(root);
        while(!q.empty()) {
            int size = q.size();
            dep++;
            while(size--) {
				TreeNode* cur = q.front();
                if (!cur->left && !cur->right) return dep;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return dep;
	}
};
```





## 222 完全二叉树的个数

**题目：**

求解完全二叉树的节点个数

**思路：**
**完全二叉树的定义：**除底层节点未满外，其余层数节点均填满，且底层节点均偏左侧

- 满二叉树：节点数为**$2^n-1$**，`n`代表节点深度
- 非满二叉树，递归求解左右子树的数量，**左右子树情况退化为满二叉树和非满二叉树** 

实现方法有两种：

- 层次遍历：普通二叉树的求解方式
  - 迭代版
  - 递归版
- 后序遍历递归：完全二叉树规律求解

### 解法一：层次遍历，迭代版

时间复杂度 $O(n)$ 空间复杂度 $O(n)$

- 统计每层节点数

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;

        if (root) q.push(root);
		
        while(!q.empty()) {
            int size = q.size();
            res += size;
            while(size--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};
```

### 层次遍历 递归版 

时间复杂度 $O(n)$ 空间复杂度 $O(logn)$

- 递归求解左右子树的节点数

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lsize = countNodes(root->left);
        int rsize = countNodes(root->right);
        return 1 + lsize + rsize;
    }
};
```



### 完全二叉树 递归版求解节点数

时间复杂度$O(logn)$ 空间复杂度 $O(logn)$

- 完全二叉树，左链深度 $\ge$右链深度
- 如果是满二叉树，直接计算$num=leftnums+rightnums$
- 否则递归求解左右子树
  - 因为完全二叉树的左右子树可以退化成满二叉树情况，因此可以递归求解
  - 递归顺序以后序遍历为例

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        // 左右子树的初始深度
        int ld = 0; int rd = 0;

        TreeNode* lc = root->left;
        TreeNode* rc = root->right;

        // 求左子树深度
        while (lc) {
            lc= lc->left;
            ld++;
        }

        // 求右子树深度
        while(rc) {
            rc = rc->right;
            rd++;
        }

        if (ld == rd) {
            cout << (2<<ld) -1 << endl;
            return (2 << ld) - 1; // 2^h -1  -> 2 >> n == 2*(n+1)
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
```



## 111 平衡二叉树



**题目：**

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

> 一个二叉树*每个节点* 的左右两个子树的高度差的绝对值不超过 1 。



### 我的递归

**思路：**
递归求每个节点的左右子树高度，如果该节点不满足就返回false，满足就返回true，继续查找父节点

>  不过我没有想到返回-1也可以表明*false*

```cpp
class Solution {
public:

    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int ls = getHeight(node->left);
        int rs = getHeight(node->right);
        return max(ls, rs) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool islb = isBalanced(root->left);
        bool isrb = isBalanced(root->right);
        if (islb && isrb) {
            int ls = getHeight(root->left);
            int rs = getHeight(root->right);
            if (abs(ls - rs) > 1) {
                return false;
            }
        }
        return islb && isrb;
    }
};
```

### 代码随想录版

```cpp
class Solution {
public:

    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int ls = getHeight(node->left);
        if (ls == -1) return -1;
        int rs = getHeight(node->right);
        if (rs == -1) return -1;
        
        return abs(ls-rs) > 1 ? -1 : 1 + max(ls, rs);
    }

    bool isBalanced(TreeNode* root) {
        int isB = getHeight(root);
        return isB == -1 ? false : true;
    }
};
```



## 257 二叉树所有路径

**题目：**
遍历二叉树的所有路径，并返回所有路径

**思路：**

首次体现回溯算法，不仅要遍历所有节点，还要能保存遍历过的路径，因此*前序遍历*是合适的

- 首先考虑终止一条路径的截止条件：当前节点为叶子节点，左右孩子为空节点
- 保存遍历过得节点时，考虑回溯，即子节点向父节点回退时，要将子节点路径弹出
- 其次，父节点放入路径时要在开始阶段，截止条件可以防止NULL节点进行递归，因此一开始就要保存父节点

### 递归第一版：充分体现回溯过程

```cpp
class Solution {
public:

    void getTreePath(TreeNode* cur, vector<int>& path, vector<string>& res) {
        path.push_back(cur->val);
        if (cur->left==NULL && cur->right==NULL) {
            // 抵达叶子结点，终止递归
            string spath;
            for ( int i = 0; i < path.size() -1; i++) {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size()-1]);
            res.push_back(spath);
            return;
        }
        if (cur->left) {    // 左
            getTreePath(cur->left, path, res);
            path.pop_back();//回溯
        }

        if (cur->right) {   // 右
            getTreePath(cur->right, path, res);
            path.pop_back();// 回溯
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        // 前序遍历
        vector<string> ap;
        if (!root) return {};
        vector<int>  path;

        getTreePath(root, path, ap);
        return ap;
    }
};
```

### 递归精简版 ：隐藏回溯过程

```cpp
class Solution {
public:

    void getTreePath(TreeNode* cur, string path, vector<string>& res) {
        path += to_string(cur->val);

        if (cur->left==NULL && cur->right==NULL) {
            res.push_back(path);
            return;
        }
        /*
        这里回溯藏在了path + "->"这里，因为是值传递，没有改变原path值，因此退出递归后即回溯
        */
        if (cur->left) getTreePath(cur->left, path + "->", res); 
        if (cur->right) getTreePath(cur->right, path + "->", res);

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        // 前序遍历
        vector<string> ap;
        if (!root) return {};
        string path;

        getTreePath(root, path, ap);
        return ap;
    }
};
```

### 前序遍历迭代版：用队列或者栈保存路径和遍历节点

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> treeSt;// 保存树的遍历节点
        stack<string> pathSt;   // 保存遍历路径的节点
        vector<string> result;  // 保存最终路径集合
        if (root == NULL) return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty()) {
            TreeNode* node = treeSt.top(); treeSt.pop(); // 取出节点 中
            string path = pathSt.top();pathSt.pop();    // 取出该节点对应的路径
            if (node->left == NULL && node->right == NULL) { // 遇到叶子节点
                result.push_back(path);
            }
            if (node->right) { // 右
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left) { // 左
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};
```





## 404 左叶子之和

**题目：**

给定二叉树的根节点 `root` ，返回所有左叶子之和。

**思路：**

前序遍历递归，**计数条件为左叶子，即当前节点为左节点，且其左右孩子为空**

### 版本一（自己想的）

```cpp
class Solution {
public:
    void getOfLeft(TreeNode* cur, int& sum) {
        if (cur==NULL) return;

        if (cur->left==NULL && cur->right==NULL) {
            return;
        }
        
        getOfLeft(cur->left, sum);
        getOfLeft(cur->right, sum);

        if (cur->left && cur->left->left==NULL && cur->left->right==NULL) {
            sum+=cur->left->val;
        }
    }


    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        getOfLeft(root, sum);
        return sum;
    }
};
```



### 版本二（代码随想录）

```
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if(root->left==NULL && root->right==NULL) return 0;
        int sum = 0;
        int leftSum = sumOfLeftLeaves(root->left);
        if (root->left && root->left->left==NULL && root->left->right==NULL) {
        	leftSum = root->left->val;
        }
        int rightSum = sumOfLeftLeaves(root->right)
        sum = leftSum + rightSum;
        return sum;
    }
};
```



## 513 找树左下角的值

**题目：**

给定一个二叉树的 **根节点** `root`，请找出该二叉树的 **最底层 最左边** 节点的值。

假设二叉树中至少有一个节点。

**提示：**

- 二叉树的节点个数的范围是 `[1,104]`
- `-231 <= Node.val <= 231 - 1` 

**思路：**

明确该题要找的为==**最后一层节点的最左边节点的值**==

- 层次遍历（迭代版）最方便
- 后序遍历（递归版），找左右子树的最左边节点的值

### 方法一：层次遍历

- 一层一层遍历，每一层第一个值保存

```cpp
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		int res = 0;
		queue<TreeNode*> q;
		if (root) q.push(root);
		while(!q.empty()){
			int size = q.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = q.front(); q.pop();
				if (i == 0) res = cur->val;
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
		}
		return res;
	}
};
```



### 方法二：后序遍历

- 确定递归传入参数：树节点，当前深度

- 确定递归截止条件：当为叶节点的时候返回深度和节点值

- 确定单层递归规则：

  - 找左子树的底层最左边节点
  - 找右子树的底层最左边节点
  - 深度回溯
  - 父节点为左右两个树中深度较大值

  

```cpp
// 我的版本
class Solution {
public:
    pair<int, int> findLeftValue(TreeNode* cur, int depth) {
        pair<int, int> res(0, 0);
        if (!cur) {//如果节点不存在，直接返回
            return res;
        }
        // 如果节点为叶节点，保存深度和值
        if (!cur->left && !cur->right) return pair<int, int> (depth, cur->val);

        // 向下找左子树中的最小叶子
        pair<int, int> resl = findLeftValue(cur->left, depth+1);
        // 向下找右子树中的做叶子
        pair<int, int> resr = findLeftValue(cur->right, depth+1);

        res = (res.first >= resl.first ? res : resl);
        res = (res.first >= resr.first ? res : resr);
        return res;
    }

    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> blv = findLeftValue(root, 1); //返回根最底层最左边节点的深度和值
        return blv.second;
    }
};


// 代码随想录版本
class Solution {
public:
    int res = 0;	// 将深度和值提前设为成员变量，满足条件时更新结果
    int max_depth = INT_MIN;
    void findLeftValue(TreeNode* cur, int depth) {
        // 如果节点为叶节点，保存深度和值
        if (!cur->left && !cur->right) 
        {
            if (depth > max_depth ) {
                max_depth = depth;
                res = cur->val;
            }
        }
        // 向下找左子树中的最小叶子
        if (cur->left) findLeftValue(cur->left, depth+1);
        // 向下找右子树中的做叶子
        if (cur->right) findLeftValue(cur->right, depth+1);

    }

    int findBottomLeftValue(TreeNode* root) {
        findLeftValue(root, 0); //返回根最底层最左边节点的深度和值
        return res;
    }
};
```

## 112 路径总和

**题目：**

给你二叉树的根节点 `root` 和一个表示目标和的整数 `targetSum` 。判断该树中是否存在 **根节点到叶子节点** 的路径，这条路径上所有节点值相加等于目标和 `targetSum` 。如果存在，返回 `true` ；否则，返回 `false` 。

**提示：**

- 树中节点的数目在范围 `[0, 5000]` 内
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

**思路：**
需要搜索整棵树的路径，因此采取深度优先遍历（前序遍历）

> 结题技巧是不用计算边之和，而是默认目标值为边之和，一直减当前节点值，最后一个节点如果刚好等于目标值了，则路径找到

- 前序遍历，递归
- 前序遍历，迭代

### 解法一：递归

- 控制边界条件，``root=NULL`
- 确定递归输入参数：当前节点，当前边之和（剩余目标值）
- 确定递归终止条件：
  - 到达叶节点，且剩余目标值和当前节点值相同，返回true
  - 到达也节点，但剩余目标值和当前节点值不同，返回false
- 确定单层递归规律：
  - 当左子树存在，查找左子树。查到立即返回
  - 当右子树存在，查找右子树。查到立即返回

```cpp
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (root->left==NULL && root->right==NULL && sum==root->val) return true;
		if (root->left==NULL && root->right==NULL) return false;
		
		if (root->left) {
			if (hasPathSum(root->left, sum-root->val)) return true;
		}
		if (root->right) {
			if (hasPathSum(root->right, sum-root->val)) return true;
		}
		return false;
 	}
};
```

### 解法二：迭代

还是选取中序遍历，需要注意的是栈或队列里面需要**存放成对的当前节点和路径之和**

> 以下方法直接copy，没仔细阅读

```cpp
class solution {
public:
    bool haspathsum(TreeNode* root, int sum) {
        if (root == null) return false;
        // 此时栈里要放的是pair<节点指针，路径数值>
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> node = st.top();
            st.pop();
            // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
            if (!node.first->left && !node.first->right && sum == node.second) return true;

            // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
            if (node.first->right) {
                st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
            }

            // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
            if (node.first->left) {
                st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
            }
        }
        return false;
    }
};
```



## 106 从中序与后续遍历序列构造二叉树

**题目：**根据一棵树的中序遍历与后序遍历构造二叉树。

注意: 你可以假设树中没有重复的元素。

例如，给出

- 中序遍历 inorder = [9,3,15,20,7]
- 后序遍历 postorder = [9,15,7,20,3] 返回如下的二叉树：

**思路：**

中序：左中右，中的前一个元素为左

后序：左右中，最后一个元素为中，中前面一个元素为右

通过后续找到中间节点，再通过中序（前序）找左节点，最后通过后序找右节点

可以大致分为7步：

1. 判断当前是否为空树，如果是空树，返回NULL
2. 找到根节点，给构建根节点
3. 如果根节点为叶子节点，立即返回该节点
4. 从中序（前序）中找到分割点（delimiterIndex）
5. 分割中序->左中序，右中序
   - 确定区间循环不变量 --> 左闭右开
   - 左中序 -> `[当前中序开始，当前中序分割点)`
   - 右中序 -> `[分割点后一位， 当前中序末尾)`
6. 分割后序 -> 左后序，右后序
   - 确定区间循环不变量 --> 左闭右开
   - 剔除后序最后一个元素（根节点，已用过）
   - 左后序 -> `[当前后序开始， 与左前序相等大小位置) `
   - 右后序 -> `[与左前序相等大小位置，当前后序末尾)`
7. 遍历左右节点

### 中后序递归（新切割数组法）

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 1.如果树为空，返回NULL
        if (inorder.size() == 0) return NULL;

        // 2.树不为空，则后序数组的最后一个数为根节点（中节点）
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);

        // 如果为叶子则返回root
        if (postorder.size()==1) return root;

        // 3.找切割点
        int delimiterIndex = 0;// 
        // 遍历中序数组
        for ( ; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == postorder[postorder.size()-1])
                break;
        }

        // 4.分割中序数组
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        // 5.分割后序数组
        postorder.resize(postorder.size()-1);// 后序数组的最后一个元素用过，剔除

        // 分割的左前序和左后序必然相等，因此以根节点为界，必然是先访问完左子树，再访问右子树
        // 左前序就是左子树，左后序就是右子树
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        // 6.递归将左右节点归位

        // 左后序的最后一个元素就是左节点
        root->left = buildTree(leftInorder, leftPostorder);
        // 右后序的最后一个元素就是右节点（下一个中节点）
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};
```

### 前后序递归（前后指针法）

>  前后序与中后序类似

```cpp
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
```



## 19 最大二叉树

**题目：**

给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

- 二叉树的根是数组中的最大元素。
- 左子树是通过数组中最大值左边部分构造出的最大二叉树。
- 右子树是通过数组中最大值右边部分构造出的最大二叉树。

通过给定的数组构建最大二叉树，并且输出这个树的根节点。

**思路：**

每次找数组中的最大数，保存索引与数值，左边数组为左子树，右边数组为右子树，**注意点在控制边界条件**

- 当前数组为空，返回NULL
- 当前数组只有一个元素，立即返回该节点
- 当前数组有多个元素，开始单层递归

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int nb, int ne) {
        if ((ne - nb) == 0) return NULL;
        int maxV = 0;
        int maxI = 0;
        for(int i = nb; i < ne; i++ ) {
            if (maxV <= nums[i]) {
                maxV = nums[i];
                maxI = i;
            }
        }
        
        TreeNode* root = new TreeNode(maxV);
        if ((nb - ne)==1) return root;

        root->left = buildTree(nums, nb, maxI);
        root->right = buildTree(nums, maxI+1, ne);
        return root;
        
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());
    }
};
```

## 617.合并二叉树

**题目：**

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

**思路：**
将两个重叠的节点，数值相加，返回到新的节点上，**注意点在控制边界条件**

- 如果两个树的相同节点都为空，返回NULL
- 如果两个树有一个节点为空，返回非空节点
- 如果两个树都不为空，**新的节点数值为两个节点和**
- 开始遍历该节点的左右节点

> 技巧，直接用原有节点作为新的节点，更新该节点

```cpp
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return NULL;
        if (!root1 && root2) return root2;
        if (root1 && !root2) return root1;
        // 当两个节点均有值，新根为两个值相加
        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    } 
};
```

## 700 二叉搜索树

**题目：**

给定==二叉搜索树（BST）==的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

**思路：**
普通二叉树的搜索，直接`dfs`遍历每个节点，如果找到，立即返回该节点，

但是**二叉搜索树**是有序的，因此可以采取类似二分法的方式，以节点值与目标值的大小来判断搜索左子树还是右子树

> 二叉搜索树是一个有序树：
>
> - 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
> - 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
> - 它的左、右子树也分别为二叉搜索树

方法有两种：

- 递归法
- 迭代法

### 解法一：递归法

- 判断当前节点与目标值的大小
  - 大于，遍历左子树
  - 小于，遍历右子树
  - 相等，返回该节点
- 当返回节点不为空时，直接返回

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;

        if (root->val==val) return root;
        
        TreeNode* result = NULL;
        if (root->val > val) result = searchBST(root->left, val);
        if (root->val < val) result = searchBST(root->right, val);
        return result;
        
    }
};
```

### 解法二：迭代版

- 由于二叉搜索树的有序性，因此找的路径唯一，不需要回溯，因此就不用栈和队列了

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
};
```



## 98 验证二叉搜索树

**题目：**

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

- 节点的左子树只包含**小于**当前节点的数。
- 节点的右子树只包含**大于**当前节点的数。
- 所有左子树和右子树自身必须也是二叉搜索树。

**提示：**

- 树中节点数目范围在`[1, 104]` 内
- `-231 <= Node.val <= 231 - 1`

**思路：**
**二叉搜索树**的特性是：==中序遍历一定是单调的==

- 判断该树的中序遍历是否有序即可验证二叉搜索树

- 两种思路：

  1. 递归版
     - 数组保存遍历节点数值，判断数组是否有序
     - 比较上一节点和当前节点的数值是否有序
       - 树节点双指针
       - 数值指针
  2. 迭代版

### 递归版（数值int指针）

```cpp
class Solution {
public：
	long long maxV = LONG_MIN;// 与树中最小元素相关，若最小元素为LONG_MIN，这该方法不适用
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		
		bool left = isValidBST(root->left);
		if(root->val > maxV) {
			maxV = root->val;
		}
		else return false;
		bool right = isValidBST(root->right);
		return left && right;
	}
};
```

### 递归版（树节点双指针）

> 该方法具有普适性

```cpp
class Solution {
public:
	TreeNode* pre = NULL;
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		
		bool left = isValidBST(root->left);
		if (pre!=NULL && pre->val >= root->val ) return false;
		pre = root;
		bool right = isValidBST(root->right);
		
		return left && right;
	}
};
```

### 迭代版(中序遍历)

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // 记录前一个节点
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;                // 左
            } else {
                cur = st.top();                 // 中
                st.pop();
                if (pre != NULL && cur->val <= pre->val)
                return false;
                pre = cur; //保存前一个访问的结点

                cur = cur->right;               // 右
            }
        }
        return true;
    }
};
```



## 530 二叉搜索树的最小绝对差

**题目：**

给你一个二叉搜索树的根节点 `root` ，返回 **树中任意两不同节点值之间的最小差值** 。

差值是一个正数，其数值等于两值之差的绝对值。

**提示：**

- 树中节点的数目范围是 `[2, 104]`
- `0 <= Node.val <= 105`

**思路：**
二叉搜索树，两个节点的最小绝对差肯定发生中序遍历下的连续两个节点之间，因此，只需要中序遍历整个树，保存最小的差

- 递归法（双指针）
- 迭代法（中序遍历）
  - 统一写法
  - 独立写法 
  - 看二叉树遍历方法

### 解法一：递归法（双指针）

- 提前指定最小值为节点数值类型的最大值
- 按中序遍历数组，更新最小值

```cpp
class Solution {
public:
    int minV = INT_MAX;
    TreeNode* pre = NULL;
    int getMinimumDifference(TreeNode* root) {
        if (!root) return -1;

        int left = getMinimumDifference(root->left);

        if (pre!=NULL){
            minV = min(abs(pre->val - root->val), minV);
        }
        pre = root;
        int right = getMinimumDifference(root->right);
        // 由于minV设置的成员变量，因此不需要再比较left和right
        return minV;
    }
};
```

### 解法二：迭代法（双指针）

```cpp
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
```



## 501 二叉搜索树中的众数

**题目：**

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

- 结点左子树中所含结点的值**小于等于**当前结点的值
- 结点右子树中所含结点的值**大于等于**当前结点的值
- 左子树和右子树都是二叉搜索树

**提示：**

- 树中节点的数目在范围 `[1, 104]` 内
- `-105 <= Node.val <= 105`

**思路：**

- 二叉树是有序数列，因此采用中序遍历进行

- 其次，需要保存二叉树中节点出现的最大频率和当前值频率
- 保存最大频率的节点，如果最大频率更新，重新保存vector结果

### 递归法（双指针）

- 初始化最大频率，当前频率，前节点，返回结果
- 中序遍历二叉搜索树
- 更新最大频率和返回结果

```cpp
class Solution {
public:
    unordered_map<int, int> um;
    TreeNode* pre;
    int size = 0;
    int maxsize = 0;
    vector<int> res;

    void Travel(TreeNode* cur) {
        if (!cur) return;

        Travel(cur->left);	// 左

        // 中
        if (pre==NULL) {
            size=1;
        }
        else if (pre->val == cur->val) {
            size++;
        }
        else size = 1;

        pre = cur;
        um[pre->val]++;
        
        if (size == maxsize) res.push_back(pre->val);
        else if (size > maxsize) {
            maxsize = size;
            res.clear();
            res.push_back(pre->val);
        }

        Travel(cur->right); // 右
        return;
    }

    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        Travel(root);
        cout << maxsize << endl;
        return res;
    }
};
```



## 236 二叉树的最近公共祖先

**题目：**

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

**提示：**

- 树中节点数目在范围 `[2, 105]` 内。

- `-109 <= Node.val <= 109`

- **所有 `Node.val` `互不相同` 。**

- `p != q`
- **`p` 和 `q` 均存在于给定的二叉树中。**

**思路：**
首先，需要自底向上去找公共祖先，**后序遍历是**一个最佳选择方式。

其次，需要确认返回条件，即当==找到q或p节点的时候，就需要返回当前节点==。

最后，左右子树返回值进行**回溯逻辑处理中节点**

- **当左右子树返回值均不为空，意味`q`和`p`均在此树中**

- **当左右子树有一个不为空，说明至少有一个节点在非空子树中**

  - 若包含两个节点，退化为情况一的下一次处理情况

  - 若包含一个节点，则退化为情况一

    > 情况1：q,p为类似叶子节点，在左右两个子树中
    >
    > 情况2：q，p有一个为根节点

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果是空节点，直接返回NULL
        if (!root) return root; 
        if (root == q || root == p) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 中
        if (left && right) return root;
        if (left && !right) return  left;
        if (!left && right) return right;
        return NULL;
    }
};
```

## 235 二叉搜索树的最近公共祖先

**题目：**

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

**思路：**
二叉搜索树的特性是 **`左子树 < 中 < 右子树`**，利用其特征可以从上往下确定唯一搜索路径。

- 最近公共祖先一定在`[p,q]`之间
- **区间之外，`q,p`两节点只可能在同一子树下**，这是二叉搜索树的特性

### 递归法

- 如果当前节点大于`p,q`值，找左子树，反之，找右子树
- 节点符合要求，return该节点
- 只要节点不为空，该节点就是最近公共祖先。

```cpp
class Solution {
private:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == NULL) return cur;
                                                        // 中
        if (cur->val > p->val && cur->val > q->val) {   // 左
            TreeNode* left = traversal(cur->left, p, q);
            if (left != NULL) {
                return left;
            }
        }

        if (cur->val < p->val && cur->val < q->val) {   // 右
            TreeNode* right = traversal(cur->right, p, q);
            if (right != NULL) {
                return right;
            }
        }
        return cur;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};
```



## 707 二叉搜索树的插入操作

**题目：**

给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据保证，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式**，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果**。

**提示：**

- 树中的节点数将在 `[0, 104]`的范围内。
- `-108 <= Node.val <= 108`

- 所有值 `Node.val` 是 **独一无二** 的。
- `-108 <= val <= 108`
- **保证** `val` 在原始BST中不存在。

**思路：**

最简单思路是找到符合二叉搜索树特性的空节点，直接插入即可

- 不断搜索`val`在树中的区间，即`[left, right]`，在区间内找到一个空节点，直接插入即可
- 当`val`大于当前节点，找左子树
- 当`val`小于当前节点，找右子树
- 当前节点为空，直接插入新节点`val`，每次遍历需要保存当前节点的父节点

### 递归法

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode (val);
            return root;
        }
        
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        }

        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
```



### 迭代法

- 保存父节点，当遇到空节点位置时，创建新节点，判断父节点与`val`的大小关系，插入

```cpp
class Solution {
private:
    TreeNode* parent;
    void traversal(TreeNode* cur, int val) {
        if (cur == NULL) {
            TreeNode* node = new TreeNode(val);
            if (val > parent->val) parent->right = node;
            else parent->left = node;
            return;
        }
        parent = cur;
        if (cur->val > val) traversal(cur->left, val);
        if (cur->val < val) traversal(cur->right, val);
        return;
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        parent = new TreeNode(0);
        if (root == NULL) {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
};
```



## 450 删除二叉搜索树中的节点

**题目：**
给定一个二叉搜索树的根节点 **root** 和一个值 **key**，删除二叉搜索树中的 **key** 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

1. 首先找到需要删除的节点；
2. 如果找到了，删除它。

**提示：**

- 节点数的范围 `[0, 104]`.
- `-105 <= Node.val <= 105`
- 节点值唯一
- `root` 是合法的二叉搜索树
- `-105 <= key <= 105`

**思路：**
因为二叉搜索树的有序性，因此只需找到比删除的节点大一点的节点，替换即可，查找查找替换节点分以下几种情况：

1. 节点无左右节点，当前节点直接为NULL，即删除
2. 节点只有左子树，直接将左子树链接过来，即删除
3. 节点有右子树，从右子树中找到左链最后一个节点（该节点只可能有右子树），与删除节点交换数值，并将替换节点替换为它的右子树

### 递归法

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* _hot  = NULL;
	TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

		if (root->val > key) {
		// key在左子树中，继续查找左子树
			_hot = root;
			root->left = deleteNode(root->left, key);
		}
		else if (root->val < key) {
		// key在右子树中，继续查找右子树
			_hot = root;
			root->right = deleteNode(root->right, key);
		}
		else {
		// 查到key节点了
			// 情况1：节点无左孩子，当前节点直接为右孩子
			if (root->left == NULL) {
                // cout << root->val << " " << key <<endl;
				root = root->right;
			} 
			// 情况2：节点无右孩子
			else if (root->right == NULL) {
				root = root->left;
			}
			
			// 情况3：节点有两个孩子
			else {
				// 找替换节点
                cout << root->val ;
				TreeNode* cur = root->right;
                _hot = root;
				while(cur->left){
					_hot = cur;
					cur = cur->left;
				}
                
                // 交换查找节点和替换节点的值
				swap(root->val, cur->val);
        
                if (_hot->right == cur) {// 如果替换节点是查找节点的右孩子
                   _hot->right = cur->right;
                    return root;
                }
    
				// // 将替换节点的右子树接在父节点上,这一步相当于把替换节点独立出来，即删除
                _hot->left = cur->right;

			}
		}
        return root;
	}
};
```

## 669 修剪二叉搜索树

**题目：**

给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

**提示：**

- 树中节点数在范围 `[1, 104]` 内
- `0 <= Node.val <= 104`
- 树中每个节点的值都是 **唯一** 的
- 题目数据保证输入是一棵有效的二叉搜索树
- `0 <= low <= high <= 104`

**思路：**

- 如果当前节点小于左边界，从当前节点右子树中找左边界
- 如果当前节点大于右边界，从当前节点左子树中找右边界
- 如果当前节点在边界内，寻找左右边界

```
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return NULL;

		if (root->val < low) {
		// 如果当前节点小于左边界，从当前节点右子树中找左边界
			TreeNode* left = trimBST(root->right, low, high);
            return left;
			
		}
		else if (root->val > high) {
		// 如果当前节点大于右边界，从当前节点左子树中找右边界
			TreeNode* right = trimBST(root->left, low , high);
            return right;
		}
        else {
        // 如果当前节点在边界内，寻找左右边界
            root->left = trimBST(root->left, low, high);
		    root->right = trimBST(root->right, low, high);
        }
		return root;
    }
};
```



## 108 将有序数组转化二叉搜索树

**题目：**

将一个按照升序排列的有序数组，转换为一棵**高度平衡二叉搜索树**。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

**思路：**
只需要从数组中间找父节点，左右两个剩余数组构建左右子树即可

> 答案不唯一指的是当数组为偶数是选奇数还是偶数构建父节点

```cpp
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};
```



## 538 把二叉搜索树转换为累加树

**题目：**

给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每**个节点 `node` 的新值等于原树中大于或等于 `node.val` 的值之和。**

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。 节点的右子树仅包含键 大于 节点键的节点。 左右子树也必须是二叉搜索树。

**思路：**
由于题目没有说累加树也是二叉搜索树，因此只需要改变节点数值即可

- node新值为其与大于它的节点之和，即中序遍历下，从右向左依次相加
- 本题递归思想与中序遍历类似，不过是右中左开始遍历

```cpp
class Solution {
public:
    int sum = 0;
    void converSumTree(TreeNode* cur) {
        if (cur==NULL) return;
        
        converSumTree(cur->right);	// 右
        sum += cur->val;	// 保存大于中节点之和
        cur->val = sum;		// 更新中节点数值
        converSumTree(cur->left);	// 左
        return;
    }


    TreeNode* convertBST(TreeNode* root) {
        converSumTree(root);
        return root;
    }
};
```

