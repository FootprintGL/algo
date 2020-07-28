



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
    vector<int> dfs(TreeNode *root) {
        if (root == NULL)
            return {0,0};

        vector<int> dp(2, 0);
        vector<int> left;
        vector<int> right;
        left = dfs(root->left);
        right = dfs(root->right);
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        dp[1] = root->val + left[0] + right[0];
        return dp;
    }

    int rob(TreeNode* root) {
        int ans;
        vector<int> dp;

        /*
         * 动态规划 - 后序遍历
         * dp[node][i]表示节点node偷或者不偷能活动的最大值
         * i == 0 -> 不偷
         * i == 1 -> 偷
         * dp[node][0] = max(dp[node->left][0], dp[node->left][1]) + max(dp[node->right][0], max(dp[node->right[1]]))
         * dp[node][1] = node->val + dp[node->left][0] + dp[node->right][0]
         */
        dp = dfs(root);

        return max(dp[0], dp[1]);
    }
};
