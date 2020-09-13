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
    int cur = 0;

    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL)
            return NULL;
        
        convertBST(root->right);
        cur += root->val;
        root->val = cur;
        convertBST(root->left);
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
    int sum;
    void dfs(TreeNode *root, int &cur) {
        if (root == NULL)
            return;

        //cout << root << " " << root->right << " " << root->left << endl;

        dfs(root->right, cur);
        cur += root->val;
        root->val = cur;
        dfs(root->left, cur);
    }

    TreeNode* convertBST(TreeNode* root) {
        int cur = 0;
        dfs(root, cur);
        return root;
    }
};
