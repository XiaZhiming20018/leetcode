#pragma once
#include "allHeader.h"
using namespace std;

// �������ı���

// �ݹ���ʽ 
// �������
void inorder(TreeNode *root,vector<int> &re)
{
	if (root) {
		inorder(root->left, re);
		re.push_back(root->val);
		inorder(root->right, re);
	}
}

//  ǰ�����
void preorder(TreeNode *root, vector<int> &re) {
	if (root) {
		re.push_back(root->val);
		inorder(root->left, re);
		inorder(root->right, re);
	}
}

// �������
void postorder(TreeNode *root, vector<int> &re) {
	if (root) {
		inorder(root->left, re);
		inorder(root->right, re);
		re.push_back(root->val);
	}
}


// �ǵݹ���ʽ

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