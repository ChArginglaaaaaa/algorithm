/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
//反转链表 原地反转 时间复杂的0(n) 空间复杂的O(1)
//方法 快慢指针（三指针）一个指针为前进指针 一个指向当前 
// 一个指向过去
//
struct ListNode* reverseList(struct ListNode* head) 
{
	struct ListNode* now = head;
	struct ListNode* tail = NULL;
	while (head != NULL)
	{//第一回NULL 1 2 3 4 5 ====> 1->2->3->4->5
	//       👆 👆
	//	     head      
	//      tail now
	//  =====>NULL<-1 2->3->4->5
	//             👆👆
	//	          head
	//	     tail now
	//最后 NULL<-1<-2<-3<-4<-5  越界
	//                      👆 👆
	//			    head
	//		       tail now            
		head = head->next;//
		now->next = tail;//
		tail = now;
		now = head;
	}
	return tail;
	


}
