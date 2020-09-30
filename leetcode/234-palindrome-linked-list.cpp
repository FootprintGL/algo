
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
    /* 反转链表 */
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *cur = head, *next;

        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        /*
         * 1. 快慢指针找中点
         * 2. 反转后半部分
         * 3. 比较
         * 4. 反转后半部分恢复原链表
         */
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *p, *q, *rhead;

        /* 找中点 */
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* 反转后半部分 */
        rhead = reverse(slow);

        /* 比较检查回文 */
        p = head;
        q = rhead;
        while (p && q) {
            if (p->val != q->val) {
                /* 反转恢复链表 */
                reverse(rhead);
                return false;
            }
            p = p->next;
            q = q->next;
        }

        /* 反转恢复链表 */
        reverse(rhead);

        return true;
    }
};
