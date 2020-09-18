

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /* 双指针 */
        ListNode *p = headA;
        ListNode *q = headB;

        while (p != q) {
            if (p == NULL) {
                p = headB;
            } else {
                p = p->next;
            }

            if (q == NULL) {
                q = headA;
            } else {
                q = q->next;
            }
        }

        return p;
    }
};
