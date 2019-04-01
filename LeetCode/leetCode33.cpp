#include "pch.h"
#include "allHeader.h"

using namespace std;

/*

							33. 搜索旋转排序数组

		假设按照升序排序的数组在预先未知的某个点上进行了旋转。

		( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

		搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

		你可以假设数组中不存在重复的元素。你的算法时间复杂度必须是 O(log n) 级别。

		示例 1:
			输入: nums = [4,5,6,7,0,1,2], target = 0
			输出: 4

		示例 2:
			输入: nums = [4,5,6,7,0,1,2], target = 3
			输出: -1
*/

/**
***           思路  ：
***      
***           如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，
***           我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了
**/


int search(vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < nums[right])
		{
			if (nums[mid] < target && nums[right] >= target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		else
		{
			if (nums[left] <= target && nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
}



// 网站最优解

int search01(vector<int>& nums, int target) {
	int length = nums.size();
	int i = 0;
	if (length == 0) return -1;
	if (length == 1)
	{
		if (nums[0] == target)
			return 0;
		else
			return -1;
	}
	if (nums[0] > target&&nums[length - 1] < target)
		return -1;
	else if (nums[0] <= target)
	{
		while (i < length&&nums[i] <= target)
		{
			if (nums[i] == target)
				return i;
			else
				++i;
		}
		return -1;
	}
	else
	{
		i = length - 1;
		while (i > 0 && nums[i] >= target)
		{
			if (nums[i] == target)
				return i;
			else
				--i;
		}
		return -1;
	}
}