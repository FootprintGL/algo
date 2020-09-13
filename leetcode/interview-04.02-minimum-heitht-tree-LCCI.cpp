

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
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *root = new (TreeNode);
        root->val = nums[mid];
        root->left = dfs(nums, left, mid - 1);
        root->right = dfs(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = nullptr;
        int n = nums.size();
        if (n == 0)
            return root;
        root = dfs(nums, 0, n - 1);
        return root;
    }
};
