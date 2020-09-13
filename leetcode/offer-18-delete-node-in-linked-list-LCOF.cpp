
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p, *q;

        p = head;
        while (p) {
            if (p->val == val) {
                if (p == head) {
                    head = head->next;
                    break;
                } else {
                    q->next = p->next;
                }
            }
            q = p;
            p = p->next;
        }

        return head;
    }
};
