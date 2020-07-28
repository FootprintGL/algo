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
    /* 计算子树深度 */
    int depth(TreeNode *root) {
        int left, right;
        if (root == NULL)
            return 0;

        left = depth(root->left);
        right = depth(root->right);
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        /* 子树平衡，检查左右子树是否平衡 */
        if (abs(depth(root->left) - depth(root->right)) <= 1)
            return (isBalanced(root->left) && isBalanced(root->right));
        else
            return false;
    }
};
