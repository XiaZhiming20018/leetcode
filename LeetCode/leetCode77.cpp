#include "pch.h"
#include "allHeader.h"
using namespace std;
/*
Combinations  ���

������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�

ʾ��:
����: n = 4, k = 2
���:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// ������һ���㷨˼�룬�ݹ�͵������㷨ʵ���ֶ�

// �ݹ��㷨

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



//�����㷨