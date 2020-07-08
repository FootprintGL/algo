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
    /* DFS - 递归算法 */
    bool hasPathSum(TreeNode* root, int sum) {
        /* 空树 */
        if (!root)
            return false;
            //return (sum == 0);
        /* 叶子节点 */
        if (!root->left && !root->right)
            return (sum == root->val);
        /* 处理左子树 */
        if (root->left && hasPathSum(root->left, sum - root->val))
            return true;
        /* 处理右子树 */
        if (root->right && hasPathSum(root->right, sum - root->val))
            return true;

        return false;
    }
};
