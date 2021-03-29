

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
    vector<int> rightSideView(TreeNode* root) {
        /* BFS提取没一层最后一个节点的值 */
        vector<int> res;

        if (root == nullptr)
            return res;

        queue<TreeNode *> qu;
        qu.push(root);
        TreeNode *cur;

        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                cur = qu.front();
                qu.pop();
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
            /* 保存该层最后一个节点的值 */
            res.push_back(cur->val);
        }

        return res;
    }
};
