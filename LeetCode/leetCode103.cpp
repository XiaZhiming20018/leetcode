#include "pch.h"
#include "allHeader.h"

using std::vector;
using std::deque;
/*
103. 二叉树的锯齿形层次遍历

	给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

	例如：
		给定二叉树 [3,9,20,null,null,15,7],

						3
					   / \
					  9  20
						/  \
					   15   7

		返回锯齿形层次遍历如下：
			[
			  [3],
			  [20,9],
			  [15,7]
			]
*/

// 使用双端队列进行存储

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	// 树为空的情形
	if (!root)
		return {};
	deque<TreeNode*> de{root};
	vector<vector<int>> result{};
	// flag 表示是否需要将数组反转
	// nums 存储每行的元素个数
	int flag = 1, nums = 1;
	while (!de.empty())
	{
		int num = 0;
		vector<int> temp{};
		for (int i = 0; i < nums; i++)
		{
			auto it = de.front();
			de.pop_front();
			temp.push_back(it->val);
			if (it->left) de.push_back(it->left),++num;
			if (it->right) de.push_back(it->right),++num;
		}
		nums = num;
		if (flag % 2)
			result.push_back(temp);
		else {
			std::reverse(temp.begin(), temp.end());
			result.push_back(temp);
		}
		flag++;
	}
	return result;
}