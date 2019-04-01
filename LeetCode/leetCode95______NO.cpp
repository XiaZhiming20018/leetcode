#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
	给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:
		输入: 3
		输出:
		[
		  [1,null,3,2],
		  [3,2,null,1],
		  [3,1,null,null,2],
		  [2,1,3],
		  [1,null,2,null,3]
		]
		解释:
		以上的输出对应以下 5 种不同结构的二叉搜索树：

		   1         3     3      2      1
			\       /     /      / \      \
			 3     2     1      1   3      2
			/     /       \                 \
		   2     1         2                 3

*/

vector<TreeNode*> *generateTreeDFS(int start, int end) {
	vector<TreeNode*> *subTree = new vector<TreeNode*>()
		;
	if (start > end)
		subTree->push_back(nullptr);
	else
	{
		for (int i = start; i <= end; i++)
		{
			vector<TreeNode*> *leftTree = generateTreeDFS(start, i - 1);
			vector<TreeNode*> *rightTree = generateTreeDFS(i + 1, end);
			for (int j = 0; j < leftTree->size(); j++)
			{
				for (int k = 0; k < rightTree->size(); k++)
				{
					TreeNode *node = new TreeNode(i);
					node->left = (*leftTree)[j];
					node->right = (*rightTree)[k];
					subTree->push_back(node);
				}
			}
		}
	}
	return subTree;
}

vector<TreeNode*> generateTrees(int n) {
	if (n == 0)
		return {};
	return *generateTreeDFS(1, n);
}

/*
	网站最优解
*/
static const int _ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
private:
	vector<TreeNode*> generate(int start, int end) {
		vector<TreeNode*> nodes;
		if (start > end) {
			nodes.push_back(nullptr);
		}
		else if (start == end) {
			nodes.push_back(new TreeNode(start));
		}
		else {
			for (int i = start; i <= end; i++) {
				for (TreeNode* n1 : generate(start, i - 1)) {
					for (TreeNode* n2 : generate(i + 1, end)) {
						TreeNode* n = new TreeNode(i);
						n->left = n1;
						n->right = n2;
						nodes.push_back(n);
					}
				}
			}
		}
		return nodes;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		return n == 0 ? vector<TreeNode*>() : generate(1, n);
	}
};