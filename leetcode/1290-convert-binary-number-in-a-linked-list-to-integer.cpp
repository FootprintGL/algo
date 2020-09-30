

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
    int getDecimalValue(ListNode* head) {
        ListNode *cur = head;
        int ans = 0;

        while (cur) {
            ans = (ans << 1) + cur->val;
            //cout << ans << " " << cur->val << endl;
            cur = cur->next;
        }

        return ans;
    }
};
