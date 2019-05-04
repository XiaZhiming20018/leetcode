#include "pch.h"
#include "allHeader.h"

using namespace std;

/*

537. 复数乘法

	给定两个表示复数的字符串。
	返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

	示例 1:
		输入: "1+1i", "1+1i"
		输出: "0+2i"
		解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。

	示例 2:
		输入: "1+-1i", "1+-1i"
		输出: "0+-2i"
		解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。

	注意:
		输入字符串不包含额外的空格。
		输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
*/

// 思路： 先提取出前后数字，再进行公式计算即可
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