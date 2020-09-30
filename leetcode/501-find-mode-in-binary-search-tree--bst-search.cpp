

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
    int prev;
    int count;
    int maxcnt;

    /* 中序遍历 */
    void inorder(TreeNode *root) {
        //cout << root << " " << prev << " " << count << " " << maxcnt << " " << res.size() << endl;
        if (root == NULL)
            return;

        inorder(root->left);
        if (count == 0) {
            prev = root->val;
            count = 1;
        } else {
            if (root->val == prev) {
                count++;
            } else {
                prev = root->val;
                count = 1;
            }
        }
        if (count == maxcnt) {
            res.push_back(prev);
        } else if (count > maxcnt) {
            res.clear();
            res.push_back(prev);
            maxcnt = count;
        }
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        maxcnt = 0;
        prev = INT_MIN;
        count = 0;

        inorder(root);

        return res;
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




/* 错误解法 - 只在不相等时更新是不对的，最后一组数据没有统计 */
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
    int prev;
    int count;
    int maxcnt;

    /* 中序遍历 */
    void inorder(TreeNode *root) {
        cout << root << " " << prev << " " << count << " " << maxcnt << " " << res.size() << endl;
        if (root == NULL)
            return;

        inorder(root->left);
        if (count == 0) {
            prev = root->val;
            count = 1;
        } else {
            if (root->val == prev) {
                count++;
            } else {
                if (count == maxcnt) {
                    res.push_back(prev);
                } else if (count > maxcnt) {
                    res.clear();
                    res.push_back(prev);
                    maxcnt = count;
                    prev = root->val;
                    count = 1;
                }
            }
        }
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        maxcnt = 0;
        prev = INT_MIN;
        count = 0;

        inorder(root);

        return res;
    }
};
