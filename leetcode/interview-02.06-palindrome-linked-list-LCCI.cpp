

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
    ListNode *reverse(ListNode *head) {
        ListNode *p, *q, *r;

        /* 空链表或只有一个元素 */
        if (head == nullptr || head->next == nullptr)
            return head;

        /* 链表反转 */
        p = head;
        q = p->next;
        r = q->next;
        while (r) {
            q->next = p;
            if (p == head)
                p->next = nullptr;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        if (p == head)
            p->next = nullptr;

        return q;
    }

    bool isPalindrome(ListNode* head) {
        /* 空链表 */
        if (head == nullptr || head->next == nullptr)
            return true;

        /* 快慢指针找终点 */
        ListNode *fast, *slow;

        slow = fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* 翻转链表 */
        ListNode *q = reverse(slow->next);
        slow->next = nullptr;

        /* 比较链表head和q */
        ListNode *p = head;
        while (p && q) {
            if (p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }

        return true;
    }
};
