

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> qu;
        TreeNode *p, *q;

        if (root == NULL)
            return true;

        /* 左右子树根节点入队 */
        qu.push(root->left);
        qu.push(root->right);
        while (!qu.empty()) {
            p = qu.front();
            qu.pop();
            q = qu.front();
            qu.pop();
            if (p == NULL && q == NULL)
                continue;
            if (p == NULL && q != NULL ||
                    p != NULL && q == NULL ||
                    p->val != q->val)
                return false;
            qu.push(p->left);
            qu.push(q->right);
            qu.push(p->right);
            qu.push(q->left);
        }

        return true;
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
    bool helper(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;

        if ((left == NULL && right != NULL) ||
                (left != NULL && right == NULL))
            return false;

        if (left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left))
            return true;

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return helper(root->left, root->right);
    }
};
