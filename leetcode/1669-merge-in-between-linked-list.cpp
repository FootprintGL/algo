


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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        /*
         * 移出a-b个节点
         * a-1指向list2的header，list2的最后一个节点指向b + 1
         */
        ListNode *aprev, *bnext;
        ListNode *cur = list1;
        int cnt = 0;

        /* 找到a-1节点 */
        while (cnt < a - 1) {
            //cout << cnt << " " << a << " " << cur->val << endl;
            cur = cur->next;
            cnt++;
        }
        aprev = cur;

        /* 删除a~b节点，找到b+1节点 */
        cur = cur->next;
        while (cnt < b) {
            //cout << cnt << " " << b << " " << cur->val << endl;
            ListNode *t = cur;
            cur = cur->next;
            delete(t);
            cnt++;
        }
        bnext = cur;

        /* 找出list2最后一个节点 */
        ListNode *pre = list2;
        cur = list2->next;
        while (cur) {
            //cout << pre->val << " " << cur->val << endl;
            pre = cur;
            cur = cur->next;
        }

        /* list2链入list1 */
        aprev->next = list2;
        pre->next = bnext;

        return list1;
    }
};
