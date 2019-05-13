#include "pch.h"
#include "allHeader.h"

using std::vector;
using std::stack;
using std::max;
using std::fill_n;
using std::min;

/*
	85. 最大矩形

	给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

	示例:
		输入:
		[
		  ["1","0","1","0","0"],
		  ["1","0","1","1","1"],
		  ["1","1","1","1","1"],
		  ["1","0","0","1","0"]
		]

		输出: 6
*/

/* 

	这一题使用类似 084.柱状图中最大的矩形 的解法
	对于每一行，求出所在列的高度，利用单调栈求解最大的矩形面积

*/

// 执行用时: 24 ms, 在Maximal Rectangle的C++提交中击败了97.72% 的用户
// 内存消耗 : 11.4 MB, 在Maximal Rectangle的C++提交中击败了59.32% 的用户
int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].size() == 0)
		return 0;
	int columnlen = matrix[0].size();  
	int rowlen = matrix.size();         
	vector<int> h(columnlen + 1);      // 高度数组
	h[columnlen] = 0;
	int max = 0;
	for (int row = 0; row < rowlen; row++) {
		stack<int> s{};
		for (int i = 0; i < columnlen + 1; i++) {
			// 记录高度
			if (i < columnlen) {
				if (matrix[row][i] == '1')
					h[i] += 1;
				else
					h[i] = 0;
			}
			// 单调栈
			if (s.empty() || h[s.top()] <= h[i])
				s.push(i);
			else 
			{
				while (!s.empty() && h[i] < h[s.top()])
				{
					int top = s.top();
					s.pop();
					int area = h[top] * (s.empty() ? i : (i - s.top() - 1));
					if (area > max)
						max = area;
				}
				s.push(i);
			}
		}
	}
	return max;
}

// 动态规划解决方案
// 执行用时: 8 ms, 在Maximal Rectangle的C++提交中击败了100.00% 的用户
// 内存消耗 : 10.9 MB, 在Maximal Rectangle的C++提交中击败了85.17% 的用户
class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> left(n, 0), right(n, n), height(n, 0);
		int maxA = 0;
		for (int i = 0; i < m; i++) {
			int cur_left = 0, cur_right = n;
			//计算高度
			for (int j = 0; j < n; j++) { 
				if (matrix[i][j] == '1') 
					height[j]++;
				else 
					height[j] = 0;
			}
			// compute left (from left to right)
			for (int j = 0; j < n; j++) { 
				if (matrix[i][j] == '1') 
					left[j] = max(left[j], cur_left);
				else { 
					left[j] = 0; 
					cur_left = j + 1; 
				}
			}
			// compute right (from right to left)
			for (int j = n - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') 
					right[j] = min(right[j], cur_right);
				else { 
					right[j] = n; 
					cur_right = j; 
				}
			}
			// compute the area of rectangle (can do this from either side)
			for (int j = 0; j < n; j++)
				maxA = max(maxA, (right[j] - left[j])*height[j]);
		}
		return maxA;
	}
};
