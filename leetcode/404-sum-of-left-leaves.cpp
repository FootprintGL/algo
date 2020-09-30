

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
    int ans;

    void dfs(TreeNode *root, bool left) {
        if (root->left == NULL && root->right == NULL) {
            if (left)
                ans += root->val;
            return;
        }

        if (root->left)
            dfs(root->left, true);

        if (root->right)
            dfs(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;

        if (root == NULL)
            return ans;

        dfs(root, false);

        return ans;
    }
};
