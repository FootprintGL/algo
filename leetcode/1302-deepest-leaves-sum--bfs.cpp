

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
    int deepestLeavesSum(TreeNode* root) {
        /* BFS - 计算最后一层元素的和 */
        int sum;
        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty()) {
            int size = qu.size();
            sum = 0;
            for (int i = 0; i < size; i++) {
                auto cur = qu.front();
                qu.pop();
                sum += cur->val;
                if (cur->left)
                    qu.push(cur->left);
                if (cur->right)
                    qu.push(cur->right);
            }
        }

        return sum;
    }
};
