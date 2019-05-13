#include "pch.h"
#include "allHeader.h"

using std::vector;
using std::stack;
using std::max;
using std::fill_n;
using std::min;

/*
	85. ������

	����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ��������������

	ʾ��:
		����:
		[
		  ["1","0","1","0","0"],
		  ["1","0","1","1","1"],
		  ["1","1","1","1","1"],
		  ["1","0","0","1","0"]
		]

		���: 6
*/

/* 

	��һ��ʹ������ 084.��״ͼ�����ľ��� �Ľⷨ
	����ÿһ�У���������еĸ߶ȣ����õ���ջ������ľ������

*/

// ִ����ʱ: 24 ms, ��Maximal Rectangle��C++�ύ�л�����97.72% ���û�
// �ڴ����� : 11.4 MB, ��Maximal Rectangle��C++�ύ�л�����59.32% ���û�
int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].size() == 0)
		return 0;
	int columnlen = matrix[0].size();  
	int rowlen = matrix.size();         
	vector<int> h(columnlen + 1);      // �߶�����
	h[columnlen] = 0;
	int max = 0;
	for (int row = 0; row < rowlen; row++) {
		stack<int> s{};
		for (int i = 0; i < columnlen + 1; i++) {
			// ��¼�߶�
			if (i < columnlen) {
				if (matrix[row][i] == '1')
					h[i] += 1;
				else
					h[i] = 0;
			}
			// ����ջ
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

// ��̬�滮�������
// ִ����ʱ: 8 ms, ��Maximal Rectangle��C++�ύ�л�����100.00% ���û�
// �ڴ����� : 10.9 MB, ��Maximal Rectangle��C++�ύ�л�����85.17% ���û�
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
			//����߶�
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
