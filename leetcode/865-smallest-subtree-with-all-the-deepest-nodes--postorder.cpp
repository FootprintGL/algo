

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
    TreeNode *dfs(TreeNode *root, int &height) {
        if (root == nullptr) {
            height = 0;
            return nullptr;
        }

        int leftheight, rightheight;

        auto left = dfs(root->left, leftheight);
        auto right = dfs(root->right, rightheight);
        height = max(leftheight, rightheight) + 1;

        if (leftheight == rightheight)
            return root;
        else if (leftheight < rightheight)
            return right;
        else
            return left;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        /*
         * 后序遍历
         * 如果左右子树高度相等，当前节点即为结果
         * 如果左右子树高度不相等，结果在高的子树中
         */
        int height;
        return dfs(root, height);
    }
};
