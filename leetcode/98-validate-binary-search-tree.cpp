


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
    bool inorder(TreeNode *root, long &prev) {
        if (root == nullptr)
            return true;
        bool l = inorder(root->left, prev);
        if (root->val <= prev)
            return false;
        prev = root->val;
        bool r = inorder(root->right, prev);

        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        /* 中序遍历递增有序 */
        /* 初始化为long的最小值 */
        long prev = LONG_MIN;
        return inorder(root, prev);
    }
};
