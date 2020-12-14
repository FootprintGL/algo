


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
    /* 统计每个数字个数 */
    int freq[10] = {0};
    /* 伪回文个数 */
    int res;
    /* 数字为奇数的个数 */
    int oddcnt;

    void dfs(TreeNode *root) {
        /* 更新计数 */
        freq[root->val]++;
        if (freq[root->val] % 2)
            oddcnt++;
        else
            oddcnt--;
        //cout << root->val << " " << freq[root->val] << " " << oddcnt << endl;

        if (root->left == nullptr && root->right == nullptr) {
            if (oddcnt < 2)
            /* 小于2个是伪回文 */
                res++;
            //return;
        }

        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
        /* 更新计数 */
        freq[root->val]--;
        if (freq[root->val] % 2)
            oddcnt++;
        else
            oddcnt--;
        //cout << root->val << " - " << freq[root->val] << " " << oddcnt << " " << res << endl;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        /* 根到叶子节点路径每个数字的个数是奇数个的数字小于2个 */
        if (root == nullptr)
            return 0;

        res = oddcnt = 0;
        dfs(root);
        return res;
    }
};
