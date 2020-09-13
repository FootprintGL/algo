

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
    /* 删除子树的所有节点 */
    void deletetree(TreeNode *root) {
        if (root == NULL)
            return ;
        deletetree(root->left);
        deletetree(root->right);
        delete(root);
    }

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return NULL;

        //cout << root << " " << root->val << endl;
        if (root->val < L) {
            //cout << "left" << endl;
            /* 根节点和左子树需要全部删除 */
            deletetree(root->left);
            root->left = NULL;
            TreeNode *tmp = root;
            root = trimBST(root->right, L, R);
            //cout << tmp << " " << root << endl;
            tmp->right = NULL;
            /* 本地执行成功，但提交失败，可能测试程序会重复使用该地址 */
            //delete(tmp);
            //cout << "del" << tmp << endl;
        } else if (root->val > R) {
            //cout << "right" << endl;
            /* 根节点和右子树需要全部删除 */
            deletetree(root->right);
            root->right = NULL;
            TreeNode *tmp = root;
            root = trimBST(root->left, L, R);
            /* 本地执行成功，但提交失败，可能测试程序会重复使用该地址 */
            //delete(tmp);
            //cout << "del" << tmp << endl;
        } else {
            //cout << "normal" << root << endl;
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }

        //cout << root << " " << root->left << " " << root->right << " " << "1" << endl << endl;
        return root;
    }
};
