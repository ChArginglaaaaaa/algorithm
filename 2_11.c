/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
//方法 快慢指针 时间复杂的O（n）空间复杂度 O（1）
//快指针先跑k个，慢指针从head出发
//当快指针跑到k的位置时，快慢指针同时启动，快指针越界的时候
//慢指针到k位置

int kthToLast(struct ListNode* head, int k) {
    struct ListNode* l = head;
    struct ListNode* h = head;
    while (k != 0)
    {
        h = h->next;
        k--;
    }
    while (h != NULL)
    {
        l = l->next;
        h = h->next;
    }
    return l->val;
}
