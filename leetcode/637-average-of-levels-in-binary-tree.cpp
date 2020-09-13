

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
    vector<double> averageOfLevels(TreeNode* root) {
        /* BFS */
        vector<double> res;
        queue<TreeNode *> qu;
        TreeNode *cur;

        if (root == NULL)
            return res;

        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            double sum = 0;

            for (int i = 0; i < size; i++) {
                cur = qu.front();
                qu.pop();
                sum += cur->val;
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            res.push_back((double)sum / size);
        }

        return res;
    }
};
