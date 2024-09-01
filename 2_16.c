/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
//空间复杂度o（n） 时间复杂的o（n）
//使用哈希表解决



struct ListNode* removeDuplicateNodes(struct ListNode* head) {
    if (head == NULL)
        return head;
    int* ar = (int*)calloc(20001, sizeof(int));
    //使用calloc函数会将分配的内存初始化为零。
    // 即所有分配的字节都被设置为0。
    //而malloc仅分配内存，但不会初始化它。
    // 内存中的数据是未定义的，因此可能包含旧数据或垃圾值。
    //calloc 需要两个参数：要分配的元素数量和每个元素的大小。
    // 例如，calloc(20001, sizeof(int)) 
    // 分配了 20001 个 int 元素，每个元素的大小是 sizeof(int) 字节。
   //malloc 只需要一个参数：所需内存的总字节数。
   // 例如，malloc(20001 * sizeof(int)) 
   // 分配了 20001 * sizeof(int) 字节的内存。
    struct ListNode* now = head;
    ar[head->val] = 1;//使第一个节点的值先到哈希表中 并占位
    while (now->next != NULL)//因为使用了now->next = now->next->next;这句所以now指针
        //不会直接跳转而是改变跳转位置（p=p->next 是直接跳转）
    {
        struct ListNode* tail = now->next;//临时指针，下一个循环回自动没有，因为这是局部变量
        if (ar[tail->val] == 1)
        {
            now->next = now->next->next;//1->2->3->4->4->3
            //                                     👆👆
            //                                     now tail
            //因为tail指针指向的数据域的值，在哈希表中冲突所以now的下一跳指向3，但不直接跳转

        }
        else {
            ar[tail->val] = 1;
            now = now->next;
        }
    }
    now->next == NULL;//最后now指针的值一定不是NULL，因为NULL是他的下一条，这里指向NULL使链表完整
    return head;
}
