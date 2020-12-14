

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
        /* 维护两个链表，一个放小于x的元素，另一个放大于等于x的元素，然后在合并两个链表 */
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *h1 = new ListNode(0), *h2 = new ListNode(0);
        ListNode *cur = head, *cur1 = h1, *cur2 = h2;

        while (cur) {
            if (cur->val < x) {
                /* 小的放入链表h1 */
                cur1->next = cur;
                cur1 = cur;
            } else {
                /* 大的放入链表h2 */
                cur2->next = cur;
                cur2 = cur;
            }
            cur = cur->next;
        }

        /* 合并2个链表 */
        cur1->next = h2->next;
        cur2->next = nullptr;

        return h1->next;
    }
};
