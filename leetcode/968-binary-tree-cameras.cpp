

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
        if (root == NULL)
            return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 2 && right == 2)
            return 0;

        if (left == 0 || right == 0) {
            res++;
            return 1;
        }

        if (left == 1 || right == 1)
            return 2;

        /* 不会走到这里 */
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        /*
         * 动态规划
         * 0 - 该节点没有覆盖
         * 1 - 该节点安装摄像头
         * 2 - 该节点有覆盖
         */
        res = 0;
        if (root == NULL)
            return 0;

        if (dfs(root) == 0)
            res++;

        return res;
    }
};
