#include "pch.h"
#include "allHeader.h"

using std::vector;
/*
45. ��Ծ��Ϸ II

	����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
	�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
	���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

	ʾ��:
		����: [2,3,1,1,4]
		���: 2
		����: �������һ��λ�õ���С��Ծ���� 2��
			 ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�

	˵��:
		���������ǿ��Ե�����������һ��λ�á�
*/

// ̰���㷨

// ִ����ʱ: 20 ms, ��Jump Game II��C++�ύ�л�����80.15% ���û�
// �ڴ����� : 10.1 MB, ��Jump Game II��C++�ύ�л�����80.33% ���û�

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
			// �ص㲽�������ж�
			// �����ǰλ��i����λ�õ�ֵnums[i]�ĺ��Ǹ���ģ������ߵ���Զ��λ��
			// �����ǵ����ж���λ���ϵ�ֵ
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

// ���Ž�
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
				continue;   //�����ǰλ���������Ȼ���ܴﵽ��ǰ���Դﵽ����Զ���룬�������һ��ѭ��
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