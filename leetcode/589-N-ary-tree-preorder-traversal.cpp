

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node *> stk;
        Node *cur;
        int i;

        if (root == nullptr)
            return res;

        stk.push(root);
        while (!stk.empty()) {
            Node *cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            /* 从右向左入栈 */
            for (i = cur->children.size() - 1; i >= 0; i--) {
                stk.push(cur->children[i]);
            }
        }

        return res;
    }
};
