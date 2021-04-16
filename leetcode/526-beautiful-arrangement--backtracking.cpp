

class Solution {
public:
    int res;

    void dfs(int start, int n, vector<bool> &vis) {
        if (start == n + 1) {
            /* 找到一个优美排列 */
            res++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i])
            /* 已经使用过 */
                continue;

            if ((start % i) && (i % start))
            /* 2个条件都不满足 */
                continue;

            vis[i] = true;
            dfs(start + 1, n, vis);
            /* 回溯 */
            vis[i] = false;
        }
    }

    int countArrangement(int n) {
        res = 0;
        vector<bool> vis(n + 1, false);
        dfs(1, n, vis);
        return res;
    }
};

class Solution {
public:
    int res;
    unordered_set<int> vis;

    void dfs(int start, int n) {
        if (start == n + 1) {
            /* 找到一个优美排列 */
            res++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (vis.count(i))
            /* 已经使用过 */
                continue;

            if ((start % i) && (i % start))
            /* 2个条件都不满足 */
                continue;

            vis.insert(i);
            dfs(start + 1, n);
            /* 回溯 */
            vis.erase(i);
        }
    }

    int countArrangement(int n) {
        res = 0;
        dfs(1, n);
        return res;
    }
};
