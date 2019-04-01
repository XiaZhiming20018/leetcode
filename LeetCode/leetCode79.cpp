#include "pch.h"
#include "allHeader.h"

using namespace std;
/*
Word Search  单词搜索

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =[['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

*/

extern const vector<vector<char>> board = { 
	{'A','B','C','E'},
	{'S','F','C','S'},
	{'A','D','E','E'} };

// 下解内存超出，思路没错
bool judge(int i, int j, int w, vector<vector<char>> board, string word, vector<vector<bool>> &flag)
{
	if (w == word.size())
		return true;
	if (i < 0 || i >= board.size() || j < 0 || j >= (int)board[0].size() || board[i][j] != word[w] || flag[i][j] == true)
		return false;
	flag[i][j] = true; //递归前修改
	if (judge(i - 1, j, w + 1, board, word, flag))
		return true;
	if (judge(i, j + 1, w + 1, board, word, flag))
		return true;
	if(judge(i + 1, j, w + 1, board, word, flag))
		return true;
	if (judge(i, j - 1, w + 1, board, word, flag))
		return true;

	flag[i][j] = false; //递归后恢复
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty() || word.empty())
		return false;
	int m = board.size(), n = board[0].size();
	vector <vector<bool>> flag(m, vector<bool>(n,false));  // 二维数组全部初始化为0
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (judge(i, j, 0, board, word, flag))
				return true;
	return false;
}


//以下为最优解
static const auto x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0) return false;

		mh = board.size();
		mw = board[0].size();

		for (int y = 0; y < mh; y++) {
			for (int x = 0; x < mw; x++) {
				if (search(board, word, 0, x, y)) return true;
			}
		}

		return false;
	}

	bool search(vector<vector<char>>& board, const string &word, int d, int x, int y) {
		if (x < 0 || x == mw ||	y < 0 || y == mh ||	board[y][x] != word[d])
			return false;
		if (d == word.size() - 1) return true;
		// 在原数组中操作，后进行恢复可节省内存
		char backup = board[y][x];
		board[y][x] = 0;
		bool found = search(board, word, d + 1, x + 1, y)
			|| search(board, word, d + 1, x - 1, y)
			|| search(board, word, d + 1, x, y + 1)
			|| search(board, word, d + 1, x, y - 1);
		board[y][x] = backup;
		return found;
	}
private:
	int mw;
	int mh;
};