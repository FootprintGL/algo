

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        /* 扁平化 - 前序遍历 - 迭代 */
        if (head == nullptr)
            return head;

        stack<Node *> stk;
        Node *dummy = new Node(0, nullptr, head, nullptr);
        Node *cur, *prev = dummy;

        stk.push(head);
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            /* 连接prev和cur */
            prev->next = cur;
            cur->prev = prev;

            if (cur->next)
            /* next先入栈 */
                stk.push(cur->next);

            if (cur->child) {
            /* child入栈 */
                stk.push(cur->child);
                cur->child = nullptr;
            }

            /* prev/cur后移 */
            prev = cur;
            cur = cur->next;
        }

        /* 还原head的prev指针 */
        head->prev = nullptr;

        return dummy->next;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *preorder(Node *prev, Node *cur) {
        if (cur == nullptr)
            return prev;

        /* 连接prev和cur */
        prev->next = cur;
        cur->prev = prev;
        /* 保持next指针 */
        Node *next = cur->next;

        /* 遍历左子树 */
        Node *tail = preorder(cur, cur->child);
        /* child置空 */
        cur->child = nullptr;
        /* 处理右子树 */
        return preorder(tail, next);
    }

    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;
        /* 扁平化 - 二叉树的前序遍历 */
        Node *dummy = new Node(0, nullptr, head, nullptr);
        preorder(dummy, head);
        head->prev = nullptr;
        return head;
    }
};
