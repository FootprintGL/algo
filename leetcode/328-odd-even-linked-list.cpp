


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
    ListNode* oddEvenList(ListNode* head) {
        /* 链表节点数小于3个 */
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode *h1 = head, *h2 = head->next;
        ListNode *p = h1, *q = h2;
        bool flag = true;

        /* 节点next指向下下个元素 */
        while (q->next) {
            p->next = q->next;
            p = q;
            q = p->next;
            flag = !flag;
        }

        if (!flag) {
            /* 奇数个节点 */
            p->next = nullptr;
            q->next = h2;
        } else {
            /* 偶数个节点 */
            p->next = h2;
        }

        return head;
    }
};
