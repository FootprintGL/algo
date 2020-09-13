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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
         * 假设后面两个链表相交于k
         * headA-k + k-end + headB-k = headB-k + k-end + headA-k
         * headA #
         *          #
         *              #   #   #   #
         *          #   K           end
         *      #
         * HeadB
         * 两个指针分别从headA和headB开始遍历，便利到结尾时，从另一个链表头开始遍历
         * 相遇时即为相交节点
         */
        ListNode *pa = headA, *pb = headB;

        while (pa != pb) {
            if (pa == NULL) {
                pa = headB;
            } else {
                pa = pa->next;
            }
            
            if (pb == NULL)
                pb = headA;
            else
                pb = pb->next;
        }

        return pa;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
         * 假设后面k个节点为相交公共节点
         * 先把尾部对齐，从短的开始依次检查是否为相交节点
         */
        int la = 0, lb = 0;
        ListNode *pa = headA, *pb = headB;

        /* 计算链表长度 */
        while (pa) {
            la++;
            pa = pa->next;
        }
        while (pb) {
            lb++;
            pb = pb->next;
        }

        /* pa遍历长的，pb遍历短的 */
        if (la < lb) {
            pa = headB;
            pb = headA;
        } else {
            pa = headA;
            pb = headB;
        }
    
        int diff = abs(la - lb);

        /* 先移动pa到diff使两链表尾部对齐 */
        while (pa && diff != 0) {
            pa = pa->next;
            diff--;
        }

        /* 寻找相交节点 */
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }

        return pa;
    }
};
