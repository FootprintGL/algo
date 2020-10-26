

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p, *q;

        p = head;
        while (p && p->val < x)
        /* 找到地一个大于等于x的节点 */
            p = p->next;

        if (p == NULL)
            return head;


        q = p->next;
        while (q) {
            //cout << p << " " << q << endl;
            //cout << p << " - " << p->val << endl;

            while (q && q->val >= x)
            /* 找下一个小于x的节点 */
                q = q->next;

            if (q == NULL)
                break;

            //cout << q << " -- " << q->val << endl;
            /* 交换 */
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
            p = p->next;
        }

        return head;
    }
};
