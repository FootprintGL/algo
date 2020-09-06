

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
    /* 树的坡度 */
    int ans;

    /* 计算子树的节点和 */
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int x = dfs(root->left);
        int y = dfs(root->right);
        /* 更新坡度和 */
        ans += abs(x - y);

        /* 返回root子树的节点和 */
        return (x + y + root->val);
    }

    int findTilt(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
