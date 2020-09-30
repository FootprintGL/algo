

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
    int res;

    int dfs(TreeNode *root) {
        int dis = 1;
        int left = 0, right = 0;
        int tl = 0, tr = 0;

        //cout << root << " " << root->left << " " << root->right << endl;

        if (root->left) {
            left = dfs(root->left);
            if (root->val == root->left->val) {
                //dis += left;
                left += 1;
                tl = left;
            }
        }

        if (root->right) {
            right = dfs(root->right);
            if (root->val == root->right->val) {
                //dis += right;
                right += 1;
                tr = right;
            }
        }

        dis += tl + tr;
        //cout << left << " " << right << " " << tl << " " << tr << " " << dis << " " << res << endl;
        res = max(res, dis);

        return max(tl, tr);
    }

    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        if (root == NULL)
            return 0;
        dfs(root);
        return res - 1;
    }
};
