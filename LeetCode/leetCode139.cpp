#include "pch.h"
#include "allHeader.h"
using std::vector;
using std::string;
using std::max;
using std::unordered_set;
/*

139. 单词拆分

	给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

	说明：
		拆分时可以重复使用字典中的单词。
		你可以假设字典中没有重复的单词。

	示例 1：
		输入 : s = "leetcode", wordDict = ["leet", "code"]
		输出 : true
		解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

	示例 2：
		输入 : s = "applepenapple", wordDict = ["apple", "pen"]
		输出 : true
		解释 : 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
		注意你可以重复使用字典中的单词。

	示例 3：
		输入 : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
		输出 : false

*/

// 动态规划

// 执行用时: 8 ms, 在Word Break的C++提交中击败了99.51% 的用户
// 内存消耗 : 9.1 MB, 在Word Break的C++提交中击败了83.93% 的用户

bool wordBreak(string s, vector<string>& wordDict) {
	// 使用 哈希索引 能够减少搜索时间
	unordered_set<string> m(wordDict.begin(), wordDict.end());
	vector<bool> state(s.size() + 1, false);
	state[0] = true;
	// 每次并不需要从s[0]开始搜索。因为wordDict中的字符串长度是有限的。只需要从i-maxWordLength开始搜索就可以了
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