#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
					搜索旋转排序数组 II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:
	输入: nums = [2,5,6,0,0,1,2], target = 0
	输出: true

示例 2:
	输入: nums = [2,5,6,0,0,1,2], target = 3
	输出: false

进阶:

		这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
		这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

*/


/**
***    想法：
***    如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的。
***    而如果可以有重复值，就会出现来面两种情况，[3 1 1] 和 [1 1 3 1]，对于这两种情况中间值等于最右值时，目标值3既可以在左边又可以在右边，，直到移到不同值为止
***    对于这种情况其实处理非常简单，只要把最右值向左一位即可继续循环，如果还相同则继续移
**/

bool search(vector<int>& nums, int target) {
	if (nums.size() == 0)
		return false;
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return true;
		if (nums[mid] < nums[right])
		{
			if (nums[mid] < target && nums[right] >= target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		else if (nums[mid] > nums[right])
		{
			if (nums[mid] > target && nums[left] <= target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		else
			right--;
	}
	return false;
}

// 网站最优解
bool search01(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0) return false;
	int l = 0, r = len - 1;
	while (l < r) {
		if (nums[l] == nums[r]) {
			int x = nums[l];
			while (nums[l] == x && l < len) ++l;
			while (nums[r] == x && r >= 0) --r;
			--l;//不能是++r  输入为[1,1] target为0时 错误
		}
		int m = (l + r) / 2;
		if (nums[m] == target)
			return true;

		if (nums[m] > nums[r]) {//左边有序 右边无序
			if (nums[m] > target) {
				if (nums[l] <= target)
					r = m - 1;
				else
					l = m + 1;
			}
			else {//nums[m] < target
				l = m + 1;
			}
		}

		else {//右边有序
			//r = m;
			if (nums[m] > target) {
				r = m - 1;
			}
			else {//nums[m] < target
				if (nums[r] >= target)
					l = m + 1;
				else
					r = m - 1;
			}
		}
	}
	if (nums[l] == target)
		return true;
	return false;
}