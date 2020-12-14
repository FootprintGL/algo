

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /* BFS */
        vector<vector<int>> res;
        queue<TreeNode *> qu;
        vector<int> tmp;
        bool l2r = true;

        if (root == nullptr)
            return res;

        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            tmp.clear();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = qu.front();
                qu.pop();
                if (l2r)
                    tmp.push_back(cur->val);
                else
                    tmp.insert(tmp.begin(), cur->val);
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            l2r = !l2r;
            res.push_back(tmp);
        }

        return res;
    }
};
