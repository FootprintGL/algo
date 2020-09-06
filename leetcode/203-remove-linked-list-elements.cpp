
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = NULL, *q = head, *r;

        while (q) {
            if (q->val == val) {
                if (p == NULL) {
                    /* 头节点 */
                    r = q;
                    q = q->next;
                    head = q;
                    //free(r);
                    delete(r);
                } else {
                    r = q;
                    p->next = q->next;
                    q = p->next;
                    //free(r);
                    delete(r);
                }
            } else {
                p = q;
                q = q->next;
            }
        }

        return head;
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = NULL, *q = head, *r;

        while (q) {
            if (q->val == val) {
                if (p == NULL) {
                    /* 头节点 */
                    r = q;
                    q = q->next;
                    head = q;
                    //free(r);
                } else {
                    r = q;
                    p->next = q->next;
                    q = p->next;
                    //free(r);
                }
            } else {
                p = q;
                q = q->next;
            }
        }

        return head;
    }
};
