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
    int diameter;

    /* DFS - 计算子树的深度，极为根节点到叶子节点最长路径上节点个数 */
    int dfs(TreeNode *root) {
        int leftdep, rightdep;
        
        if (root == NULL) 
            return 0;
        /* 计算左子树深度 */
        leftdep = dfs(root->left);
        /* 计算右子树深度 */
        rightdep = dfs(root->right);
        /* 记录最长直径 */
        if (leftdep + rightdep + 1 > diameter)
            diameter = leftdep + rightdep + 1;
        /* 返回子树的深度 */
        return max(leftdep, rightdep) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return max(diameter - 1, 0);
    }
};
