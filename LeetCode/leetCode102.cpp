#pragma
#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��

		����:
		����������: [3,9,20,null,null,15,7],

			3
		   / \
		  9  20
			/  \
		   15   7
		�������α��������

		[
		  [3],
		  [9,20],
		  [15,7]
		]
*/

/*
	�ҵ�˼·��ʹ�ö��У������м���
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