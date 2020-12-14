


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
    int res = 0;

    void dfs(TreeNode *root, int &cur) {
        if (root == NULL)
            return;

        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            res += cur;
        }

        dfs(root->left, cur);
        dfs(root->right, cur);
        /* 回溯 */
        cur /= 10;
    }

    int sumNumbers(TreeNode* root) {
        int cur = 0;
        /* 回溯算法 */
        dfs(root, cur);
        return res;
    }
};
