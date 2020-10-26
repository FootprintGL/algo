

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
    /* 检查A是否包含B */
    bool dfs(TreeNode *A, TreeNode *B) {
        if (B == NULL)
            return true;

        if (A == NULL)
            return false;

        if (A->val == B->val)
            return dfs(A->left, B->left) && dfs(A->right, B->right);

        return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL)
            return false;

        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
