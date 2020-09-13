

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode *> par;
    unordered_map<int, bool> visited;

    void helper(TreeNode *root) {
        if (root->left) {
            par[root->left->val] = root;
            helper(root->left);
        }

        if (root->right) {
            par[root->right->val] = root;
            helper(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
         * 遍历保存每个节点的父节点到哈希表
         * 从p向上搜索祖先节点，并记录已经访问节点
         * 从q向上搜索祖先节点，如果已经出现在记录中
         * 则该祖先就是最近公共祖先
         */
        if (root == NULL)
            return NULL;
        par[root->val] = NULL;
        helper(root);

        while (p) {
            visited[p->val] = true;
            p = par[p->val];
        }

        while (q) {
            if (visited[q->val])
                return q;
            q = par[q->val];
        }

        return NULL;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        if (left && !right)
            return left;

        if (right && !left)
            return right;

        return NULL;
    }
};
