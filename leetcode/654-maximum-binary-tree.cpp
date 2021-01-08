

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
    TreeNode* dfs(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        /* 找区间范围[start, end]最大值和坐标 */
        int maxidx = start;
        int maxv = nums[start];
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] > maxv) {
                maxv = nums[i];
                maxidx = i;
            }
        }

        /* 递归构建子树 */
        TreeNode *root = new TreeNode(maxv);
        root->left = dfs(nums, start, maxidx - 1);
        root->right = dfs(nums, maxidx + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};
