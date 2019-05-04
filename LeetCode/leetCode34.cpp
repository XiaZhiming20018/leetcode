#include "pch.h"
#include "allHeader.h"

using std::vector;

/*
34. �����������в���Ԫ�صĵ�һ�������һ��λ��

	����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

	����㷨ʱ�临�Ӷȱ����� O(log n) ����

	��������в�����Ŀ��ֵ������ [-1, -1]��

	ʾ�� 1:
		����: nums = [5,7,7,8,8,10], target = 8
		���: [3,4]

	ʾ�� 2:
		����: nums = [5,7,7,8,8,10], target = 6
		���: [-1,-1]
*/


// �������Ҫ���ڴ���߽����
// ʹ�ö��ַ��ҵ�Ŀ��ֵ��Ȼ���������ұ���

// ִ����ʱ: 24 ms, ��Find First and Last Position of Element in Sorted Array��C++�ύ�л�����35.31% ���û�
// �ڴ����� : 10.3 MB, ��Find First and Last Position of Element in Sorted Array��C++�ύ�л�����85.81% ���û�

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

// ��վ���Ž�, �����ҷֱ����м����������

static const auto __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

// ִ����ʱ: 16 ms, ��Find First and Last Position of Element in Sorted Array��C++�ύ�л�����93.24% ���û�
// �ڴ����� : 10.4 MB, ��Find First and Last Position of Element in Sorted Array��C++�ύ�л�����74.70% ���û�

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