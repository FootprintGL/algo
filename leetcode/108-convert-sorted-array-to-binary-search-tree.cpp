/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
public:
    /*
     * DFS - 构建二叉搜索树
     * 选择[start, end]居中元素[(start + end) / 2]为root, 左半部分中间为左子树节点，右半部分中间为右子树节点
     * 递归调用构建以root为根的子树
     */
    TreeNode* createbst(vector<int> &nums, int start, int end) {

        if (start > end) {
            return NULL;
        }

        int m = (end + start + 1) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = createbst(nums, start, m - 1);
        root->right = createbst(nums, m + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createbst(nums, 0, nums.size() - 1);
    }
};

class Solution {
public:
    /* 
     * DFS - 构建二叉搜索树
     * 选择[start, end]居中元素[(start + end) / 2]为root, 左半部分中间为左子树节点，右半部分中间为右子树节点
     * 递归调用构建以root为根的子树
     */
    void createbst(TreeNode *root, vector<int> &nums, int start, int end) {
        int l, m, r;

        if (start == end) {
            return;
        }

        /* m为[start, end]的中间元素 */
        m = (end + start + 1) / 2;

        /* 一定有左子树，构建左子树 - l为[start, m - 1]中间元素 */
        l = (start + m - 1 + 1) / 2;
        root->left = new(TreeNode);
        root->left->val = nums[l];
        createbst(root->left, nums, start, m - 1);

        /* 如果有右子树，构建右子树 - r为[m + 1, end]中间元素 */
        if (m != end) {
            r = (m + 1 + end + 1) / 2;
            root->right = new(TreeNode);
            root->right->val = nums[r];
            createbst(root->right, nums, m + 1, end);
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root;
        int n = nums.size();

        /* 空数组 - 返回空树 */
        if (n == 0)
            return NULL;

        root = new (TreeNode);
        root->val = nums[n/2];

        createbst(root, nums, 0, n - 1);

        return root;
    }
};
