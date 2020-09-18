
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        /* BFS */
        vector<vector<int>> res;
        vector<int> tmp;
        queue<TreeNode *> qu;

        if (root == nullptr)
            return res;

        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            tmp.clear();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = qu.front();
                qu.pop();
                tmp.push_back(cur->val);
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            res.push_back(tmp);
        }

        return res;
    }
};
