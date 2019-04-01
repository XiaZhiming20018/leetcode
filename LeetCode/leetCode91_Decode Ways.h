#pragma once
#include "allHeader.h"
using namespace std;
/*
һ��������ĸ A-Z ����Ϣͨ�����·�ʽ�����˱��룺
'A' -> 1
'B' -> 2
...
'Z' -> 26
����һ��ֻ�������ֵķǿ��ַ������������뷽����������

ʾ�� 1:
����: "12"
���: 2
����: �����Խ���Ϊ "AB"��1 2������ "L"��12����

ʾ�� 2:
����: "226"
���: 3
����: �����Խ���Ϊ "BZ" (2 26), "VF" (22 6), ���� "BBF" (2 2 6) ��
*/


/*
����һ��������¥�ݵ��㷨��ʮ��̨�ף�ÿ��ֻ����һ���������ܹ��ж����ֽⷨ��
����˼·���������������쳲���������
�����㷨ֻ�Ǵ��벻ͬ������˼·ʹ��ȫһ����
*/

//�㷨���Ž�

int numDecodings(string s) {
	vector<int> dp;
	int n = s.length();
	if (n == 0) 
	{
		return 0;
	}
	dp.push_back(1);
	dp.push_back(s[0] != '0' ? 1 : 0);
	for (int i = 1; i < n; i++) 
	{
		dp.push_back(0);
		if (s[i] > '0' && s[i] <= '9') 
		{
			dp[i + 1] += dp[i];
		}
		if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) 
		{
			dp[i + 1] += dp[i - 1];
		}
	}
	return dp[n];
} 

int numDecodings(string s) 
{
	int n = s.size();
	vector<int> f(n + 1, 0);
	if (s[0] == '0') 
		return 0;
	f[0] = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] != '0') 
			f[i] += f[i - 1];
		int t = (s[i - 1] - '0') * 10 + s[i] - '0';
		if (t <= 26 && t >= 10) 
		{
			if (i == 1) 
				f[i] += f[i - 1];
			else 
				f[i] += f[i - 2];
		}
	}
	return f[n - 1];
}

//����
int numDecodings(string s) {
	if (s.empty())
		return 0;
	vector<int> dp(s.size() + 1, 0);  //��ʼ��Ϊ�ַ������� + 1
	dp[0] = 1;
	for (size_t i = 1; i < dp.size(); i++)
	{
		if (s[i - 1] != '0')
			dp[i] += dp[i - 1];
		if (i > 1 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10")
			dp[i] += dp[i - 2];
	}
	return dp.back();
}

// �ռ临�Ӷ�ΪO(1)
int numDecodings(string s) {
	if (s.empty() || s.front() == '0') 
		return 0;
	int c1 = 1, c2 = 1;
	for (int i = 1; i < s.size(); ++i) 
	{
		if (s[i] == '0') 
			c1 = 0;
		if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) 
		{
			c1 = c1 + c2;
			c2 = c1 - c2;
		}
		else 
			c2 = c1;
	}
	return c1;
}