

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
    unordered_map<int, int> tbl;

    /*
     * 前序遍历第一个节点为根节点
     * 根节点把中序遍历结果分割成左右子树
     * 递归构建左右子树
     */
    TreeNode *dfs(vector<int> &inorder, int l1, int r1, vector<int> &preorder, int l2, int r2) {
        //cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        if (l1 > r1)
            return NULL;

        int index = tbl[preorder[l2]];
        TreeNode *root = new TreeNode(preorder[l2]);
        root->left = dfs(inorder, l1, index - 1, preorder, l2 + 1, index + l2 - l1);
        root->right = dfs(inorder, index + 1, r1, preorder, index + l2 - l1 + 1, r2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /* 哈希表加快根节点位置坐标查询 */
        for (int i = 0; i < inorder.size(); i++)
            tbl[inorder[i]] = i;

        return dfs(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
    }
};
