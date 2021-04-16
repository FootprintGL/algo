

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
    int sum = 0;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        /* 先访问右子树 */
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        /* 再访问左子树 */
        dfs(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        dfs(root);
        return root;
    }
};
