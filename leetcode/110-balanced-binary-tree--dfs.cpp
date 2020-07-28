

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
    int height(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int left, right;
        left = height(root->left);
        right = height(root->right);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        int depth = 0;
        int left, right;

        if (root == NULL)
            return true;

        left = height(root->left);
        right = height(root->right);

        if (abs(left - right) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
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
    bool dfs(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        //cout << root << " " << root->left << " " << root->right << endl;
        int left = 0, right = 0;
        if (!dfs(root->left, left))
            return false;
        if (!dfs(root->right, right))
            return false;

        depth = max(left, right) + 1;
        //cout << left << " " << right << endl;

        return abs(left - right) <= 1;
    }

    bool isBalanced(TreeNode* root) {
        int depth = 0;;

        if (root == NULL)
            return true;

        return dfs(root, depth);
    }
};
