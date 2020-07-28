
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
    int maxDepth(TreeNode* root) {
        int left, right;
        if (root == NULL) {
            return 0;
        }
        left = maxDepth(root->left);
        right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};


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
    int maxdep = 0;
    void dfs(TreeNode *root, int &depth) {
        if (!root->left && !root->right) {
            depth++;
            if (depth > maxdep)
                maxdep = depth;
            return;
        }
        depth++;
        if (root->left) {
            dfs(root->left, depth);
            depth--;
        }
        if (root->right) {
            dfs(root->right, depth);
            depth--;
        }
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL) {
            return 0;
        }
        dfs(root, depth);
        return maxdep;
    }
};
