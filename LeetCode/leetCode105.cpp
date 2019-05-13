#include "pch.h"
#include "allHeader.h"
using std::vector;
using std::map;
using std::pair;
/*
	105. 从前序与中序遍历序列构造二叉树
		
		根据一棵树的前序遍历与中序遍历构造二叉树。

	注意:
		你可以假设树中没有重复的元素。

	例如，给出
		前序遍历 preorder = [3,9,20,15,7]
		中序遍历 inorder = [9,3,15,20,7]
		返回如下的二叉树：

			3
		   / \
		  9  20
			/  \
		   15   7
*/

// 按照重建二叉树的规则即可

TreeNode *pre_order(int leftpre, int rightpre, int leftin, int rightin, vector<int> &pre, vector<int> &in) {
	if (leftpre > rightpre || leftin > rightin) 
		return nullptr;
	TreeNode *root = new TreeNode(pre[leftpre]);
	int rootin = leftin;
	while (rootin <= rightin && in[rootin] != pre[leftpre]) 
		rootin++;
	int left = rootin - leftin;
	root->left = pre_order(leftpre + 1, leftpre + left, leftin, rootin - 1, pre, in);
	root->right = pre_order(leftpre + left + 1, rightpre, rootin + 1, rightin, pre, in);
	return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
}



// 网站最优解
// 主要是建立的map 提高查找速度

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// map提高中序数组查找速度
		map<int, int> inorderMap;
		for (int i = 0; i < inorder.size(); ++i) {
			inorderMap.insert(pair<int, int>(inorder[i], i));
		}

		TreeNode* root = createTree(inorderMap, preorder, 0, preorder.size() - 1,
			inorder, 0, inorder.size() - 1);
		return root;
	}

	TreeNode* createTree(map<int, int>& inorderMap,
		const vector<int>& preorder, int preBegin, int preEnd,
		const vector<int>& inorder, int inBegin, int inEnd) {

		if (preBegin > preEnd || inBegin > inEnd) return NULL;
		if (preBegin == preEnd || inBegin == inEnd)
			return new TreeNode(preorder[preBegin]);

		TreeNode* root = new TreeNode(preorder[preBegin]);

		// leftChildCnt 表示中序遍历数组中，root左边的节点个数，即左子树的度
		int leftChildCnt = inorderMap[root->val] - inBegin;

		// 如果左子树存在，即root左边有节点
		// if (leftChildCnt > 0) {
		root->left = createTree(inorderMap,
			preorder, preBegin + 1, preBegin + leftChildCnt,
			inorder, inBegin, inBegin + leftChildCnt - 1);
		// }

		// 如果右子树存在，即root右边有节点
		// if (leftChildCnt < inEnd-inBegin) {
		root->right = createTree(inorderMap,
			preorder, preBegin + 1 + leftChildCnt, preEnd,
			inorder, inBegin + leftChildCnt + 1, inEnd);
		// }

		return root;

	}

};