

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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode *cur = head;

        while (cur) {
            res.insert(res.begin(), cur->val);
            cur = cur->next;
        }

        return res;
    }
};
