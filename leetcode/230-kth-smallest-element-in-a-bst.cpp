

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
    int cur;
    int res;
    int k;

    /* 中序遍历 */
    void inorder(TreeNode *root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        cur++;
        //cout << cur << " " << k << endl;
        if (cur == k) {
            res = root->val;
            return;
        }
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        res = 0;
        cur = 0;
        this->k = k;
        inorder(root);
        return res;
    }
};
