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
    int res;
    int cnt;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        dfs(root->right);
        if (cnt == 0)
            return;
        if (--cnt == 0) {
            res = root->val;
            return;
        }
        dfs(root->left);
    }

    int kthLargest(TreeNode* root, int k) {
        /* 二叉搜索树中序遍历递增有序,中序遍历倒序为递减有序 */
        cnt = k;
        dfs(root);
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
    vector<int> res;

    void dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }

    int kthLargest(TreeNode* root, int k) {
        /* 二叉搜索树中序遍历递增有序 */
        dfs(root);
        return res[res.size() - k];
    }
};
