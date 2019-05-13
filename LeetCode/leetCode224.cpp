#include "pch.h"
#include "allHeader.h"
using std::string;
using std::vector;
using std::stack;
/*
	224. 基本计算器
	实现一个基本的计算器来计算一个简单的字符串表达式的值。

	字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

	示例 1:
		输入: "1 + 1"
		输出: 2

	示例 2:
		输入: " 2-1 + 2 "
		输出: 3

	示例 3:
		输入: "(1+(4+5+2)-3)+(6+8)"
		输出: 23

	说明：
		你可以假设所给定的表达式都是有效的。
		请不要使用内置的库函数 eval。
*/

// 执行用时 : 40 ms, 在Basic Calculator的C++提交中击败了45.78% 的用户
// 内存消耗: 10.9 MB, 在Basic Calculator的C++提交中击败了54.13% 的用户

int calculate224(string s) {
	// 使用 vector 代替stack ，最后计算结果方便些
	vector<int> nums{};
	vector<char> symbol{};
	int tmp = 0;
	s += '+'; // 方便处理最后一个数
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		else if (s[i] == '(') {
			symbol.push_back('(');
			continue;
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			tmp = tmp * 10 + (s[i] - '0');
			continue;
		}
		else
		{
			if (symbol.empty() || symbol.back() == '(') {
				nums.push_back(tmp);
				symbol.push_back(s[i]);
				tmp = 0;
			}
			else
			{
				if (symbol.back() == '+')
					nums.back() += tmp;
				else
					nums.back() -= tmp;
				symbol.pop_back();
				tmp = 0;
				symbol.push_back(s[i]);
			}
		}
		// 去除成对的括号
		if (symbol.back() == ')') {
			symbol.pop_back();
			symbol.pop_back();
			if (nums.size() > 1) {
				int i = nums.back();
				nums.pop_back();
				if (symbol.back() == '+')
					nums.back() += i;
				else
					nums.back() -= i;
				symbol[symbol.size() - 1] = '+'; // 在 ） 后面会跟一个加减号，逻辑判断时会 将 tmp = 0 加入，此处是为了消除nums中这个多加的0
			}
		}

	}

	int res = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		if (symbol[i - 1] == '+')
			res += nums[i];
		else
			res -= nums[i];
	}
	return res;
}


int _calculate(string s) {
	stack<long> nums{}, ops{};
	long result = 0;
	long num = 0;
	int sign = 1;
	for (char c : s) {
		if (isdigit(c)) {
			num = num * 10 + c - '0';
		}
		else {
			result += num * sign;
			num = 0;
			if (c == '+')
				sign = 1;
			if (c == '-')
				sign = -1;
			if (c == '(') {
				nums.push(result);
				ops.push(sign);
				result = 0;
				sign = 1;
			}
			if (c == ')') {
				result = ops.top() * result + nums.top();

				nums.pop();
				ops.pop();
			}
		}
	}
	result = result + sign * num;
	return result;
}



// 网站最优解

class Solution {
public:
	void compute(stack<int> &number_stack, stack<char> &operation_stack)
	{
		if (number_stack.size() < 2)
			return;
		int num2 = number_stack.top();
		number_stack.pop();
		int num1 = number_stack.top();
		number_stack.pop();
		if (operation_stack.top() == '+')
			number_stack.push(num1 + num2);
		else
			number_stack.push(num1 - num2);
		operation_stack.pop();
	}
	int calculate(string s) {
		static const int STATE_BEGIN = 0;
		static const int NUMBER_STATE = 1;
		static const int OPERATION_STATE = 2;
		stack<int> number_stack;
		stack<char> operation_stack;
		int number = 0;
		int STATE = STATE_BEGIN;
		int compute_flag = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == ' ')
				continue;
			switch (STATE) {
			case STATE_BEGIN:
				if (s[i] >= '0' && s[i] <= '9')
					STATE = NUMBER_STATE;
				else
					STATE = OPERATION_STATE;
				i--;
				break;
			case NUMBER_STATE:
				if (s[i] >= '0' && s[i] <= '9')
					number = number * 10 + s[i] - '0';
				else
				{
					number_stack.push(number);
					if (compute_flag == 1)
						compute(number_stack, operation_stack);
					number = 0;
					i--;
					STATE = OPERATION_STATE;
				}
				break;
			case OPERATION_STATE:
				if (s[i] == '+' || s[i] == '-') {
					compute_flag = 1;
					operation_stack.push(s[i]);
				}
				else if (s[i] == '(') {
					STATE = NUMBER_STATE;
					compute_flag = 0;
				}
				else if (s[i] >= '0' && s[i] <= '9')
				{
					STATE = NUMBER_STATE;
					i--;
				}
				else if (s[i] == ')')
					compute(number_stack, operation_stack);
				break;
			}

		}
		if (number != 0)
		{
			number_stack.push(number);
			compute(number_stack, operation_stack);
		}
		if (number == 0 && number_stack.empty())
			return 0;
		return number_stack.top();
	}
};