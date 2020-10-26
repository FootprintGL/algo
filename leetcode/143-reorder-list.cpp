

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
    /* 找链表中点 */
    ListNode *findmid(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;

        while (fast->next && fast->next->next) {
            //cout << fast << " ";
            //cout << fast->next << endl;
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    /* 反转链表 */
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL, *cur = head, *next;

        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    /* 合并链表 */
    void merge(ListNode *l1, ListNode *l2) {
        ListNode *cur1, *next1, *cur2, *next2;

        cur1 = l1;
        cur2 = l2;
        while (cur1 && cur2) {
            next1 = cur1->next;
            next2 = cur2->next;

            cur1->next = cur2;
            cur1 = next1;
            cur2->next = cur1;
            cur2 = next2;
        }
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        /* 节点数小于等于2，直接返回 */
            return;
        /* 找中点 */
        ListNode *mid = findmid(head);
        //cout << "mid " << mid << endl;
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = NULL;
        /* 后半部分反转 */

        l2 = reverse(l2);
        /* 合并 */
        merge(l1, l2);
    }
};
