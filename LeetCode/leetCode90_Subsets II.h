#pragma once
#include "allHeader.h"
using namespace std;

/*
����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:
����: [1,2,2]     ���: [ [2],  [1],  [1,2,2],  [2,2],  [1,2],  [] ]
���룺[5,5,5,5,5]   ����� [ [], [5], [5,5], [5,5,5], [5,5,5,5], [5,5,5,5,5] ]
*/


/*
	Ŀǰ���Ž⣺�ݹ�
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		if (!nums.size()) return result;
		sort(nums.begin(), nums.end());  // ��������
		vector<int> tmp;
		back_tracking(nums, 0, tmp, result);
		return result;
	}
private:
	void back_tracking(vector<int> nums, int index, vector<int> & tmp, vector<vector<int>> & result) {
		result.push_back(tmp);
		for (int i = index; i < nums.size(); i++) {
			if (i != index && nums[i] == nums[i - 1]) // �Ƿ���ϸ�Ԫ���ظ�
				continue;
			tmp.push_back(nums[i]);
			back_tracking(nums, i + 1, tmp, result);
			tmp.pop_back();
		}

	}
};


/*
�ҵĽⷨ��1.ȡ����������ÿ�������飬���������в���ԭ����Ԫ�أ�������Ԫ�غ�������������������
���ڴ����ظ�Ԫ�ص�������1.��ԭ����������� 2. ����ͳ�Ƽ������ظ�Ԫ�صĲ���˳��Ϊ���� ������鳤/���� ��
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res{ {} }; //��Ž������
	sort(nums.begin(), nums.end());  //��ԭ�����������
	int cout = 1;   //�ظ�Ԫ�صĸ���
	for (size_t i = 0; i < nums.size(); i++)  
	{
		int size = res.size(), begin = 0;     // res�ĳ��ȺͲ������ʼλ��
		if (i != 0 && nums[i] == nums[i - 1])
		{
			cout++;    // �����ظ�Ԫ��ʱ���������ȼ�һ
			begin = size - size / cout;  // �ظ�Ԫ�ص���ʼ����λ��
		}
		else
			cout = 1;  // ��һ
		for (size_t j = begin; j < size; j++)
		{
			vector<int> tmp{ res[j] };   //��nums����Ԫ�ؼ���res��������
			tmp.push_back(nums[i]);
			res.push_back(tmp);
		}
	}
	return res;
}

