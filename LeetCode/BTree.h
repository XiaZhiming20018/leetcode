#pragma once
#include "allHeader.h"
using namespace std;

// 二叉树的遍历

// 递归形式 
// 中序遍历
void inorder(TreeNode *root,vector<int> &re)
{
	if (root) {
		inorder(root->left, re);
		re.push_back(root->val);
		inorder(root->right, re);
	}
}

//  前序遍历
void preorder(TreeNode *root, vector<int> &re) {
	if (root) {
		re.push_back(root->val);
		inorder(root->left, re);
		inorder(root->right, re);
	}
}

// 后序遍历
void postorder(TreeNode *root, vector<int> &re) {
	if (root) {
		inorder(root->left, re);
		inorder(root->right, re);
		re.push_back(root->val);
	}
}


// 非递归形式

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> results;
	stack<TreeNode*> stacks{};
	while (true) {
		if (root) {
			stacks.push(root);
			root = root->left;
		}
		else {
			if (stacks.empty())
				return results;
			root = stacks.top();
			stacks.pop();
			results.push_back(root->val);
			root = root->right;
		}
	}
}