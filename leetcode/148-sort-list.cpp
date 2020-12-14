

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
    ListNode* sortList(ListNode* head) {
        /*
         * 归并排序
         * 分割 - 快慢指针找到中点并断开，递归终止条件为head->next == null, 只有一个节点
         * 合并 - 双指针，建立辅助头节点
         */
        if (head == nullptr || head->next == nullptr)
            return head;

        /* 快慢指针找中点 */
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* 分割 */
        ListNode* tmp = slow->next;
        slow->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);

        /* 合并 */
        ListNode *h = new ListNode(0);
        ListNode *res = h;
        while (left && right) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }

        h->next = left != nullptr ? left : right;

        return res->next;
    }
};
