class Solution {
public:
    void dfs(vector<string> &res, string &path, int n, int l, int r) {
        if (path.size() == n * 2) {
            /* 放置完毕，保存结果 */
            res.push_back(path);
            return;
        }

        if (l > r) {
            if (l < n) {
                /* 既可以放‘(‘,也可以放')' */
                path.push_back('(');
                dfs(res, path, n, l + 1, r);
                path.pop_back();
                path.push_back(')');
                dfs(res, path, n, l, r + 1);
                path.pop_back();
            } else {
                /* '('已放完，只能放')' */
                path.push_back(')');
                dfs(res, path, n, l, r + 1);
                path.pop_back();
            }
        } else {
            /* 只能放'(' */
            path.push_back('(');
            dfs(res, path, n, l + 1, r);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;

        /*
         * 回溯算法
         * 有效括号必须以'('开始，l为已放置'('的数量，r为已放置的')'的数量
         *     1. l > r时既可以放'('和')'
         *     2. l <= r时只能放'('
         *     3. 如果'('放完n个，则只能放')'
         * 如果放了2n个括号，找到一个有效组合，保存结果，递归结束
         * 注意放完一个括号处理结束后，需要移除放的括号来恢复现场 - 这也是回溯算法的基础所在
         */
        dfs(res, path, n, 0, 0);

        return res;
    }
};
