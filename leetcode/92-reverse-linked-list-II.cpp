

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return nullptr;

        /*
         * 先找到第m个节点 - 翻转链表的起始位置
         * 引入tail和con指针，tail指向第m个节点，con指向第m个节点的前一个节点
         * 翻转m到n的节点，prev只想第n个节点，cur指向第n + 1个节点
         * con指针链接prev指针，tail链接prev的下一个指针
         */
        ListNode *prev = nullptr;
        ListNode *cur = head;

        /* 找第m个节点 - cur指向第m个节点，prev指向前一个节点 */
        while (m > 1) {
            prev = cur;
            cur = cur->next;
            m--;
            n--;
        }

        ListNode *con = prev;
        ListNode *tail = cur;
        ListNode *next = nullptr;
        /* 翻转m到n的节点 */
        while (n > 0) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            n--;
        }

        /* 链接翻转后的链表 */
        if (con)
            con->next = prev;
        else
            head = prev;

        tail->next = cur;

        return head;
    }
};
