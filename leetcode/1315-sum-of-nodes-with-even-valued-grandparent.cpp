

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
    int res;

    void dfs(TreeNode *root, TreeNode *parent, TreeNode *grandparent) {
        if (root == nullptr)
            return;

        if (grandparent != nullptr && grandparent->val % 2 == 0)
            /* 祖父节点为偶数 */
            res += root->val;

        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        res = 0;
        dfs(root, NULL, NULL);
        return res;
    }
};
