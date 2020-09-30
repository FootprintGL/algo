
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
    string tree2str(TreeNode* t) {
        if (t == NULL)
            return "";
        if (t->left == NULL && t->right == NULL)
            return to_string(t->val);
        if (t->right == NULL)
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
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
    string res;

    void preorder(TreeNode *root) {
        res += to_string(root->val);
        if (root->left == NULL && root->right == NULL)
            return;

        if (root->left == NULL) {
            res += "()";
            res += '(';
            preorder(root->right);
            res += ')';
        } else if (root->right == NULL) {
            res += '(';
            preorder(root->left);
            res += ')';
        } else {
            res += '(';
            preorder(root->left);
            res += ')';
            res += '(';
            preorder(root->right);
            res += ')';
        }
    }

    string tree2str(TreeNode* t) {
        if (t == NULL)
            return res;
        preorder(t);
        return res;
    }
};
