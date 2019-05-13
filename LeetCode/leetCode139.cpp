#include "pch.h"
#include "allHeader.h"
using std::vector;
using std::string;
using std::max;
using std::unordered_set;
/*

139. ���ʲ��

	����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�

	˵����
		���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
		����Լ����ֵ���û���ظ��ĵ��ʡ�

	ʾ�� 1��
		���� : s = "leetcode", wordDict = ["leet", "code"]
		��� : true
		���� : ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��

	ʾ�� 2��
		���� : s = "applepenapple", wordDict = ["apple", "pen"]
		��� : true
		���� : ���� true ��Ϊ "applepenapple" ���Ա���ֳ� "apple pen apple"��
		ע��������ظ�ʹ���ֵ��еĵ��ʡ�

	ʾ�� 3��
		���� : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
		��� : false

*/

// ��̬�滮

// ִ����ʱ: 8 ms, ��Word Break��C++�ύ�л�����99.51% ���û�
// �ڴ����� : 9.1 MB, ��Word Break��C++�ύ�л�����83.93% ���û�

bool wordBreak(string s, vector<string>& wordDict) {
	// ʹ�� ��ϣ���� �ܹ���������ʱ��
	unordered_set<string> m(wordDict.begin(), wordDict.end());
	vector<bool> state(s.size() + 1, false);
	state[0] = true;
	// ÿ�β�����Ҫ��s[0]��ʼ��������ΪwordDict�е��ַ������������޵ġ�ֻ��Ҫ��i-maxWordLength��ʼ�����Ϳ�����
	int maxWordLength = 0;
	for (size_t i = 0; i < wordDict.size(); i++){
		maxWordLength = max(maxWordLength, (int)wordDict[i].size());
	}

	for (int i = 1; i <= s.size(); i++){
		for (int j = max(i - maxWordLength, 0); j < i; j++) {
			if (state[j] && m.find(s.substr(j, i - j)) != m.end()) {
				state[i] = true;
				break;
			}
		}
	}
	return state[s.size()];
}