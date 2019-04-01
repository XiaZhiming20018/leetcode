#pragma
#include "allHeader.h"
using namespace std;
#include <queue>

/*
1029. 可被 5 整除的二进制前缀

	给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。
	返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。

	示例 1：
		输入：[0,1,1]
		输出：[true,false,false]
		解释：输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为真。
	
	示例 2：
		输入：[1,1,1]
		输出：[false,false,false]

	示例 3：
		输入：[0,1,1,1,1,1]
		输出：[true,false,false,false,true,false]

	示例 4：
		输入：[1,1,1,0,1]
		输出：[false,false,false,false,false]
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
	1028. 负二进制转换 

		给出数字 N，返回由若干 "0" 和 "1"组成的字符串，该字符串为 N 的负二进制（base -2）表示。

		除非字符串就是 "0"，否则返回的字符串中不能含有前导零。

		示例 1：
			输入：2
			输出："110"
			解释：(-2) ^ 2 + (-2) ^ 1 = 2

		示例 2：
			输入：3
			输出："111"
			解释：(-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3

		示例 3：
			输入：4
			输出："100"
			解释：(-2) ^ 2 = 4
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
1030. 链表中的下一个更大节点 
		给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

		每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，
		那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

		返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

		注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。
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
1031. 飞地的数量 

		给出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。
		移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。
		返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。

		示例 1：
			输入：[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
			输出：3
			解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。

		示例 2：
			输入：[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
			输出：0
			解释：所有 1 都在边界上或可以到达边界。


	提示：

		1 <= A.length <= 500
		1 <= A[i].length <= 500
		0 <= A[i][j] <= 1
		所有行的大小都相同

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
