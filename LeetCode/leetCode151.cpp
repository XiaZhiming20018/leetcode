#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
	����һ���ַ����������ת�ַ����е�ÿ�����ʡ�

		ʾ�� 1��
			����: "the sky is blue"
			���: "blue is sky the"
		
		ʾ�� 2��
			����: "  hello world!  "
			���: "world! hello"
			����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
		
		ʾ�� 3��
			����: "a good   example"
			���: "example good a"
			����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����

		˵����
			�޿ո��ַ�����һ�����ʡ�
			�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
			����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����


		���ף�
			��ѡ�� C ���Ե��û�����ʹ�� O(1) ����ռ临�Ӷȵ�ԭ�ؽⷨ��
*/


// ��˼·ʹ��ջ���д洢�ַ�����ִ����ʱ��140 ms
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

// ��Ϊ��վ���Ž⡣���о����Ĳ���һ��
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

