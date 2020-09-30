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
    vector<vector<int>> res;
    
    void dfs(TreeNode *root, vector<int> &path, int sum) {
        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val)
                res.push_back(path);
        }

        if (root->left)
            dfs(root->left, path, sum - root->val);
        
        if (root->right)
            dfs(root->right, path, sum - root->val);
        
        /* 回溯 */
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return res;
        vector<int> path;
        dfs(root, path, sum);
        return res;
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
    vector<vector<int>> res;

    void dfs(TreeNode *root, vector<int> &path, int sum) {
        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val)
                res.push_back(path);
            /* 回溯 */
            path.pop_back();
            return;
        }

        if (root->left)
            dfs(root->left, path, sum - root->val);

        if (root->right)
            dfs(root->right, path, sum - root->val);

        /* 回溯 */
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return res;
        vector<int> path;
        dfs(root, path, sum);
        return res;
    }
};
