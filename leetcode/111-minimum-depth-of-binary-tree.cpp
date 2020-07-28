
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

    int minDepth(TreeNode* root) {
        int left, right;
        if (root == NULL) {
            return 0;
        }
        left = minDepth(root->left);
        right = minDepth(root->right);
        return left && right ? min(left, right) + 1 : left + right + 1;
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
    int mindep = INT_MAX;

    void dfs(TreeNode *root, int &depth) {
        if (!root->left && !root->right) {
            depth++;
            if (depth < mindep)
                mindep = depth;
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

    int minDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL)
            return 0;
        dfs(root, depth);
        return mindep;
    }
};
