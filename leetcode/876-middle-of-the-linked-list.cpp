
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
    ListNode* middleNode(ListNode* head) {
        /* 快慢指针找中间节点 */
        ListNode *slow, *fast;

        slow = fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /*
         * fast最后停在奇数节点
         * 如果fast->next不是NULL, 共有偶数个节点，返回第二个
         * 如果fast->next是NULL, 共有奇数个节点，只有一个中间节点
         */
        return fast->next ? slow->next : slow;
    }
};
