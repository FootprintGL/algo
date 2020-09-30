

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

    TreeNode *dfs(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2) {
        if (l1 > r1)
            return NULL;

        int i = tbl[postorder[r2]];
        /* 构建根节点 */
        TreeNode *root = new TreeNode(postorder[r2]);

        /*
         * 构建左右子树
         * 找到postorder中左右子树的分界点
         * 左子树[l1, i + l2 - l1 - 1] - 共i - l1个节点
         * 右子树[i + l2 - l1, r2 - 1]
         */
        root->left = dfs(inorder, l1, i - 1, postorder, l2, i + l2 - l1 - 1);
        root->right = dfs(inorder, i + 1, r1, postorder, i + l2 - l1, r2 - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
         * 后序遍历最后一个元素为根节点
         * 根节点可以把中序遍历结果分割成左右子树
         * 递归构建左右子树
         */
        for (int i = 0; i < inorder.size(); i++)
            tbl[inorder[i]] = i;

        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

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
    TreeNode *dfs(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2) {
        if (l1 > r1)
            return NULL;

        int i;
        /* 找到inorder左右子树分界点 - 可以用哈希map优化 */
        for (i = l1; i <= r1; i++) {
            if (inorder[i] == postorder[r2])
                break;
        }
        /* 构建根节点 */
        TreeNode *root = new TreeNode(postorder[r2]);

        /*
         * 构建左右子树
         * 找到postorder中左右子树的分界点
         * 左子树[l1, i + l2 - l1 - 1] - 共i - l1个节点
         * 右子树[i + l2 - l1, r2 - 1]
         */
        root->left = dfs(inorder, l1, i - 1, postorder, l2, i + l2 - l1 - 1);
        root->right = dfs(inorder, i + 1, r1, postorder, i + l2 - l1, r2 - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
         * 后序遍历最后一个元素为根节点
         * 根节点可以把中序遍历结果分割成左右子树
         * 递归构建左右子树
         */
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    }
};
