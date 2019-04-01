#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
					������ת�������� II

���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬���� [0,0,1,2,2,5,6] ���ܱ�Ϊ [2,5,6,0,0,1,2] )��

��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ��� true�����򷵻� false��

ʾ�� 1:
	����: nums = [2,5,6,0,0,1,2], target = 0
	���: true

ʾ�� 2:
	����: nums = [2,5,6,0,0,1,2], target = 3
	���: false

����:

		���� ������ת�������� ��������Ŀ�������е� nums  ���ܰ����ظ�Ԫ�ء�
		���Ӱ�쵽�����ʱ�临�Ӷ��𣿻���������Ӱ�죬Ϊʲô��

*/


/**
***    �뷨��
***    ����м����С�����ұߵ��������Ұ��������ģ����м����������ұ�����������������ġ�
***    ������������ظ�ֵ���ͻ�����������������[3 1 1] �� [1 1 3 1]����������������м�ֵ��������ֵʱ��Ŀ��ֵ3�ȿ���������ֿ������ұߣ���ֱ���Ƶ���ֵͬΪֹ
***    �������������ʵ����ǳ��򵥣�ֻҪ������ֵ����һλ���ɼ���ѭ�����������ͬ�������
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

// ��վ���Ž�
bool search01(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0) return false;
	int l = 0, r = len - 1;
	while (l < r) {
		if (nums[l] == nums[r]) {
			int x = nums[l];
			while (nums[l] == x && l < len) ++l;
			while (nums[r] == x && r >= 0) --r;
			--l;//������++r  ����Ϊ[1,1] targetΪ0ʱ ����
		}
		int m = (l + r) / 2;
		if (nums[m] == target)
			return true;

		if (nums[m] > nums[r]) {//������� �ұ�����
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

		else {//�ұ�����
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