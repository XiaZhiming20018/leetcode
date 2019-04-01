#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
	给定一个二叉树，判断其是否是一个有效的二叉搜索树。

	假设一个二叉搜索树具有如下特征：

	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。
	示例 1:

	输入:
		2
	   / \
	  1   3
	输出: true
	示例 2:

	输入:
		5
	   / \
	  1   4
		 / \
		3   6
	输出: false
	解释: 输入为: [5,1,4,null,null,3,6]。
		 根节点的值为 5 ，但是其右子节点值为 4 。
*/

void bfs(TreeNode* root, vector<int> &tmp) {
	if (root) {
		bfs(root->left, tmp);
		tmp.push_back(root->val);
		bfs(root->right, tmp);
	}
}

bool isValidBST(TreeNode* root) {
	vector<int> tmp{};  // 中序遍历 ,遍历后结果应该为递增序列
	bfs(root, tmp);
	for (int i = 1; i < tmp.size(); ++i) {
		if (tmp[i] <= tmp[i - 1])
			return false;
	}
	return true;
}


//其他解法

class Solution {
public:
	TreeNode* pre;
	bool isValidBST(TreeNode* root) {
		pre = NULL;
		return dfs(root);
	}

	bool dfs(TreeNode* root) {
		if (!root) return true;
		if (!dfs(root->left)) return false;
		if (pre && pre->val >= root->val)
			return false;
		pre = root;
		if (!dfs(root->right))
			return false;
		return true;
	}
};