

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
    int M;

    void dfs(TreeNode *root, int cur) {
        //cout << root << " " << cur << endl;

        /* 注意: 算数+运算符比移位运算符<<优先级高 */
        if (root->left == nullptr && root->right == nullptr) {
            /* 叶子节点 */
            ans = (ans + (cur << 1) + root->val) % M;
            return;
        }

        if (root->left)
            dfs(root->left, (cur << 1) + root->val);
        if (root->right)
            dfs(root->right, (cur << 1) + root->val);
    }

    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        M = 1000000007;
        if (root)
            dfs(root, 0);
        return ans;
    }
};
