

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
    int kthToLast(ListNode* head, int k) {
        ListNode *p, *q;

        p = q = head;

        while (k > 0 && q != nullptr) {
            q = q->next;
            k--;
        }

        while (q != NULL) {
            p = p->next;
            q = q->next;
        }

        return p->val;
    }
};
