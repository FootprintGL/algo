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
    ListNode* reverseList(ListNode* head) {
        ListNode *p, *q, *r;

        if (head == NULL || head->next == NULL)
            return head;

        p = head;
        q = head->next;
        while (p && q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head->next = NULL;
     
        return p;
    }
};
