#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;

// 定义二叉树节点结构体  
struct TreeNode {  
    int val;  
    TreeNode* left;  
    TreeNode* right;  
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
};

// 打印二叉树  
void printTree(TreeNode* root) {  
    if (root == nullptr) {  
        return;  
    }  
    cout << root->val << " ";  
    printTree(root->left);  
    printTree(root->right);  
}

// 打印二叉树前缀和  
int printPreorder(TreeNode* root, int n) {  
    if (root == nullptr) {  
        return 0;  
    }  
    int preorderSum = 0;  
    printTree(root);  
    preorderSum += printPreorder(root->left, n);  
    preorderSum += printPreorder(root->right, n);  
    return preorderSum;  
}

// 打印二叉树中序和  
int printInorder(TreeNode* root, int n) {  
    if (root == nullptr) {  
        return 0;  
    }  
    int inorderSum = 0;  
    TreeNode* current = root;  
    while (current != nullptr) {  
        inorderSum += printInorder(current->left, n);  
        current = current->right;  
    }  
    return inorderSum;  
}

// 构建二叉树  
TreeNode* buildTree(const int arr[], int n) {  
    if (n == 0) {  
        return nullptr;  
    }  
    TreeNode* root = new TreeNode(arr[0]);  
    int i = 1;  
    for (int j = 1; j < n; j++) {  
        TreeNode* child = new TreeNode(arr[i]);  
        root->left = child;  
        root->right = child;  
        child->left = nullptr;  
        child->right = nullptr;  
        i++;  
    }  
    return root;  
}

// 读取屏幕输出流  
void readOutputStream(TreeNode* root, const int arr[], int n) {    
    for (int i = 0; i < n; i++) {    
        int val = readInt();    
        TreeNode* node = buildTree(arr, n_arr);    
        if (node != nullptr) {    
            node->val = val;    
            node->left = nullptr;    
            node->right = nullptr;    
        }    
    }    
}    


int main() {  
    const int n = 9;  
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  
    int n_arr = sizeof(arr) / sizeof(arr[0]);  
      
    TreeNode* root = buildTree(arr, n_arr);  
    readOutputStream(root, arr, n_arr);  
      
    cout << "Preorder traversal: ";  
    printPreorder(root, n_arr);  
    cout << endl;  
      
    cout << "Inorder traversal: ";  
    printInorder(root, n_arr);  
    cout << endl;  
      
    cout << "Postorder traversal: ";  
    printPostorder(root, n_arr);  
    cout << endl;  
      
    return 0;  
}
