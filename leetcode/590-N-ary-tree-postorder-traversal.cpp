

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
    vector<int> res;

    /* 迭代算法 - 父节点后面压入nullptr做标记 */
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return {};
        
        stack<Node *> stk;
        Node *cur;

        stk.push(root);
        while (!stk.empty()) {
            cur = stk.top();
            if (cur == nullptr) {
                stk.pop();
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                continue;
            }

            stk.push(nullptr);
            for (int i = cur->children.size() - 1; i >= 0; i--)
                stk.push(cur->children[i]);
        }

        return res;
    }
};

class Solution {
public:
    vector<int> res;

    /* 递归算法 */
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return {};

        for (int i = 0; i < root->children.size(); i++) {
            postorder(root->children[i]);
        }
        res.push_back(root->val);

        return res;
    }
};
