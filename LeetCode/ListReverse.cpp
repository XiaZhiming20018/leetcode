#include "pch.h"
#include "allHeader.h"
using namespace std;

//  第一种方法：  ==>  就地反转法

/*

把当前链表的下一个节点pCur插入到头结点dummy的下一个节点中，就地反转。

dummy->1->2->3->4->5的就地反转思路：

					dummy->2->1->3->4->5
					dummy->3->2->1->4->5
					dummy->4>-3->2->1->5
					dummy->5->4->3->2->1

反转过程：
		pCur是需要反转的节点。

		prev连接下一次需要反转的节点
		反转节点pCur
		纠正头结点dummy的指向
		pCur指向下一次要反转的节点

伪代码

		prev.next = pCur.next;
		pCur.next = dummy.next;
		dummy.next = pCur;
		pCur = prev.next;
*/

// 实现代码
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



//  第二种方法   ==>  新建链表，头节点插入法
 
/*
      思路：新建一个头结点，遍历原链表，把每个节点用头结点插入到新建链表中。最后，新建的链表就是反转后的链表

	  过程：pCur是要插入到新链表的节点。pNex是临时保存的pCur的next。

				1. pNex保存下一次要插入的节点
				2. 把pCur插入到dummy中
				3. 纠正头结点dummy的指向
				4. pCur指向下一次要插入的节点
	  
	  伪代码：

				pNex = pCur.next
				pCur.next = dummy.next
				dummy.next = pCur
				pCur = pNex
*/

// 实现代码

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