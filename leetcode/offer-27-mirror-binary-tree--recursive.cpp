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
    /* 交换子树左右子树 */
    void dfs(TreeNode *root) {
        TreeNode *node;

        if (root == NULL)
            return;

        /* 交换左子树 */
        dfs(root->left);
        /* 交换右子树 */
        dfs(root->right);
        /* 交换左右儿子 */
        node = root->left;
        root->left = root->right;
        root->right = node;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
