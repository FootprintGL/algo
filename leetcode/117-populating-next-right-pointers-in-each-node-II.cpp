



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
    /* root的下一个节点 */
    Node *nextnode(Node *root) {
        while (root != NULL) {
            if (root->left != NULL)
                return root->left;

            if (root->right != NULL)
                return root->right;

            root = root->next;
        }

        return NULL;
    }

    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;

        if (root->left) {
            if (root->right) {
                /* 右儿子存在 - 左儿子next指向右儿子 */
                root->left->next = root->right;
            } else {
                /* 右儿子存在 - 左儿子next指向父节点下一个节点 */
                root->left->next = nextnode(root->next);
            }
        }

        if (root->right) {
            /* 右儿子指向父节点下一个节点 */
            root->right->next = nextnode(root->next);
        }

        /* 先处理右边，再处理左边 */
        connect(root->right);
        connect(root->left);

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
