

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
    TreeNode *prev = NULL;

    bool isValidBST(TreeNode* root) {
        /* 二叉搜索树中序遍历有序 */
        if (root == NULL)
            return true;

        /* 检查左子树 */
        if (!isValidBST(root->left))
            return false;

        /* 检测是否递增 */
        if (prev && prev->val >= root->val)
            return false;

        /* 更新prev */
        prev = root;

        /* 检测右子树 */
        if (!isValidBST(root->right))
            return false;

        return true;
    }
};
