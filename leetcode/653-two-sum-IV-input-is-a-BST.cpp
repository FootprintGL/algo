

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
    bool dfs(TreeNode *root, int k, unordered_set<int> &tbl) {
        if (root == nullptr)
            return false;
        if (tbl.count(k - root->val))
            return true;
        tbl.insert(root->val);
        return dfs(root->left, k, tbl) || dfs(root->right, k, tbl);
    }

    bool findTarget(TreeNode* root, int k) {
        /* 哈希表 */
        unordered_set<int> tbl;
        return dfs(root, k, tbl);
    }
};
