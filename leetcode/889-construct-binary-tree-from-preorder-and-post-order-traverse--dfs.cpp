

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
    TreeNode *dfs(vector<int> &pre, int l1, int r1, vector<int> &post, int l2, int r2) {
        //cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        if (l1 > r1)
            return NULL;

        TreeNode *root = new TreeNode(pre[l1]);
        if (l1 == r1)
        /* 只有一个元素 */
            return root;

        int i;
        /* 在post中搜索pre[l + 1]的位置，划分左右子树 */
        for (i = l2; i < r2; i++)
            if (post[i] == pre[l1 + 1])
                break;

        root->left = dfs(pre, l1 + 1, l1 + i - l2 + 1, post, l2, i);
        root->right = dfs(pre, l1 + i - l2 + 2, r1, post, i + 1, r2 - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        /*
         * pre[start] - 根节点
         * pre[start + 1] - 左子树根节点
         * 寻找pre[start + 1]在post中的位置index，即可划分左右指数
         * 左子树post[start - index], 右子树post[index + 1, n - 2]
         */
        int n = pre.size();
        return dfs(pre, 0, n - 1, post, 0, n - 1);
    }
};
