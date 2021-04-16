

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
    int maxLevelSum(TreeNode* root) {
        /* BFS */
        int res = 1;
        int depth = 0;
        int summax = root->val, sum;
        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty()) {
            int size = qu.size();

            /* 统计当前层和 */
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
            depth++;
            if (sum > summax) {
                /* 找到更大的层和，更新层号 */
                summax = sum;
                res = depth;
            }
        }

        return res;
    }
};
