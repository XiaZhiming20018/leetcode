#include "pch.h"
#include "allHeader.h"
using namespace std;

//  ��һ�ַ�����  ==>  �͵ط�ת��

/*

�ѵ�ǰ�������һ���ڵ�pCur���뵽ͷ���dummy����һ���ڵ��У��͵ط�ת��

dummy->1->2->3->4->5�ľ͵ط�ת˼·��

					dummy->2->1->3->4->5
					dummy->3->2->1->4->5
					dummy->4>-3->2->1->5
					dummy->5->4->3->2->1

��ת���̣�
		pCur����Ҫ��ת�Ľڵ㡣

		prev������һ����Ҫ��ת�Ľڵ�
		��ת�ڵ�pCur
		����ͷ���dummy��ָ��
		pCurָ����һ��Ҫ��ת�Ľڵ�

α����

		prev.next = pCur.next;
		pCur.next = dummy.next;
		dummy.next = pCur;
		pCur = prev.next;
*/

// ʵ�ִ���
ListNode* reverseList1(ListNode *head) {
	if (head == nullptr)
		return head;
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *prev = dummy->next;
	ListNode *pCur = prev->next;
	while (pCur != nullptr) {
		prev->next = pCur->next;
		pCur->next = dummy->next;
		dummy->next = pCur;
		pCur = prev->next;
	}
	return dummy->next;
}



//  �ڶ��ַ���   ==>  �½�����ͷ�ڵ���뷨
 
/*
      ˼·���½�һ��ͷ��㣬����ԭ������ÿ���ڵ���ͷ�����뵽�½������С�����½���������Ƿ�ת�������

	  ���̣�pCur��Ҫ���뵽������Ľڵ㡣pNex����ʱ�����pCur��next��

				1. pNex������һ��Ҫ����Ľڵ�
				2. ��pCur���뵽dummy��
				3. ����ͷ���dummy��ָ��
				4. pCurָ����һ��Ҫ����Ľڵ�
	  
	  α���룺

				pNex = pCur.next
				pCur.next = dummy.next
				dummy.next = pCur
				pCur = pNex
*/

// ʵ�ִ���

ListNode* reverseList2(ListNode *head) {
	ListNode *dummy = new ListNode(-1);
	ListNode *pCur = head;
	while (pCur != nullptr) {
		ListNode *pNex = pCur->next;
		pCur->next = dummy->next;
		dummy->next = pCur;
		pCur = pNex;
	}
	return dummy->next;
}