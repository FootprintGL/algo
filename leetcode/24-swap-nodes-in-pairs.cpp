

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
    /* 迭代算法 */
    ListNode* swapPairs(ListNode* head) {
        ListNode *pseudo = new ListNode(0);
        pseudo->next = head;
        ListNode *temp = pseudo, *first, *second;

        while (temp->next && temp->next->next) {
            first = temp->next;
            second = temp->next->next;
            temp->next = second;
            first->next = second->next;
            second->next = first;
            temp = first;
        }

        return pseudo->next;
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
    /* 递归 */
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;

        return next;
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *first = head, *second, *prev = nullptr, *next, *res = head;

        while (first) {
            second = first->next;
            if (second == nullptr) {
                break;
            }
            next = second->next;
            second->next = first;
            if (first == head) {
                res = second;
                prev = first;
            } else {
                prev->next = second;
                prev = first;
            }
            first = next;
        }

        if (first == nullptr) {
            /* 偶数个节点 */
            if (prev)
                prev->next = nullptr;
        } else {
            /* 奇数个节点 */
            if (prev)
                prev->next = first;
        }

        return res;
    }
};
