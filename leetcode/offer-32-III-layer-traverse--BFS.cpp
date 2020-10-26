


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
        vector<vector<int>> res;
        vector<int> tmp;
        queue<TreeNode *> qu;
        TreeNode *cur;
        int i, size;
        bool flag = true;

        /* BFS */
        if (root == NULL)
            return res;

        qu.push(root);
        while (!qu.empty()) {
            size = qu.size();
            for (i = 0; i < size; i++) {
                cur = qu.front();
                qu.pop();
                if (flag)
                    tmp.push_back(cur->val);
                else
                    tmp.insert(tmp.begin(), cur->val);
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            res.push_back(tmp);
            tmp.clear();
            flag = !flag;
        }

        return res;
    }
};
