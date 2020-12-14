

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
    int maxcnt;
    unordered_map<int, int> sumfreq;

    int dfs(TreeNode *root) {
        if (root == NULL)
            return 0;

        int res = root->val;
        res += dfs(root->left);
        res += dfs(root->right);
        sumfreq[res]++;
        if (sumfreq[res] > maxcnt)
            maxcnt = sumfreq[res];
        return res;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        maxcnt = 0;

        /* 哈希表统计sum出现次数，找出出现次数最多的元素 */
        dfs(root);
        for (auto &[sum, cnt] : sumfreq)
            if (cnt == maxcnt)
                res.push_back(sum);

        return res;
    }
};
