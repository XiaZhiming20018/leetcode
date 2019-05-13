#include "pch.h"
#include "allHeader.h"

using namespace std;

// 第一题
/*
1020. 将数组分成和相等的三个部分  显示英文描述  

	给定一个整数数组 A，只有我们可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
	形式上，如果我们可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。
	
	示例 1：
		输出：[0,2,1,-6,6,-7,9,1,2,0,1]
		输出：true
		解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
	示例 2：
		输入：[0,2,1,-6,6,7,9,-1,2,0,1]
		输出：false
	示例 3：
		输入：[3,3,6,5,-2,2,5,1,-9,4]
		输出：true
		解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
*/

bool canThreePartsEqualSum(vector<int>& A) {
	long long sum = 0;     
	for (int i = 0; i < (int)A.size(); ++i) 
		sum += A[i];
	if (sum % 3 == 0) {
		long long x = A[0];
		int cnt = 0;
		for (int i = 1; i < (int)A.size(); ++i) {
			if (x == sum / 3) 
				x = 0, cnt += 1;
			x += A[i];
		}
		if (x == sum / 3) 
			cnt += 1;
		return cnt == 3;
	}
	else 
		return false;
}


// 第二题
/*
	1022. 可被 K 整除的最小整数  显示英文描述

		给定正整数 K，你需要找出可以被 K 整除的、仅包含数字 1 的最小正整数 N。
		返回 N 的长度。如果不存在这样的 N，就返回 -1。

	示例 1：
		输入：1
		输出：1
		解释：最小的答案是 N = 1，其长度为 1。
	示例 2：
		输入：2
		输出：-1
		解释：不存在可被 2 整除的正整数 N 。
	示例 3：
		输入：3
		输出：3
		解释：最小的答案是 N = 111，其长度为 3。
*/

int smallestRepunitDivByK(int K) {
	int sum = 0;
	for (int i = 1; i <= 10 * K; ++i) {
		(sum = sum * 10 + 1) %= K;
		if (sum == 0) return i;
	}
	return -1;
}

//第三题
/*
	1021. 最佳观光组合  显示英文描述
		给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
		一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
		返回一对观光景点能取得的最高分。

	示例：
		输入：[8,1,5,2,6]
		输出：11
		解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
*/
int maxScoreSightseeingPair(vector<int>& A) {
	int mx = -10000000;
	int ans = mx;
	for (int i = 1; i < (int)A.size(); ++i) {
		mx = max(mx, A[i - 1] + i - 1);
		ans = max(ans, A[i] - i + mx);
	}
	return ans;
}

//第四题
/*
	1023. 子串能表示从 1 到 N 数字的二进制串  显示英文描述

		给定一个二进制字符串 S（一个仅由若干 '0' 和 '1' 构成的字符串）和一个正整数 N，如果对于从 1 到 N 的每个整数 X，其二进制表示都是 S 的子串，就返回 true，否则返回 false。

	示例 1：
		输入：S = "0110", N = 3
		输出：true
	示例 2：
		输入：S = "0110", N = 4
		输出：false
*/

bool queryString(string S, int N) {
	int len = S.size();
	set<int> s;
	for (int j = 1; j <= min(len, 30); ++j) {
		for (int i = 0; i + j - 1 < len; ++i) {
			int num = 0;
			for (int k = i; k < i + j; ++k) {
				num <<= 1;
				num |= (int)(S[k] - '0');
			}
			//printf("%d\n", num);
			if (num <= N && num > 0) s.insert(num);
		}
	}
	return s.size() == N;
}