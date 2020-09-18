

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
    int minimum;
    int ans;

    void dfs(TreeNode *root) {
        if (root == NULL)
            return;

        if (root->val == minimum) {
            dfs(root->left);
            dfs(root->right);
        } else if (root->val < ans || ans == minimum) {
            ans = root->val;
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        /* 根节点最小，寻找子树根节点不等于根节点的最小值 */
        if (root == NULL)
            return -1;

        ans = minimum = root->val;
        dfs(root);

        return ans == minimum ? -1 : ans;
    }
};
