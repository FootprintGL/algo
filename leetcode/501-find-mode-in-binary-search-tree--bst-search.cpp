

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
        int cnt;
        int maxnum;
        int prev;

        /* 二叉搜索树中序遍历有序 */
        void dfs(TreeNode *root) {
            //cout << root << " " << prev << " " << cnt << " " << maxnum << " " << res.size() << endl;
            if (root == NULL)
                return;

            dfs(root->left);
            if (root->val == prev) {
                cnt++;
            } else {
                cnt = 1;
                prev = root->val;
            }
            if (cnt == maxnum) {
                res.push_back(root->val);
            } else if (cnt > maxnum) {
                res.clear();
                maxnum = cnt;
                res.push_back(root->val);
            }
            dfs(root->right);
        }

        vector<int> findMode(TreeNode* root) {
            cnt = 0;
            maxnum = 0;
            prev = INT_MAX;
            dfs(root);

            return res;
        }
    };
