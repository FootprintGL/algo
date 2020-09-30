

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

    void dfs(TreeNode *root, int sum) {
        sum -= root->val;
        //cout << root << " " << root->val << " " << sum << endl;

        if (sum == 0)
            res++;

        if (root->left)
            dfs(root->left, sum);

        if (root->right)
            dfs(root->right, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            //return sum == 0 ? 1 : 0;
            return 0;

        dfs(root, sum);

        if (root->left)
            pathSum(root->left, sum);

        if (root->right)
            pathSum(root->right, sum);

        return res;
    }
};
