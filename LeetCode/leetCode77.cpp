#include "pch.h"
#include "allHeader.h"
using namespace std;
/*
Combinations  组合

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// 回溯是一种算法思想，递归和迭代是算法实现手段

// 递归算法

void ReCombine(vector<vector<int>> &, vector<int> &, int, int, int);

vector<vector<int>> combine(int n, int k) {
	vector<int> tmp{};
	vector<vector<int>> result;
	ReCombine(result, tmp, 1, n, k);
	return result;
}
void ReCombine(vector<vector<int>> &re, vector<int> &tmp, int first, int n, int k) {
	if (k == 0)
	{
		re.push_back(tmp);
		return;
	}
	for (int i = first; i <= n - k + 1; i++)
	{
		tmp.push_back(i);
		ReCombine(re, tmp, i + 1, n, k - 1);
		tmp.pop_back();
	}
}



//迭代算法