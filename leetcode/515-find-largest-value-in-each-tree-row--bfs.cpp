

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> qu;
        if (root == nullptr)
            return res;

        /* BFS */
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            int tmax = qu.front()->val;
            for (int i = 0; i < size; i++) {
                auto cur = qu.front();
                qu.pop();
                if (cur->val > tmax)
                    tmax = cur->val;
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            res.push_back(tmax);
        }

        return res;
    }
};
