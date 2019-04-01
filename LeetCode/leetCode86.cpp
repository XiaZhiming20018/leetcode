#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
	给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

	你应当保留两个分区中每个节点的初始相对位置。

	示例:
		输入: head = 1->4->3->2->5->2, x = 3
		输出: 1->2->2->4->3->5
*/

// 交换数据
void swap(ListNode * p, vector<int>::iterator q)
{
	int tmp = p->val;
	p->val = *q;
	*q = tmp;
}

/**       我的思路：
***       使用两个容器装大于数和小于数
***       将vector 合并
***	      然后将链表按顺序进行替换
**/
ListNode* partition(ListNode* head, int x) {
	ListNode *p = head;
	vector<int> l{}, b{};
	while (p)
	{
		if (p->val < x)
			l.push_back(p->val);
		else
			b.push_back(p->val);
		p = p->next;
	}
	p = head;
	l.insert(l.end(), b.begin(), b.end());
	vector<int>::iterator it = l.begin();
	while (p)
	{
		swap(p, it);
		p = p->next;
		it++;
	}
	return head;
}

// 网站提供最优解

ListNode* partition2(ListNode* head, int x) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	ListNode smallHead(-1); 
	ListNode bigHead(-1);
	ListNode* smallPre = NULL;
	ListNode* bigPre = NULL;

	while (head)
	{
		ListNode* next = head->next;
		if (head->val < x)
		{
			if (smallPre == NULL)
			{
				smallPre = head;
				smallHead.next = head;
				smallPre->next = NULL;
			}
			else
			{
				smallPre->next = head;
				smallPre = head;
				smallPre->next = NULL;
			}
		}
		else
		{
			if (bigPre == NULL)
			{
				bigPre = head;
				bigHead.next = bigPre;
				bigPre->next = NULL;
			}
			else
			{
				bigPre->next = head;
				bigPre = head;
				bigPre->next = NULL;
			}
		}
		head = next;
	}

	if (smallHead.next)
	{
		smallPre->next = bigHead.next;
	}
	else
	{
		smallHead.next = bigHead.next;
	}
	return smallHead.next;
}