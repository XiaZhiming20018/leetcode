#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
	����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

	��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

	ʾ��:
		����: head = 1->4->3->2->5->2, x = 3
		���: 1->2->2->4->3->5
*/

// ��������
void swap(ListNode * p, vector<int>::iterator q)
{
	int tmp = p->val;
	p->val = *q;
	*q = tmp;
}

/**       �ҵ�˼·��
***       ʹ����������װ��������С����
***       ��vector �ϲ�
***	      Ȼ������˳������滻
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

// ��վ�ṩ���Ž�

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