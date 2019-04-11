#pragma
#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

		例如:
		给定二叉树: [3,9,20,null,null,15,7],

			3
		   / \
		  9  20
			/  \
		   15   7
		返回其层次遍历结果：

		[
		  [3],
		  [9,20],
		  [15,7]
		]
*/

/*
	我的思路：使用队列，并进行计数
*/

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> result;
	deque<TreeNode*> temp{};
	if (root)
		temp.push_back(root);
	int i = 1;

	while (!temp.empty())
	{
		vector<int> tmp;
		int j = 0;
		while (i--)
		{
			tmp.push_back(temp.front()->val);
			if (temp.front()->left) {
				temp.push_back(temp.front()->left);
				j++;
			}
			if (temp.front()->right) {
				temp.push_back(temp.front()->right);
				j++;
			}
			temp.pop_front();
		}
		result.push_back(tmp);
		i = j;
	}
	return result;
}