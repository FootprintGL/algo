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
    int longestZigZag(TreeNode* root) {
        /*
         * BFS
         * f(u) - 从根到u节点的路径上，以u结尾并且u是它父亲的左儿子的最长交错路径
         * f(u) - 从根到u节点的路径上，以u结尾并且u是他父亲的右儿子的最长交错路径
         * u的父节点为father[u], 则有
         * f(u) = g(father[u]) + 1, u为左儿子
         * g(u) = f(father[u]) + 1, u为右儿子
         * 用unordered_map<TreeNode *, int>f, g记录节点到函数值的映射
         * 用qu<u, father>记录u和父亲节点
         * 边计算边更新最长交错路径长度
         */
        queue<pair<TreeNode *, TreeNode *>> qu;
        unordered_map<TreeNode *, int> f, g;
        pair<TreeNode *, TreeNode *> cur;
        TreeNode *u, *father;
        int ans = 0;

        if (root == nullptr)
            return 0;

        qu.push({root, nullptr});
        while (!qu.empty()) {
            cur = qu.front();
            qu.pop();
            u = cur.first;
            father = cur.second;
            f[u] = g[u] = 0;
            if (father) {
                if (u == father->left)
                    f[u] = g[father] + 1;
                else
                    g[u] = f[father] + 1;
                ans = max(max(ans, f[u]), g[u]);
            }
            if (u->left)
                qu.push({u->left, u});
            if (u->right)
                qu.push({u->right, u});
        }
/*
        for (auto &p : f)
            cout << p.first << " " << p.second << endl;
        cout << endl << endl;

        for (auto &p : g)
            cout << p.first << " " << p.second << endl;
        cout << endl << endl;
*/
        return ans;
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
    int ans;

    void dfs(TreeNode *root, bool moveleft, int len) {
        //cout << root << " " << moveleft << " " << len << endl;
        ans = max(ans, len);
        if (moveleft) {
            if (root->left)
                /* 能往左走就往左走，交错路径+1 */
                dfs(root->left, !moveleft, len + 1);
            if (root->right)
                /* 不能往左就往右走，交错路径重置为1 */
                dfs(root->right, moveleft, 1);
        } else {
            if (root->right)
                /* 能往右走就往右走，交错路径+1 */
                dfs(root->right, !moveleft, len + 1);
            if (root->left)
                /* 不能往右走就往左走，交错路径重置为1 */
                dfs(root->left, moveleft, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        ans = 0;
        if (root == nullptr)
            return 0;
        dfs(root, true, 0);
        dfs(root, false, 0);
        return ans;
    }
};
