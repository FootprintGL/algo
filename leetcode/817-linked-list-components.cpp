

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
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        /* 哈希表加速查找 */
        unordered_set<int> tbl(G.begin(), G.end());
        /* 指针用来遍历链表 */
        ListNode *cur = head;
        /* 当前元素在组件中 */
        bool isin;

        while (cur) {
            if (tbl.count(cur->val)) {
                isin = true;
            } else {
                if (isin)
                    res++;
                /* 准备统计新的组件 */
                isin = false;
            }
            cur = cur->next;
        }

        /* 最后一个组件 */
        if (isin)
            res++;

        return res;
    }
};
