

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
    vector<int> vec;

    /* 中序遍历构建有序数组 */
    void helper(TreeNode *root) {
        if (root) {
            helper(root->left);
            vec.push_back(root->val);
            helper(root->right);
        }
    }

    /* 有序数组构建二叉搜索树 */
    TreeNode *rebuild(int left, int right) {
        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(vec[mid]);
        root->left = rebuild(left, mid - 1);
        root->right = rebuild(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        /*
         * 二叉搜索树中序遍历有序
         * 先遍历够关键有序数组，再递归构建平衡二叉搜索树
         */
        helper(root);
        return rebuild(0, vec.size() - 1);
    }
};
