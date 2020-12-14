

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

        ListNode *pseudo = new ListNode(0);
        pseudo->next = head;

        ListNode *pre = pseudo, *cur = head, *next = cur->next;
        while (next) {
            if (cur->val == next->val) {
                /* 找到相同元素 */
                while (next && cur->val == next->val)
                    /* 跳过相同元素 */
                    next = next->next;
                cur = next;
                pre->next = cur;
                if (next)
                    next = next->next;
            } else {
                /* 递增 */
                pre = cur;
                cur = next;
                next = next->next;
            }
        }

        return pseudo->next;
    }
};
