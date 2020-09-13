

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
    int ans;

    Solution() {
        ans = 0;
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr)
            return 0;
        
        rangeSumBST(root->left, L, R);
        if (root->val >= L && root->val <= R)
            ans += root->val;
        rangeSumBST(root->right, L, R);

        return ans;
    }
};



/* 错误解法 - 会重复累加 */
class Solution {
public:
    int ans;

    Solution() {
        ans = 0;
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr)
            return 0;

        cout << root->val << " " << ans << endl;

        if (root->val < L) {
            ans += rangeSumBST(root->right, L, R);
            cout << "1- " << ans << endl;
        } else if (root->val > R) {
            ans += rangeSumBST(root->left, L, R);
            cout << "2- " << ans << endl;
        } else {
            ans += rangeSumBST(root->left, L, R);
            cout << "3- left - " << ans << endl;
            ans += rangeSumBST(root->right, L, R);
            cout << "3- right - " << ans << endl;
            ans += root->val;
            cout << "3- " << ans << endl;
        }

        return ans;
    }
};
