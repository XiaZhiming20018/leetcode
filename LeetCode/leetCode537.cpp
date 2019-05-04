#include "pch.h"
#include "allHeader.h"

using namespace std;

/*

537. �����˷�

	����������ʾ�������ַ�����
	���ر�ʾ���ǳ˻����ַ�����ע�⣬���ݶ��� i2 = -1 ��

	ʾ�� 1:
		����: "1+1i", "1+1i"
		���: "0+2i"
		����: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ������Ҫ����ת��Ϊ 0+2i ����ʽ��

	ʾ�� 2:
		����: "1+-1i", "1+-1i"
		���: "0+-2i"
		����: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ������Ҫ����ת��Ϊ 0+-2i ����ʽ��

	ע��:
		�����ַ�������������Ŀո�
		�����ַ������� a+bi ����ʽ�������������� a �� b �ķ�Χ���� [-100, 100] ֮�䡣���ҲӦ������������ʽ��
*/

// ˼·�� ����ȡ��ǰ�����֣��ٽ��й�ʽ���㼴��
vector<int> getInt(string a) {
	int i = 0, aa, bb;
	while (true) {
		if (a[i] == '+')
			break;
		i++;
	}
	string s = a.substr(0, i);
	string ss = a.substr(i + 1, a.size() - i - 2);
	aa = atoi(s.c_str());
	bb = atoi(ss.c_str());
	return vector<int>{aa, bb};
}


string complexNumberMultiply(string a, string b) {
	vector<int> f = getInt(a);
	vector<int> s = getInt(b);
	return to_string(f[0] * s[0] - f[1] * s[1]) + "+" + to_string(f[0] * s[1] + f[1] * s[0]) + "i";
}