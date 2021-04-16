

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
    /* 计算树的高度 */
    int calcheight(TreeNode *root) {
        if (root == NULL)
            return 0;

        return 1 + max(calcheight(root->left), calcheight(root->right));
    }

    void fill(TreeNode *root, vector<vector<string>> &res, int i, int l, int r) {
        if (root == NULL)
            return;

        int m = l + (r - l) / 2;

        res[i][m] = to_string(root->val);
        fill(root->left, res, i + 1, l, m);
        fill(root->right, res, i + 1, m + 1, r);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        /*
         * 递归
         * 创建一个长度为height * (2 ^ height - 1)的二维数组，height为树的高度
         * 先用““填充，然后递归调用fill(res, root, i, l, r)将节点的值输出到res
         * i表示当前节点所在的层数，l, r为当前子树在res中的左右边界，当前节点被输出
         * 到第i行的第l和第r列中间位置上
         */
        int height = calcheight(root);

        vector<vector<string>> res(height, vector<string>(((1 << height) - 1), ""));
        fill(root, res, 0, 0, res[0].size());

        return res;
    }
};
