


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
    vector<int> levelOrder(TreeNode* root) {
        /* BFS */
        vector<int> res;
        queue<TreeNode *>qu;
        TreeNode *cur;

        if (root == NULL)
            return res;

        qu.push(root);
        while (!qu.empty()) {
            cur = qu.front();
            qu.pop();
            res.push_back(cur->val);
            if (cur->left)
                qu.push(cur->left);
            if (cur->right)
                qu.push(cur->right);
        }

        return res;
    }
};
