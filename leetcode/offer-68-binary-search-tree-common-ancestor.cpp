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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return root;

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return root;

        if (root == p || root == q)
            return root;
        //cout << root << " " << root->left << " " << root->right << endl;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        if (left && right)
            return root;

        return NULL;
    }
};
