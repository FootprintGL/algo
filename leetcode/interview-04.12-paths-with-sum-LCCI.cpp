

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
    /* 保存前缀和和路径数量 */
    unordered_map<int, int> tbl;
    /* 保存结果 */
    int res;

    void dfs(TreeNode *root, int currsum, int sum) {
        if (root == NULL)
            return;

        currsum += root->val;
        if (tbl.count(currsum - sum))
        /* 搜索到currsum - sum并累加结果 */
            res += tbl[currsum - sum];

        tbl[currsum]++;
        dfs(root->left, currsum, sum);
        dfs(root->right, currsum, sum);
        tbl[currsum]--;
    }

    int pathSum(TreeNode* root, int sum) {
        /*
         * 前缀和
         * 如果两个数的前缀总和是相同的，那么节点之间的元素和为0
         * 如果前缀和和cursum,在节点A和节点B处相差target，则位于节点A和节点B之间的元素之和为target
         */
        res = 0;
        int currsum = 0;
        tbl[0] = 1;
        dfs(root, currsum, sum);
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
    int res = 0;

    void dfs(TreeNode *root, int &cur, int sum) {
        if (root == NULL)
            return;
        cur += root->val;
        //cout << root << " " << root->val << " " << cur << " " << sum << endl;
        if (cur == sum)
            res++;
        dfs(root->left, cur, sum);
        dfs(root->right, cur, sum);
        cur -= root->val;
    }

    int pathSum(TreeNode* root, int sum) {
        int cur = 0;

        if (root == NULL)
            return res;

        dfs(root, cur, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);

        return res;
    }
};
