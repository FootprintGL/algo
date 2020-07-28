



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
    vector<TreeNode*> helper(int i, int j) {
        vector<TreeNode *> res;
        if (i > j) {
            //1. res.push_back(NULL);
            //return res;
	    //2. return {NULL};
	    //return {nullptr};
	    return {nullptr};
        }

        /* 以不同节点为根节点递归构建左右子树，组合拼接到根节点构成子树 */
        for (int k = i; k <= j; k++) {
            vector<TreeNode *> lefttree = helper(i, k - 1);
            vector<TreeNode *> righttree = helper(k + 1, j);
            for (auto left : lefttree) {
                for (auto right : righttree) {
                    TreeNode *root = new TreeNode(k);
                    root->left = left;
                    root->right = right;
                    res.emplace_back(root);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return helper(1, n);
    }
};
