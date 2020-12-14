


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
    int res;

    /* 前序遍历 */
    void dfs(TreeNode *root, int curmax) {
        if (root == nullptr)
            return;

        if (root->val >= curmax) {
            curmax = root->val;
            res++;
        }

        dfs(root->left, curmax);
        dfs(root->right, curmax);
    }

    int goodNodes(TreeNode* root) {
        res = 0;
        dfs(root, INT_MIN);
        return res;
    }
};
