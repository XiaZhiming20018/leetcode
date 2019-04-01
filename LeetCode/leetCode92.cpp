#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
				92. 反转链表 II
	反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

	说明: 	1 ≤ m ≤ n ≤ 链表长度。

	示例:
		输入: 1->2->3->4->5->NULL, m = 2, n = 4
		输出: 1->4->3->2->5->NULL

*/


ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode *root = new ListNode(-1);
	root->next = head;
	ListNode *node = root;

	for (int i = 0; i < m - 1; i++)
		node = node->next;

	auto prev = node;
	ListNode *midHead = nullptr;
	ListNode *midEnd = node->next;

	node = node->next;

	for (int i = 0; i < n - m + 1; i++) {
		auto *t = node;
		node = node->next;
		t->next = midHead;
		midHead = t;
	}

	prev->next = midHead;
	midEnd->next = node;

	return root->next;
}