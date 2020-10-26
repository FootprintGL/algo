


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
     * 中序遍历
     * 如果节点p的值大于等于root的值，说明p的后继节点在右子树中
     * 如果节点p的之小于root的值，说明p在左子树中
     *      1. 如果在左子树中找到后继节点，直接返回答案
     *      2. 如果在左子树中没有找到后继节点，说明p的右儿子为空，那么root就是它的后继节点
     */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL)
            return NULL;

        if (p->val >= root->val) {
        /* 在右子树 */
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode *left = inorderSuccessor(root->left, p);
            /* 在左子树找到则返回结果，找不到则返回根节点 */
            return left ? left : root;
        }
    }
};
