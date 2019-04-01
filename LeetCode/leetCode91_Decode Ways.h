#pragma once
#include "allHeader.h"
using namespace std;
/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

示例 2:
输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
*/


/*
这是一个类似爬楼梯的算法（十阶台阶，每次只能走一至两步，总共有多少种解法）
解题思路类似类似于特殊的斐波那契数列
下列算法只是代码不同，解题思路使完全一样的
*/

//算法最优解

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

//网解
int numDecodings(string s) {
	if (s.empty())
		return 0;
	vector<int> dp(s.size() + 1, 0);  //初始化为字符串长度 + 1
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

// 空间复杂度为O(1)
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