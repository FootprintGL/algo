
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
    bool dfs(TreeNode *left, TreeNode *right) {
        //cout << left << " - " << right << endl;
        if (left == NULL && right == NULL)
            return true;
        //cout << left << " -- " << right << endl;
        if (left == NULL || right == NULL)
            return false;
        //cout << left << " --- " << right << " " << left->val << " " << right->val << endl;
        return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return dfs(root->left, root->right);
    }
};
