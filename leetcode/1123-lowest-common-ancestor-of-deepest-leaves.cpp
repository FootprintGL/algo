


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
    int depth(TreeNode *root) {
        /* 计算子树深度 */
        return root ? max(depth(root->left), depth(root->right)) + 1 : 0;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        /*
         * 如果左右子树高度相等，当前节点即为结果
         * 如果左右子树高度不相等，结果在高的子树中
         */
        if (root == nullptr)
            return nullptr;

        int lheight = depth(root->left);
        int rheight = depth(root->right);

        //cout << lheight << " " << rheight << endl;

        if (lheight == rheight)
            return root;
        else if (lheight < rheight)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
};
