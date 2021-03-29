

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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
         * 先将链表闭合成环，再找到相应的位置断开，确定新的头和尾
         */
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        /* 闭合链表并统计节点个数 */
        ListNode *oldtail = head;
        int n = 1;
        while (oldtail->next) {
            oldtail = oldtail->next;
            n++;
        }
        oldtail->next = head;

        /* 找到相应的位置 */
        k = n - k % n;
        ListNode *cur = head;
        while (k > 1) {
            cur = cur->next;
            k--;
        }

        /* 断开指针 */
        head = cur->next;
        cur->next = nullptr;

        return head;
    }
};


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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
         * 设链表节点个数为n
         *      1 k < n，快慢指针
         *      2 k > n, 移动n的倍数时链表还原，剩余k/n,和情况1相同
         */
        if (head == nullptr || k == 0)
            return head;

        /* 统计链表节点个数 */
        int n = 0;
        /* 记录最后一个节点 */
        ListNode *tail = nullptr;
        ListNode *cur = head;
        while (cur) {
            tail = cur;
            cur = cur->next;
            n++;
        }

        /* 计算剩余节点和第n - k个节点 */
        k %= n;
        cur = head;
        k = n - k;
        while (k > 1) {
            cur = cur->next;
            k--;
        }

        /* 重新链接链表 */
        tail->next = head;
        head = cur->next;
        cur->next = nullptr;

        return head;
    }
};
