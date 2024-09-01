/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��
//���� ����ָ�� ʱ�临�ӵ�O��n���ռ临�Ӷ� O��1��
//��ָ������k������ָ���head����
//����ָ���ܵ�k��λ��ʱ������ָ��ͬʱ��������ָ��Խ���ʱ��
//��ָ�뵽kλ��

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
