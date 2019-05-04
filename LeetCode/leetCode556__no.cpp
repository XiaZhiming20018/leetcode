#include "pch.h"
#include "allHeader.h"

using namespace std;

/*

	556. 下一个更大元素 III

	给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。如果不存在这样的32位整数，则返回-1。

	示例 1:
		输入: 12
		输出: 21

	示例 2:
		输入: 21
		输出: -1
*/

//木有看懂题目意思

int nextGreaterElement(int n) {
	int res = 0;
	int temp = n;
	vector<int> num;
	while (n != 0)
	{
		num.push_back(n % 10);
		n = n / 10;
	}

	int len = num.size();
	int k;
	for (k = 1; k < len; k++)
	{
		if (num[k] < num[k - 1])
		{
			break;
		}
	}
	if (k == len)    
		return -1;

	sort(num.begin(), num.begin() + k, greater<int>());

	for (int j = k - 1; j >= 0; j--)
	{
		if (num[j] > num[k])
		{
			swap(num[j], num[k]);
			break;
		}
	}

	reverse(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++)
	{
		res = res * 10 + num[i];
	}
	if (res > temp) return res;

	return -1;
}

