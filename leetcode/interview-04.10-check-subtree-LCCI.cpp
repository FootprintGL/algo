

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
    /* 检查2棵树是否相等 */
    bool sametree(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL && t2 == NULL)
            return true;

        if (t1 == NULL || t2 == NULL)
            return false;

        return t1->val == t2->val && sametree(t1->left, t2->left) && sametree(t1->right, t2->right);
    }

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t2 == NULL)
            return true;

        if (t1 == NULL)
            return false;

        if (t1->val == t2->val) {
            if (sametree(t1, t2))
                return true;
        }

        return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
};
