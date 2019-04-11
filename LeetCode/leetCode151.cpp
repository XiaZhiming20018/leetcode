#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
	给定一个字符串，逐个翻转字符串中的每个单词。

		示例 1：
			输入: "the sky is blue"
			输出: "blue is sky the"
		
		示例 2：
			输入: "  hello world!  "
			输出: "world! hello"
			解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
		
		示例 3：
			输入: "a good   example"
			输出: "example good a"
			解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

		说明：
			无空格字符构成一个单词。
			输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
			如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。


		进阶：
			请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
*/


// 下思路使用栈进行存储字符串，执行用时：140 ms
string reverseWords(string s) {
	stack<string> res;
	string tmp{};
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			tmp += s[i];
			if ((i + 1 != s.size() && s[i + 1] == ' ') || i + 1 == s.size()) {
				res.push(tmp);
				tmp.clear();
			}
		}
	}
	string result{};
	while (!res.empty())
	{
		result = result + res.top() + " ";
		res.pop();
	}
	if (!result.empty())
		result.erase(result.size() - 1);
	return result;
}

// 下为网站较优解。。感觉做的不是一题
void reverseWords(string &s) {
	s += " ";
	vector<string> v;
	string ins = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (ins == "")continue;
			v.push_back(ins);
			ins = "";
		}
		else {
			ins += s[i];
		}

	}
	ins = "";
	for (int i = v.size() - 1; i >= 0; i--) {
		ins += v[i] + " ";
	}
	ins.erase(ins.end() - 1);
	swap(ins, s);
}

