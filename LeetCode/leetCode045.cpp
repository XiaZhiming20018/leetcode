#include "pch.h"
#include "allHeader.h"

using std::vector;
/*
45. 跳跃游戏 II

	给定一个非负整数数组，你最初位于数组的第一个位置。
	数组中的每个元素代表你在该位置可以跳跃的最大长度。
	你的目标是使用最少的跳跃次数到达数组的最后一个位置。

	示例:
		输入: [2,3,1,1,4]
		输出: 2
		解释: 跳到最后一个位置的最小跳跃数是 2。
			 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

	说明:
		假设你总是可以到达数组的最后一个位置。
*/

// 贪心算法

// 执行用时: 20 ms, 在Jump Game II的C++提交中击败了80.15% 的用户
// 内存消耗 : 10.1 MB, 在Jump Game II的C++提交中击败了80.33% 的用户

int jump(vector<int>& nums) {
	if (nums.size() <= 1)
		return 0;
	int i = 0, step = 0;
	while (i < nums.size())
	{
		if (i + nums[i] >= nums.size() - 1)
			return step + 1;
		int _max = -1,index;
		for (int j = i + 1; j < nums[i] + i + 1; j++) {
			// 重点步骤在下判断
			// 如果当前位置i和其位置的值nums[i]的和是更大的，即能走到更远的位置
			// 而不是单独判断其位置上的值
			if (_max <= j + nums[j]) {
				_max = j + nums[j];
				index = j;
			}
		}
		++step;
		i = index;
	}
	return step;
}

// 最优解
static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> res(nums.size(), INT_MAX);
		res[0] = 0;
		int start, i, j;
		int range = 0;
		for (i = 0; i < nums.size() - 1; i++)
		{
			if (range == nums.size() - 1) 
				break;
			if (i + nums[i] <= range)    
				continue;   //如果当前位置最大跨度仍然不能达到当前可以达到的最远距离，则进行下一次循环
			for (j = range - i + 1; j <= nums[i] && (i + j) < nums.size(); j++)
			{
				if ((res[i] + 1) < res[i + j])
					res[i + j] = res[i] + 1;
			}
			range = (i + nums[i]) >= nums.size() ? nums.size() - 1 : i + nums[i];
		}
		return res[nums.size() - 1];
	}
};