


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
    vector<string> res;

    void dfs(TreeNode *root, string cur) {
        cur += to_string(root->val);
        if (root->left ==nullptr && root->right == nullptr) {
            res.push_back(cur);
            return;
        }

        cur += "->";
        if (root->left)
            dfs(root->left, cur);

        if (root->right)
            dfs(root->right, cur);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string cur;

        if (root == nullptr)
            return res;

        dfs(root, cur);

        return res;
    }
};
