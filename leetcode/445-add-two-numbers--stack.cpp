

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
         * 堆栈 - 需要反序操作，可以借助堆栈处理
         * 高位在前面，借助栈翻转，从栈顶到栈底依次做加法处理
         */
        int carry = 0;
        ListNode *l = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *p = nullptr;
        stack<int> stk1, stk2;

        /* l1,l2放入堆栈 */
        while (p1) {
            stk1.push(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            stk2.push(p2->val);
            p2 = p2->next;
        }

        /* 模拟加法 */
        while (!stk1.empty() || !stk2.empty() || carry) {
            //cout << carry << " ";
            if (!stk1.empty()) {
                carry += stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                carry += stk2.top();
                stk2.pop();
            }
            //cout << carry << endl;
            auto cur = new ListNode(carry % 10);
            carry /= 10;
            cur->next = p;
            p = cur;
        }

        return p;
    }
};
