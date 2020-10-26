




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *head;
    Node *prev;

    /* 中序遍历 */
    void dfs(Node *cur) {
        if (cur == NULL)
            return;

        dfs(cur->left);
        if (prev) {
            /* 前驱节点right指向curr */
            prev->right = cur;
        } else {
            head = cur;
        }
        /* left指向前驱节点 */
        cur->left = prev;
        prev = cur;
        dfs(cur->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        head = prev = NULL;
        dfs(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
};
