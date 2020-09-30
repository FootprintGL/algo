
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
    /* 中序遍历，求相邻元素差值绝对值最小值 */
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        stack<TreeNode *> stk;
        TreeNode *cur, *prev = NULL;

        cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (prev)
                ans = min(ans, cur->val - prev->val);
            prev = cur;
            cur = cur->right;
        }

        return ans;
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
    int ans;
    int prev;

    /* 中序遍历，求相邻元素差值绝对值最小值 */
    void inroder(TreeNode *root) {
        if (root == NULL)
            return;

        inroder(root->left);

        if (prev != -1)
            ans = min(ans, root->val - prev);
        prev = root->val;

        inroder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        prev = -1;
        inroder(root);
        return ans;
    }
};
