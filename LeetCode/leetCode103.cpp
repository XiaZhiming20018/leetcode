#include "pch.h"
#include "allHeader.h"

using std::vector;
using std::deque;
/*
103. �������ľ���β�α���

	����һ����������������ڵ�ֵ�ľ���β�α����������ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���

	���磺
		���������� [3,9,20,null,null,15,7],

						3
					   / \
					  9  20
						/  \
					   15   7

		���ؾ���β�α������£�
			[
			  [3],
			  [20,9],
			  [15,7]
			]
*/

// ʹ��˫�˶��н��д洢

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	// ��Ϊ�յ�����
	if (!root)
		return {};
	deque<TreeNode*> de{root};
	vector<vector<int>> result{};
	// flag ��ʾ�Ƿ���Ҫ�����鷴ת
	// nums �洢ÿ�е�Ԫ�ظ���
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