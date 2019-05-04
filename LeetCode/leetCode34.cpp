#include "pch.h"
#include "allHeader.h"

using std::vector;

/*
34. 在排序数组中查找元素的第一个和最后一个位置

	给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

	你的算法时间复杂度必须是 O(log n) 级别。

	如果数组中不存在目标值，返回 [-1, -1]。

	示例 1:
		输入: nums = [5,7,7,8,8,10], target = 8
		输出: [3,4]

	示例 2:
		输入: nums = [5,7,7,8,8,10], target = 6
		输出: [-1,-1]
*/


// 这题的主要点在处理边界情况
// 使用二分法找到目标值，然后向左向右遍历

// 执行用时: 24 ms, 在Find First and Last Position of Element in Sorted Array的C++提交中击败了35.31% 的用户
// 内存消耗 : 10.3 MB, 在Find First and Last Position of Element in Sorted Array的C++提交中击败了85.81% 的用户

vector<int> searchRange(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, flag = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			flag = mid;
			break;
		}
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	if (left > right)
		return { -1,-1 };
	int i;
	left = flag, right = flag;
	for (i = flag - 1; i >= 0; i--)
	{
		if (nums[i] != target) {
			left = i + 1;
			break;
		}
	}
	if (i == -1)
		left = 0;
	for (i = flag + 1; i < nums.size(); i++)
	{
		if (nums[i] != target) {
			right = i - 1;
			break;
		}
	}
	if (i == nums.size())
		right = nums.size() - 1;
	return { left, right };
}

// 网站最优解, 从左右分别向中间遍历、、、

static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

// 执行用时: 16 ms, 在Find First and Last Position of Element in Sorted Array的C++提交中击败了93.24% 的用户
// 内存消耗 : 10.4 MB, 在Find First and Last Position of Element in Sorted Array的C++提交中击败了74.70% 的用户

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res = { -1,-1 };
		if (nums.size() == 0) 
			return { -1,-1 };
		for (int i = 0; i < nums.size(); i++) {
			if (target == nums[i]) {
				res[0] = i;
				break;
			}
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (target == nums[i]) {
				res[1] = i;
				break;
			}
		}
		return res;
	}
};