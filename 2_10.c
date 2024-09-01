/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//给你一个链表的头节点 head 和一个整数 val ，
// 请你删除链表中所有满足 
// Node.val == val 的节点，并返回 新的头节点 。
//方法 快慢指针 时间复杂的O(n) 空间复杂的O(1)

struct ListNode* removeElements(struct ListNode* head, int val) 
{
	while (head != NULL && head->val == val)
		//这部是处理空链&&第一个结点就是要删除的值，
		// 一直删除到不是val的结点
		//如:3->3->4->5->3 val=3 ===>   4->5->3
	{
		head = head->next;
	}
	struct ListNode* now = head;//快指针
	struct ListNode* tail = NULL;//慢指针
	while (now != NULL)
	{
		if (now->val != val)//如果当前值不等于val
		{
			tail = now;//使慢指针指向现在的值
		}
		else {//如果等于
			tail->next = now->next; //相当于滤过当前指针直接
								//使慢指针指向 快指针的下一跳
		}
		now = now->next;

	}
	return head;//输出head 因为tial 指针在最后的节点 now指针越界
}