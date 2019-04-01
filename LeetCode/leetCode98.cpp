#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
	����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

	����һ��������������������������

	�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
	�ڵ��������ֻ�������ڵ�ǰ�ڵ������
	�������������������������Ҳ�Ƕ�����������
	ʾ�� 1:

	����:
		2
	   / \
	  1   3
	���: true
	ʾ�� 2:

	����:
		5
	   / \
	  1   4
		 / \
		3   6
	���: false
	����: ����Ϊ: [5,1,4,null,null,3,6]��
		 ���ڵ��ֵΪ 5 �����������ӽڵ�ֵΪ 4 ��
*/

void bfs(TreeNode* root, vector<int> &tmp) {
	if (root) {
		bfs(root->left, tmp);
		tmp.push_back(root->val);
		bfs(root->right, tmp);
	}
}

bool isValidBST(TreeNode* root) {
	vector<int> tmp{};  // ������� ,��������Ӧ��Ϊ��������
	bfs(root, tmp);
	for (int i = 1; i < tmp.size(); ++i) {
		if (tmp[i] <= tmp[i - 1])
			return false;
	}
	return true;
}


//�����ⷨ

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