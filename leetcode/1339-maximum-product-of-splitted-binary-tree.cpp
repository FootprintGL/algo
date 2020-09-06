

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
    unordered_set<long> sums;
    long M;

    int dfs(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = (left + right + root->val) % M;
        sums.insert(sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        long ans = 0, total;
        M = 10e8 + 7;

        total = dfs(root);
        for (auto sum : sums) {
            long tmp = ((total - sum) * sum);
            if (tmp > ans)
                ans = tmp;
        }

        return (int)(ans % M);
    }
};
