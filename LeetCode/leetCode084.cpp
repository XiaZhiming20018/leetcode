#include "pch.h"
#include "allHeader.h"

using std::vector;
using std::stack;
using std::max;

/*
	84. 柱状图中最大的矩形
	https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*/

// 执行用时: 20 ms, 在Largest Rectangle in Histogram的C++提交中击败了94.26% 的用户
// 内存消耗 : 10.9 MB, 在Largest Rectangle in Histogram的C++提交中击败了5.92% 的用户

// 使用单调栈

int largestRectangleArea(vector<int>& heights) {
	heights.push_back(0);
	stack<int> stk{};
	int maxArea = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		while (!stk.empty() && heights[i] < heights[stk.top()])
		{
			int top = stk.top();
			stk.pop();
			maxArea = max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
		}
		// 栈中存放的是数组的索引
		stk.push(i);
	}
	return maxArea;
}



// 网站最优解
static const int _ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		/*
			 84. 使用栈
			 1.若序列有序，则很容易计算max(h[i] *(h.size-i))
			 2.使用栈来构建局部有序，计算局部，保留最大值，达到整体有序，整体最大
			 */

		stack<int > s; s.push(0);
		heights.insert(heights.begin(), 0);
		heights.insert(heights.end(), 0);
		int maxA = 0;

		for (int i = 0; i < heights.size(); i++) {
			while (heights[i] < heights[s.top()])
			{
				int top = s.top();
				s.pop();
				maxA = max(heights[top] * (i - s.top() - 1), maxA);
			}
			s.push(i);
		}
		return maxA;
	}
};