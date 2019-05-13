#include "pch.h"
#include "allHeader.h"
using std::string;
using std::vector;
using std::stack;
/*
	224. ����������
	ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ��ֵ��

	�ַ������ʽ���԰��������� ( �������� )���Ӻ� + ������ -���Ǹ������Ϳո�  ��

	ʾ�� 1:
		����: "1 + 1"
		���: 2

	ʾ�� 2:
		����: " 2-1 + 2 "
		���: 3

	ʾ�� 3:
		����: "(1+(4+5+2)-3)+(6+8)"
		���: 23

	˵����
		����Լ����������ı��ʽ������Ч�ġ�
		�벻Ҫʹ�����õĿ⺯�� eval��
*/

// ִ����ʱ : 40 ms, ��Basic Calculator��C++�ύ�л�����45.78% ���û�
// �ڴ�����: 10.9 MB, ��Basic Calculator��C++�ύ�л�����54.13% ���û�

int calculate224(string s) {
	// ʹ�� vector ����stack ��������������Щ
	vector<int> nums{};
	vector<char> symbol{};
	int tmp = 0;
	s += '+'; // ���㴦�����һ����
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
		// ȥ���ɶԵ�����
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
				symbol[symbol.size() - 1] = '+'; // �� �� ������һ���Ӽ��ţ��߼��ж�ʱ�� �� tmp = 0 ���룬�˴���Ϊ������nums�������ӵ�0
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



// ��վ���Ž�

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