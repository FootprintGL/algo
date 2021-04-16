


class Solution {
public:
    void dfs(vector<int> &res, int start, int n) {
        if (start > n)
            return;
        res.push_back(start);
        start *= 10;
        for (int i = 0; i < 10; i++) {
            dfs(res, start + i, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        /*
         * 先序遍历10叉树
         */
        vector<int> res;

        for (int i = 1; i < 10; i++)
            dfs(res, i, n);

        return res;
    }
};
