#pragma
#include "pch.h"
#include "allHeader.h"
using namespace std;
/*
	解题思路：使用快慢双指针遍历链表，若其中有一个链表指向NULL，即为无环
*/
ListNode *detectCycle(ListNode *head) {
	ListNode *fast = head, *slow = head;
	ListNode *h = new ListNode(-1);
	h->next = head;
	while (true)
	{
		if (!fast->next || !fast->next->next)
			return nullptr;
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	slow = h;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}