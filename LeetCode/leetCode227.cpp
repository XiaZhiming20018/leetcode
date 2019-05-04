#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
	实现一个基本的计算器来计算一个简单的字符串表达式的值。
	字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

	示例 1:
		输入: "3+2*2"
		输出: 7
	示例 2:
		输入: " 3/2 "
		输出: 1
	示例 3:
		输入: " 3+5 / 2 "
		输出: 5
	说明：
		你可以假设所给定的表达式都是有效的。
		请不要使用内置的库函数 eval。
*/

// 解题思路：先将乘除法计算入栈，同时消除空格，再做纯加减法

int calculate(string s) {
	vector<int> tmp{};
	vector<char> operate{};
	int result = 0, num = 0;
	bool flag = false;
	s = s + '+';
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			// 下式需要加括号，因为计算顺序导致从左往右时会有溢出
			num = num * 10 + (s[i] - '0');
		else if (s[i] != ' ')
		{
			if (flag == true) {
				int second = tmp.back();
				tmp.pop_back();
				if (operate.back() == '*')
					tmp.push_back(num * second);
				else
					tmp.push_back(second / num);
				operate.pop_back();
				flag = false;
			}
			else
			{
				tmp.push_back(num);		
			}
			num = 0;
			operate.push_back(s[i]);
			if (s[i] == '*' || s[i] == '/')
				flag = true;
		}
	}
	result = tmp[0];
	for (int i = 1; i < tmp.size(); i++)
	{
		if (operate[i - 1] == '-')
			result -= tmp[i];
		else
			result += tmp[i];
	}
	return result;
}