#include "pch.h"
#include "allHeader.h"

using namespace std;
/*
Word Search  ��������

����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�

ʾ��:

board =[['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']]

���� word = "ABCCED", ���� true.
���� word = "SEE", ���� true.
���� word = "ABCB", ���� false.

*/

extern const vector<vector<char>> board = { 
	{'A','B','C','E'},
	{'S','F','C','S'},
	{'A','D','E','E'} };

// �½��ڴ泬����˼·û��
bool judge(int i, int j, int w, vector<vector<char>> board, string word, vector<vector<bool>> &flag)
{
	if (w == word.size())
		return true;
	if (i < 0 || i >= board.size() || j < 0 || j >= (int)board[0].size() || board[i][j] != word[w] || flag[i][j] == true)
		return false;
	flag[i][j] = true; //�ݹ�ǰ�޸�
	if (judge(i - 1, j, w + 1, board, word, flag))
		return true;
	if (judge(i, j + 1, w + 1, board, word, flag))
		return true;
	if(judge(i + 1, j, w + 1, board, word, flag))
		return true;
	if (judge(i, j - 1, w + 1, board, word, flag))
		return true;

	flag[i][j] = false; //�ݹ��ָ�
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty() || word.empty())
		return false;
	int m = board.size(), n = board[0].size();
	vector <vector<bool>> flag(m, vector<bool>(n,false));  // ��ά����ȫ����ʼ��Ϊ0
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (judge(i, j, 0, board, word, flag))
				return true;
	return false;
}


//����Ϊ���Ž�
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
		// ��ԭ�����в���������лָ��ɽ�ʡ�ڴ�
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