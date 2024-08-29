/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//使用方法 递归 时间复杂度（m+n）空间复杂度（m+n）
//题目 将两个递增有序链表合并成一个递增有序链表。
// 要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中不允许有重复的数据
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    else if (list1->val < list2->val)//如果l1小于l2 l1 的下一跳应该是l1 剩下的和l2全部中选择
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else if (list1->val == list2->val)//如果l1和l2相等 l1的下一跳应该是l1剩下的和l2剩下的中的
    {
        list1->next = mergeTwoLists(list1->next, list2->next);
        return list1;
    }
    else//如果l1小于l2 同理
    {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }

}