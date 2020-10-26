


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

    void dump(vector<int> &path) {
        for (auto &t : path)
            cout << t << " ";
        cout << endl;
    }

    void dfs(TreeNode *root, vector<int> &path, int &cur, int sum) {
        cur += root->val;
        path.push_back(root->val);
        //cout << root << " " << root->val << " " << cur << " " << sum << endl;
        //dump(path);
        //cout << endl;

        if (root->left == NULL && root->right == NULL) {
            /* 叶子节点 */
            if (cur == sum)
                res.push_back(path);
            path.pop_back();
            cur -= root->val;
            return;
        }

        if (root->left)
            dfs(root->left, path, cur, sum);
        if (root->right)
            dfs(root->right, path, cur, sum);
        /* 回溯 */
        cur -= root->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        int cur = 0;
        if (root == NULL)
            return res;
        dfs(root, path, cur, sum);
        return res;
    }
};
