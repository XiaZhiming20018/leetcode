// LeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "allHeader.h"
#include "function.h"

using namespace std;

int largestRectangleArea(vector<int>& heights);

static const auto io_sync_off = []()
{
	// turn off sync
	ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(nullptr);
	return nullptr;
}();


int main()
{
	ListNode *head = new ListNode(1), *p = head;
	p->next = new ListNode(4), p = p->next;
	p->next = new ListNode(3), p = p->next;
	p->next = new ListNode(2), p = p->next;
	p->next = new ListNode(5), p = p->next;
	p->next = new ListNode(2);



	//while (p)
	//{
	//	cout << p->val << endl;
	//	p = p->next;
	//}
	vector<int> nums{ 2,1,5,6,2,3 };


	cout << largestRectangleArea(nums);


	return 0;
}


