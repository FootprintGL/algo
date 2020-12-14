

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
    int countlevel(TreeNode *root) {
        int cnt = 0;
        TreeNode *cur = root;
        while (cur) {
            /* 完全二叉树节点集中在左边，往做搜索即可 */
            cur = cur->left;
            cnt++;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        /*
         * 如果是满二叉树，总结点数为2 ^ h - 1, h为层数
         * 对左右子树的高度进行统计，分别记为left, right
         *      1 如果left == right, 左子树一定是满二叉树，左子树节点个数为2 ^ left - 1
         *        加上根节点正好是2 ^ left, 再对右子树进行递归统计
         *      2 如果left != right, 最后一层没满，倒数第二层满了，可以直接得到右子树的节点个数2 ^ right
         *        再对左子树进行递归统计
         */
        if (root == NULL)
            return 0;

        int left = countlevel(root->left);
        int right = countlevel(root->right);

        if (left == right) {
            return countNodes(root->right) + (1 << left);
        } else {
            return countNodes(root->left) + (1 << right);
        }
    }
};
