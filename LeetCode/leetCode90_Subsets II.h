#pragma once
#include "allHeader.h"
using namespace std;

/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例:
输入: [1,2,2]     输出: [ [2],  [1],  [1,2,2],  [2,2],  [1,2],  [] ]
输入：[5,5,5,5,5]   输出： [ [], [5], [5,5], [5,5,5], [5,5,5,5], [5,5,5,5,5] ]
*/


/*
	目前最优解：递归
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		if (!nums.size()) return result;
		sort(nums.begin(), nums.end());  // 数组排序
		vector<int> tmp;
		back_tracking(nums, 0, tmp, result);
		return result;
	}
private:
	void back_tracking(vector<int> nums, int index, vector<int> & tmp, vector<vector<int>> & result) {
		result.push_back(tmp);
		for (int i = index; i < nums.size(); i++) {
			if (i != index && nums[i] == nums[i - 1]) // 是否和上个元素重复
				continue;
			tmp.push_back(nums[i]);
			back_tracking(nums, i + 1, tmp, result);
			tmp.pop_back();
		}

	}
};


/*
我的解法：1.取出结果数组的每个子数组，在子数组中插入原数组元素，将插入元素后的子数组放入结果数组中
存在大量重复元素的做法：1.对原数组进行排序； 2. 进行统计计数，重复元素的插入顺序为倒数 结果数组长/计数 ；
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res{ {} }; //存放结果数组
	sort(nums.begin(), nums.end());  //对原数组进行排序
	int cout = 1;   //重复元素的个数
	for (size_t i = 0; i < nums.size(); i++)  
	{
		int size = res.size(), begin = 0;     // res的长度和插入的起始位置
		if (i != 0 && nums[i] == nums[i - 1])
		{
			cout++;    // 存在重复元素时，计数长度加一
			begin = size - size / cout;  // 重复元素的起始插入位置
		}
		else
			cout = 1;  // 归一
		for (size_t j = begin; j < size; j++)
		{
			vector<int> tmp{ res[j] };   //将nums的逐元素加入res的子数组
			tmp.push_back(nums[i]);
			res.push_back(tmp);
		}
	}
	return res;
}

