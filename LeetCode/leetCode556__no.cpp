#include "pch.h"
#include "allHeader.h"

using namespace std;

/*

	556. ��һ������Ԫ�� III

	����һ��32λ������ n������Ҫ�ҵ���С��32λ���������� n �д��ڵ�λ����ȫ��ͬ��������ֵ����n�����������������32λ�������򷵻�-1��

	ʾ�� 1:
		����: 12
		���: 21

	ʾ�� 2:
		����: 21
		���: -1
*/

//ľ�п�����Ŀ��˼

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

