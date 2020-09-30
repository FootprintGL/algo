
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
    bool hasCycle(ListNode *head) {
        /* 快慢指针 */
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *p, *q;
        p = head;
        q = p->next;

        while (p != q) {
            if (q == NULL || q->next == NULL)
                return false;
            p = p->next;
            q = q->next->next;
        }

        return true;
    }
};



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
    bool hasCycle(ListNode *head) {
        /* 快慢指针 */
        ListNode *p, *q;
        p = q = head;

        if (head == NULL)
            return false;

        while (p && q) {
            p = p->next;
            q = q->next;
            if (q != NULL)
                q = q->next;
            else
                return false;
            if (p == q)
                return true;
        }

        return false;
    }
};
