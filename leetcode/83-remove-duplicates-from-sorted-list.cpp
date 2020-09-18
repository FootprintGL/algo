

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = head, *q = head->next;

        while (q) {
            if (p->val == q->val) {
                p->next = q->next;
                delete(q);
                q = p->next;
            } else {
                p = q;
                q = q->next;
            }
        }

        return head;
    }
};
