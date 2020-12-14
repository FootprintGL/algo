


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = new ListNode(0);
        pre->next = head;

        ListNode *p = pre;
        ListNode *q = head;

        /* q先走n步 */
        while (n--) {
            q = q->next;
        }

        /* q走到结尾，p指向倒数第n + 1个节点 */
        while (q) {
            q = q->next;
            p = p->next;
        }

        /* 删除第n个节点 */
        q = p->next;
        p->next = q->next;
        delete(q);

        return pre->next;
    }
};
