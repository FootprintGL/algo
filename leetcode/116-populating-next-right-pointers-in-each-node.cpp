
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /* 完美二叉树 - 所有叶子在同一层 */
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;

        if (root->left)
            root->left->next = root->right;

        if (root->right && root->next)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);
        return root;
    }
};




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /* BFS - 层序遍历 */
        queue<Node *> qu;

        if (root == NULL)
            return NULL;

        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                Node *cur = qu.front();
                qu.pop();
                if (i == size - 1)
                    /* 该层最后一个节点，next指向NULL */
                    cur->next = NULL;
                else
                    /* next只想该层下一个元素 */
                    cur->next = qu.front();
                /* 左右孩子入队 */
                if (cur->left)
                    qu.push(cur->left);

                if (cur->right)
                    qu.push(cur->right);
            }
        }

        return root;
    }
};
