


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
    /* 快速定位元素在inorder中的坐标 */
    unordered_map<int, int> tbl;

    /* 递归构建子树 */
    TreeNode *dfs(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2) {
        if (l2 > r2)
            return NULL;

        int index = tbl[preorder[l1]];
        TreeNode *root = new TreeNode(preorder[l1]);
        root->left = dfs(preorder, l1 + 1, index + l1 - l2, inorder, l2, index - 1);
        root->right = dfs(preorder, index + l1 - l2 + 1, r1, inorder, index + 1, r2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            tbl[inorder[i]] = i;
        /* 前序遍历地一个节点为根节点，根节点把inorder分割成左右字数，递归构建子树即可 */
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
