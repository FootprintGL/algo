

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        /* DFS */
        if (original == NULL)
            return NULL;

        if (original == target)
            return cloned;

        TreeNode* tmp = getTargetCopy(original->left, cloned->left, target);
        if (tmp != NULL)
            return tmp;

        tmp = getTargetCopy(original->right, cloned->right, target);

        return tmp;
    }
};
