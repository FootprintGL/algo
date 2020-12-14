

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
    vector<int> res;

    void dump(vector<int> &l) {
        for (auto &t : l)
            cout << t << " ";
        cout << endl;
    }

    void inorder(TreeNode *root, vector<int> &l) {
        /* 中序遍历 */
        if (root == NULL)
            return;
        inorder(root->left, l);
        l.push_back(root->val);
        inorder(root->right, l);
    }

    /* 归并排序 - l1,l2本身已有序 */
    void mergesort(vector<int> &l1, vector<int> &l2) {
        int n1 = l1.size();
        int n2 = l2.size();
        int i1 = 0, i2 = 0;
/*
        cout << n1 << " " << n2 << endl;
        dump(l1);
        dump(l2);
*/
        while (i1 < n1 || i2 < n2) {
            if (i1 == n1) {
                res.push_back(l2[i2++]);
            } else if (i2 == n2) {
                res.push_back(l1[i1++]);
            } else {
                if (l1[i1] < l2[i2]) {
                    res.push_back(l1[i1++]);
                } else {
                    res.push_back(l2[i2++]);
                }
            }
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        /* 中序遍历 + 归并排序 */
        vector<int> l1;
        vector<int> l2;

        /* 中序遍历二叉搜索树 - 有序 */
        inorder(root1, l1);
        inorder(root2, l2);
        /* 归并排序 */
        mergesort(l1, l2);

        return res;
    }
};
