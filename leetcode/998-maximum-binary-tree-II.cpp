

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        /*
         * 将val放在数组的最后面
         * 如果val为最大值，则将root放在左边
         * 否则一直在右子树递归 - 最大值右侧的为右子树元素
         */
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (root->val < val) {
            /* 如果val是最大值,则将root放在左边 */
            TreeNode *tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        } else if (root->val > val) {
            /* 否则放在 */
            root->right = insertIntoMaxTree(root->right, val);
        }

        return root;
    }
};
