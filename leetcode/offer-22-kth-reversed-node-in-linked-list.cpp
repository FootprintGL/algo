
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        /* 双指针p, 移动q，使p到q相距k个位置，同时移动p,q, q只想null时，p即为所球节点 */
        ListNode *p, *q;
        int cnt = 0, i;

        p = q = head;
        for (i = 0; i < k; i++) {
            if (q)
                q = q->next;
            else
                break;
        }

        /* 链表小于k个 */
        if (i != k)
            return nullptr;

        /* 同时移动p,q到结尾 */
        while (q) {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};
