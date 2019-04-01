#pragma
#include "allHeader.h"
using namespace std;
#include <queue>

/*
1029. �ɱ� 5 �����Ķ�����ǰ׺

	���������� 0 �� 1 ��ɵ����� A�����Ƕ��� N_i���� A[0] �� A[i] �ĵ� i �������鱻����Ϊһ�������������������Чλ�������Чλ����
	���ز���ֵ�б� answer��ֻ�е� N_i ���Ա� 5 ����ʱ���� answer[i] Ϊ true������Ϊ false��

	ʾ�� 1��
		���룺[0,1,1]
		�����[true,false,false]
		���ͣ���������Ϊ 0, 01, 011��Ҳ����ʮ�����е� 0, 1, 3 ��ֻ�е�һ�������Ա� 5 ��������� answer[0] Ϊ�档
	
	ʾ�� 2��
		���룺[1,1,1]
		�����[false,false,false]

	ʾ�� 3��
		���룺[0,1,1,1,1,1]
		�����[true,false,false,false,true,false]

	ʾ�� 4��
		���룺[1,1,1,0,1]
		�����[false,false,false,false,false]
*/
vector<bool> prefixesDivBy5(vector<int>& A) {
	vector<bool> ans;
	int t = 0;
	for (int n : A) {
		t = (t * 2 + n) % 5;
		ans.push_back(t == 0);
	}
	return ans;
}

/*
	1028. ��������ת�� 

		�������� N������������ "0" �� "1"��ɵ��ַ��������ַ���Ϊ N �ĸ������ƣ�base -2����ʾ��

		�����ַ������� "0"�����򷵻ص��ַ����в��ܺ���ǰ���㡣

		ʾ�� 1��
			���룺2
			�����"110"
			���ͣ�(-2) ^ 2 + (-2) ^ 1 = 2

		ʾ�� 2��
			���룺3
			�����"111"
			���ͣ�(-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3

		ʾ�� 3��
			���룺4
			�����"100"
			���ͣ�(-2) ^ 2 = 4
*/

string baseNeg2(int N) {
	if (N == 0) return "0";
	string r;
	int t = N;
	int k = 1;
	while (t != 0) {
		if (t % 2 == 1) {
			r.push_back('1');
			t -= k;
		}
		else 
			r.push_back('0');
		t /= 2;
		k *= -1;
	}
	reverse(r.begin(), r.end());
	return r;
}

/*
1030. �����е���һ������ڵ� 
		����һ����ͷ�ڵ� head ��Ϊ��һ���ڵ�����������еĽڵ�ֱ���Ϊ��node_1, node_2, node_3, ... ��

		ÿ���ڵ㶼��������һ������ֵ��next larger value�������� node_i������� next_larger(node_i) �� node_j.val��
		��ô���� j > i ��  node_j.val > node_i.val���� j �ǿ��ܵ�ѡ������С���Ǹ������������������ j����ô��һ������ֵΪ 0 ��

		�������������� answer������ answer[i] = next_larger(node_{i+1}) ��

		ע�⣺�������ʾ���У����� [2,1,5] ���������루�������������������л���ʾ����ͷ�ڵ��ֵΪ 2���ڶ����ڵ�ֵΪ 1���������ڵ�ֵΪ 5 ��
*/

vector<int> nextLargerNodes(ListNode* head) {
	vector<int> nums;
	auto* p = head;
	while (p != NULL) {
		nums.push_back(p->val);
		p = p->next;
	}

	stack<int> ss;
	vector<int> ans(nums.size(), 0);
	for (int i = 0; i < nums.size(); i++) {
		while (!ss.empty() && nums[ss.top()] < nums[i]) {
			int t = ss.top();
			ss.pop();
			ans[t] = nums[i];
		}
		ss.push(i);
	}
	return ans;
}

/*
1031. �ɵص����� 

		����һ����ά���� A��ÿ����Ԫ��Ϊ 0���������� 1������½�أ���
		�ƶ���ָ��½���ϴ�һ���ط��ߵ���һ���ط������ĸ�����֮һ�����뿪����ı߽硣
		�����������޷�������������ƶ����뿪����߽��½�ص�Ԫ���������

		ʾ�� 1��
			���룺[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
			�����3
			���ͣ������� 1 �� 0 ��Χ��һ�� 1 û�б���Χ����Ϊ���ڱ߽��ϡ�

		ʾ�� 2��
			���룺[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
			�����0
			���ͣ����� 1 ���ڱ߽��ϻ���Ե���߽硣


	��ʾ��

		1 <= A.length <= 500
		1 <= A[i].length <= 500
		0 <= A[i][j] <= 1
		�����еĴ�С����ͬ

*/

class Solution {
public:
	int numEnclaves(vector<vector<int>>& A) {
		int m = A.size(), n = A[0].size();
		vector<vector<bool>> used(m, vector<bool>(n, false));
		queue<pair<int, int>> qq;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (A[i][j] == 1) {
					if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
						qq.push(make_pair(i, j));
						used[i][j] = true;
					}
				}
			}
		int dd[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
		while (!qq.empty()) {
			auto p = qq.front();
			qq.pop();
			for (int i = 0; i < 4; i++) {
				int x = p.first + dd[i][0];
				int y = p.second + dd[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n) continue;
				if (A[x][y] == 0 || used[x][y]) continue;
				qq.push(make_pair(x, y));
				used[x][y] = true;
			}
		}

		int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (A[i][j] == 1 && !used[i][j]) {
					ans++;
				}
			}
		return ans;
	}
};
