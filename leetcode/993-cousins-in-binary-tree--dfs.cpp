
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> dep;
    unordered_map<int, int> par;
    void dfs(TreeNode *node, TreeNode *parent) {
        if (node != nullptr) {
            par[node->val] = parent == nullptr ? 0 : parent->val;
            dep[node->val] = parent == nullptr ? 0 : dep[parent->val] + 1;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        /*
         * dfs
         * 分别记录节点对应的父节点和深度
         * x,y如果深度相同，父节点不同，则为堂兄弟节点
         */
        dfs(root, NULL);
        return((dep[x] == dep[y]) && (par[x] != par[y]));
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> dep;
    unordered_map<int, TreeNode*> par;
    void dfs(TreeNode *node, TreeNode *parent) {
        if (node != nullptr) {
            par[node->val] = parent;
            dep[node->val] = parent == nullptr ? 0 : dep[parent->val] + 1;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        /*
         * dfs
         * 分别记录节点对应的父节点和深度
         * x,y如果深度相同，父节点不同，则为堂兄弟节点
         */
        dfs(root, NULL);
        return((dep[x] == dep[y]) && (par[x] != par[y]));
    }
};
