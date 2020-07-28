

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
    /*
     * 如果p，q分布在左子树，则必在左儿子为根节点的子树
     * 如果p，q分布在右子树，则必在右儿子为根节点的子树
     * 否则，则root即为最近公共祖先
     * 递归下探，直到找到最近公共祖先
     */
    TreeNode *helper(TreeNode *root, int p, int q) {
        if (p < root->val && q < root->val)
            return helper(root->left, p, q);
        else if (p > root->val && q > root->val)
            return helper(root->right, p, q);
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p->val, q->val);
    }
};


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
    /*
     * 如果p，q分布在左右子树，则root即为最近公共祖先
     * 如果分布在左子树，则必在左儿子为根节点的子树
     * 如果分布在右子树，则必在右儿子为根节点的子树
     * 递归下探，直到找到最近公共祖先
     */
    TreeNode *helper(TreeNode *root, int p, int q) {
        if (p == root->val ||
            q == root->val ||
            (p < root->val && q > root->val) ||
            (p > root->val && q < root->val))
            return root;
        else if (p < root->val && q < root->val)
            return helper(root->left, p, q);
        else
            return helper(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p->val, q->val);
    }
};
