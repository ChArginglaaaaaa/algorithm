/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//����һ�������ͷ�ڵ� head ��һ������ val ��
// ����ɾ���������������� 
// Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
//���� ����ָ�� ʱ�临�ӵ�O(n) �ռ临�ӵ�O(1)

struct ListNode* removeElements(struct ListNode* head, int val) 
{
	while (head != NULL && head->val == val)
		//�ⲿ�Ǵ������&&��һ��������Ҫɾ����ֵ��
		// һֱɾ��������val�Ľ��
		//��:3->3->4->5->3 val=3 ===>   4->5->3
	{
		head = head->next;
	}
	struct ListNode* now = head;//��ָ��
	struct ListNode* tail = NULL;//��ָ��
	while (now != NULL)
	{
		if (now->val != val)//�����ǰֵ������val
		{
			tail = now;//ʹ��ָ��ָ�����ڵ�ֵ
		}
		else {//�������
			tail->next = now->next; //�൱���˹���ǰָ��ֱ��
								//ʹ��ָ��ָ�� ��ָ�����һ��
		}
		now = now->next;

	}
	return head;//���head ��Ϊtial ָ�������Ľڵ� nowָ��Խ��
}