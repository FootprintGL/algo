

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
    int res;

    int dfs(TreeNode *root) {
        /*
         * 如果叶子节点有0个金币，需要从父节点移动一个记为-1，过载量
         * 如果叶子节点有3个金币，需要移动2个到父节点记为2，过载量
         * 如果子树的金币数大于节点数，需要把硬币移到父节点
         * 如果字数的金币数小于节点数，需要从父节点移动到子树
         * dfs(node)为所在子树需要移入/移出的数量，即金币数量 - 节点数量
         * 则该节点与字节点需要移动的金币数量为|dfs(node->left)| + |dfs(node->right)|
         * 这个节点的过载量为node.val + dfs(node->left) + dfs(node->right) - 1
         */
        if (root == nullptr)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);
        res += abs(l) + abs(r);

        return root->val + l + r - 1;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};
