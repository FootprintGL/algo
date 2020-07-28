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
    bool helper(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;

        /* 一个为空，一个不为空 */
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        
        if (p->val == q->val)
            /* 左右子树都相同 */
            return (helper(p->left, q->left) && helper(p->right, q->right));
        else
            /* 节点数据不同 */
            return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};
