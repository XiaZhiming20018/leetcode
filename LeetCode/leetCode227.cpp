#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
	ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ��ֵ��
	�ַ������ʽ�������Ǹ�������+�� - ��*��/ ����������Ϳո�  �� ���������������������֡�

	ʾ�� 1:
		����: "3+2*2"
		���: 7
	ʾ�� 2:
		����: " 3/2 "
		���: 1
	ʾ�� 3:
		����: " 3+5 / 2 "
		���: 5
	˵����
		����Լ����������ı��ʽ������Ч�ġ�
		�벻Ҫʹ�����õĿ⺯�� eval��
*/

// ����˼·���Ƚ��˳���������ջ��ͬʱ�����ո��������Ӽ���

int calculate(string s) {
	vector<int> tmp{};
	vector<char> operate{};
	int result = 0, num = 0;
	bool flag = false;
	s = s + '+';
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			// ��ʽ��Ҫ�����ţ���Ϊ����˳���´�������ʱ�������
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