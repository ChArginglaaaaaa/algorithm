/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//ʹ�÷��� �ݹ� ʱ�临�Ӷȣ�m+n���ռ临�Ӷȣ�m+n��
//��Ŀ ������������������ϲ���һ��������������
// Ҫ����������ʹ��ԭ����������Ĵ洢�ռ䣬������ռ�������Ĵ洢�ռ䡣���в��������ظ�������
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
    else if (list1->val < list2->val)//���l1С��l2 l1 ����һ��Ӧ����l1 ʣ�µĺ�l2ȫ����ѡ��
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else if (list1->val == list2->val)//���l1��l2��� l1����һ��Ӧ����l1ʣ�µĺ�l2ʣ�µ��е�
    {
        list1->next = mergeTwoLists(list1->next, list2->next);
        return list1;
    }
    else//���l1С��l2 ͬ��
    {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }

}