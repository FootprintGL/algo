

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return head;

        ListNode *prev, *cur;
        ListNode *p, *q;
        /* 引入dummy节点方便处理 */
        ListNode *dummy = new ListNode(0);

        dummy->next = head;
        prev = dummy;
        cur = head;

        while (cur) {
            p = dummy;
            q = dummy->next;
            while (q != cur && q->val < cur->val) {
                /* 找到大于cur->val的节点 */
                p = p->next;
                q = q->next;
            }

            if (q != cur) {
                /* 插入 */
                prev->next = cur->next;
                p->next = cur;
                cur->next = q;
                cur = prev->next;
            } else {
                /* 已在位，向右移动，处理下一个 */
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
