

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
    /* 求树的深度 */
    int depth(TreeNode *root) {
        if (root == NULL)
            return 1;
        int ldep = depth(root->left);
        int rdep = depth(root->right);
        return max(ldep, rdep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int ldep = depth(root->left);
        int rdep = depth(root->right);

        /* 深度相差小于等于1，并且左右字数也是平衡二叉树 */
        return abs(ldep - rdep) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
