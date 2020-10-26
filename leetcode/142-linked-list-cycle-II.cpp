
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
    ListNode *detectCycle(ListNode *head) {
        /*
         * 双指针
         * 快慢指针，fast走2步，slow走1步
         *      1. 如果没有环fast会率先走到NULL
         *      2. 如果有环，第一次相遇是f = 2 * s, f = s + n * b - b为环上节点个数
         *          相减可得s = n * b, s还需要再走a不到达入环第一个节点
         *          从head走a步恰好也到达入环第一个节点
         */
        ListNode *fast, *slow;
        bool meet = false;

        fast = slow = head;
        while (1) {
            if (fast == NULL || fast->next == NULL)
            /* 无还 */
                return NULL;

            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            /* 第一次相遇 */
                break;
        }

        /* fast从head走a步与slow在入环第一个节点相遇 */
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
    
        return fast;
    }
};


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
    ListNode *detectCycle(ListNode *head) {
        /*
         * 双指针
         * 快慢指针，fast走2步，slow走1步
         *      1. 如果没有环fast会率先走到NULL
         *      2. 如果有环，第一次相遇是f = 2 * s, f = a + n * b - b为环上节点个数
         *          相减可得s = n * b, s还需要再走a不到达入环第一个节点
         *          从head走a步恰好也到达入环第一个节点
         */
        ListNode *fast, *slow;
        bool meet = false;

        fast = slow = head;
        while (fast && fast->next) {
            if (meet == false) {
                slow = slow->next;
                fast = fast->next->next;
            } else {
                slow = slow->next;
                fast = fast->next;
            }

            if (fast == slow) {
                if (meet || slow == head)
                /* 第二次相遇或者第一次相遇是slow为head节点，节点即为入环第一个节点 */
                    return fast;

                /* 第一次相遇, fast从head走a步与slow在入环第一个节点处相遇 */
                fast = head;
                meet = true;
            }
        }

        return NULL;
    }
};



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
    ListNode *detectCycle(ListNode *head) {
        /* 哈希表 */
        unordered_set<ListNode *> tbl;

        ListNode *cur = head;
        while (cur) {
            if (tbl.count(cur))
                return cur;
            tbl.insert(cur);
            cur = cur->next;
        }

        return NULL;
    }
};
