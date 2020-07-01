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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode *p, *q, *r;
        int val;

        p = head;
        while (p) {
            val = p->val;
            r = p;
            q = p->next;
            while (q) {
                if (q->val == val) {
                    r->next = q->next;
                    q = q->next;
                } else {
                    r = q;
                    q = q->next;
                }
            }
            p = p->next;
        }

        return head;
    }
};
