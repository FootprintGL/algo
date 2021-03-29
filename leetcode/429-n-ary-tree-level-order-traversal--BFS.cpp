

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
    vector<vector<int>> levelOrder(Node* root) {
        /* BFS */
        vector<vector<int>> res;
        queue<Node *> qu;

        if (root == nullptr)
            return res;

        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                Node *cur = qu.front();
                temp.push_back(cur->val);
                qu.pop();
                for (auto &child : cur->children)
                    qu.push(child);
            }
            res.push_back(temp);
        }

        return res;
    }
};
