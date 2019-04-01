// LeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "allHeader.h"
#include "function.h"
using namespace std;

static const auto io_sync_off = []()
{
	// turn off sync
	ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(nullptr);
	return nullptr;
}();

long long maxProduct(int *A)
{
	long long maxNum1, maxNum2;
	int minOne = INT_MAX, minTwo = INT_MAX;
	int maxOne = INT_MIN, maxTwo = INT_MIN, maxThree = INT_MIN;
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		if (A[i] > maxOne)
			maxOne = A[i];
		else if (A[i] > maxTwo)
			maxTwo = A[i];
		else if (A[i] > maxThree)
			maxThree = A[i];
		if (A[i] < minOne)
			minOne = A[i];
		else if (A[i] < minTwo)
			minTwo = A[i];
	}
	maxNum1 = minOne * minTwo * maxThree;
	maxNum2 = maxOne * maxTwo * maxThree;
	return maxNum1 > maxNum2 ? maxNum1:maxNum2;
}

int main()
{
	ListNode *head = new ListNode(1), *p = head;
	p->next = new ListNode(4), p = p->next;
	p->next = new ListNode(3), p = p->next;
	p->next = new ListNode(2), p = p->next;
	p->next = new ListNode(5), p = p->next;
	p->next = new ListNode(2);
	

	p = reverseBetween(head, 2, 4);
	

	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}

	return 0;
}


