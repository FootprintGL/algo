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
    int val = 100;
public:
    bool isUnivalTree(TreeNode* root) {
        bool ans = true;

        if (!root)
            return true;

        /* 节点数据：0～99，100表示递归首次调用，保存单值树节点值 */
        if (val == 100)
            val = root->val;

        /* 判断节点值是否相同 */
        if (val != root->val) {
            return false;
        }

        /* 处理左子树 */
        if (root->left) {
            ans = isUnivalTree(root->left);
            if (!ans)
                /* 左子树非单值树 */
                return ans;
        }
        /* 处理右子树 */
        if (root->right) {
            ans = isUnivalTree(root->right);
            return ans;
        }

        return true;
    }
};

