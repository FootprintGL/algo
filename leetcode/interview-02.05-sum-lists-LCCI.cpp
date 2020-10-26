

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *l3 = new ListNode(0), *p3 = l3;
        int carry = 0, cur, tmp;

        /* 模拟加法 */
        while (p1 || p2 || carry) {
            cur = carry;
            if (p1) {
                cur += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                cur += p2->val;
                p2 = p2->next;
            }

            carry = cur / 10;
            cur %= 10;
            p3->next = new ListNode(cur);
            p3 = p3->next;
        }

        return l3->next;
    }
};
