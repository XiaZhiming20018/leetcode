#include "pch.h"
#include "allHeader.h"

using std::vector;
using std::stack;
using std::max;

/*
	84. ��״ͼ�����ľ���
	https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*/

// ִ����ʱ: 20 ms, ��Largest Rectangle in Histogram��C++�ύ�л�����94.26% ���û�
// �ڴ����� : 10.9 MB, ��Largest Rectangle in Histogram��C++�ύ�л�����5.92% ���û�

// ʹ�õ���ջ

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
		// ջ�д�ŵ������������
		stk.push(i);
	}
	return maxArea;
}



// ��վ���Ž�
static const int _ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		/*
			 84. ʹ��ջ
			 1.����������������׼���max(h[i] *(h.size-i))
			 2.ʹ��ջ�������ֲ����򣬼���ֲ����������ֵ���ﵽ���������������
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