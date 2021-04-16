

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
    ListNode *head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        /*
         * 蓄水池抽样
         * 第n个数据以1/n的概率抽到，否则留下前n - 1个中的一个
         * 这样数据流中数据被选中的概率都一样
         */
        ListNode *p = head;
        int val = p->val;
        int n = 1;

        while (p) {
            if (rand() % n == 0)
                val = p->val;
            n++;
            p = p->next;
        }

        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
