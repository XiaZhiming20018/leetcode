#pragma
#include "pch.h"
#include "allHeader.h"
using namespace std;
/*
	����˼·��ʹ�ÿ���˫ָ�����������������һ������ָ��NULL����Ϊ�޻�
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