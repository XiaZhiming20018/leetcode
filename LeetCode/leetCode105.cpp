#include "pch.h"
#include "allHeader.h"
using std::vector;
using std::map;
using std::pair;
/*
	105. ��ǰ��������������й��������
		
		����һ������ǰ�������������������������

	ע��:
		����Լ�������û���ظ���Ԫ�ء�

	���磬����
		ǰ����� preorder = [3,9,20,15,7]
		������� inorder = [9,3,15,20,7]
		�������µĶ�������

			3
		   / \
		  9  20
			/  \
		   15   7
*/

// �����ؽ��������Ĺ��򼴿�

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



// ��վ���Ž�
// ��Ҫ�ǽ�����map ��߲����ٶ�

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// map���������������ٶ�
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

		// leftChildCnt ��ʾ������������У�root��ߵĽڵ���������������Ķ�
		int leftChildCnt = inorderMap[root->val] - inBegin;

		// ������������ڣ���root����нڵ�
		// if (leftChildCnt > 0) {
		root->left = createTree(inorderMap,
			preorder, preBegin + 1, preBegin + leftChildCnt,
			inorder, inBegin, inBegin + leftChildCnt - 1);
		// }

		// ������������ڣ���root�ұ��нڵ�
		// if (leftChildCnt < inEnd-inBegin) {
		root->right = createTree(inorderMap,
			preorder, preBegin + 1 + leftChildCnt, preEnd,
			inorder, inBegin + leftChildCnt + 1, inEnd);
		// }

		return root;

	}

};