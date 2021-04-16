

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
    ListNode* swapNodes(ListNode* head, int k) {
        /* 快慢指针定位，交换节点的值，返回头节点 */
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        /* 找到第k个节点 */
        for (int i = 0; i < k; i++) {
            fast = fast->next;
            prev = prev->next;
        }

        /* 快慢指针同时走 */
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        /* 交换prev,slow节点的值 */
        int tmp = prev->val;
        prev->val = slow->val;
        slow->val = tmp;

        return head;
    }
};
