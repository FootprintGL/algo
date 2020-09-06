
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p, *q, *r, *s;

        if (!l1)
            return l2;

        if (!l2)
            return l1;

        r = p = l1;
        q = l2;
        while (p && q) {
            while (p && p->val < q->val) {
                r = p;
                p = p->next;
            }

            if (p == nullptr) {
                r->next = q;
                break;
            } else {
                if (r == p) {
                    /* 第一次如果没走while循环，在p前面插入q */
                    s = q->next;
                    q->next = p;
                    r = q;
                    q = s;
                    /* 更新l1表头 */
                    l1 = r;
                } else {
                    /* 在r,p之间插入q */
                    s = q->next;
                    r->next = q;
                    q->next = p;
                    r = q;
                    q = s;
                }
            }
        }

        if (p == nullptr)
            r->next = q;

        return l1;
    }
};
