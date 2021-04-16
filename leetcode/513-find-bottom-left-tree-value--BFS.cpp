

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
    int findBottomLeftValue(TreeNode* root) {
        /*
         * BFS
         * 层序遍历，保存每一层第一个元素，最后一层第一个元素即为结果
         */
        queue<TreeNode *> qu;
        qu.push(root);
        int res = root->val;

        while (!qu.empty()) {
            /* 保存每层第一个元素 */
            res = qu.front()->val;
            int n = qu.size();

            for (int i = 0; i < n; i++) {
                TreeNode *t = qu.front();
                qu.pop();
                if (t->left)
                    qu.push(t->left);
                if (t->right)
                    qu.push(t->right);
            }
        }

        return res;
    }
};
