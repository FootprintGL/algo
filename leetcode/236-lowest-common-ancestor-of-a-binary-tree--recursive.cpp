
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
    /*
     * 可能返回NULL，p，q或公共祖先
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return root;
        
        if (root == p || root == q)
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
            return root;
        else if (left == NULL)
            return right;
        else if (right == NULL)
            return left;

        return NULL;
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
    /* 检查val是否在子树 */
    bool search(TreeNode *root, int val) {
        if (root == NULL)
            return false;
        if (val == root->val)
            return true;
        else
            return search(root->left, val) || search(root->right, val);
    }

    /*
     * 如果p，q分布在左右子树，则root即为最近公共祖先
     * 如果p，q分布在左子树，则必在左儿子为根节点的子树
     * 如果p，q分布在右子树，则必在右儿子为根节点的子树
     * 递归下探，直到找到最近公共祖先
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val == root->val || q->val == root->val)
            return root;

        bool pinleft = search(root->left, p->val);
        bool qinleft = search(root->left, q->val);
        /* 一个在左，一个在右 */
        if ((pinleft && !qinleft) || (!pinleft && qinleft))
            return root;

        if (pinleft && qinleft)
            /* 都在左子树 */
            return lowestCommonAncestor(root->left, p, q);
        else
            /* 都在右子树 */
            return lowestCommonAncestor(root->right, p, q);
    }
};
