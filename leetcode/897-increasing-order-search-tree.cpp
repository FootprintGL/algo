
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *pre = new TreeNode(0);
        TreeNode *ans = pre, *cur;
        stack<TreeNode *> stk;
        
        if (root == NULL)
            return root;

        /* 迭代中序遍历 - pre记录前一个访问的节点 */
        cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            pre->right = cur;
            cur->left = NULL;
            pre = cur;
            cur = cur->right;
        }

        return ans->right;
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
    TreeNode *pre;
    void inorder(TreeNode *root) {
        if (root == NULL)
            return;

        inorder(root->left);
        root->left = NULL;
        pre->right = root;
        pre = root;
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        /* 递归 */
        TreeNode *ans = new TreeNode(0);
        pre = ans;
        inorder(root);
        return ans->right;
    }
};
