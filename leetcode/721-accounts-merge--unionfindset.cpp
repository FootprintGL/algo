

class Solution {
    /* 记录每个人们的父辈id号 */
    vector<int> f;
    /* 保存已经出现过的邮箱 */
    unordered_set<string> isappeared;
    /* 记录每个邮箱的父辈是谁 */
    unordered_map<string, int> father;
public:
    int find(int x) {
        return x == f[x] ? x : find(f[x]);
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
            f[rooty] = rootx;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        /*
         * 并查集
         * 邮箱相同的账户需要合并
         */
        int n = accounts.size();

        /* 初始化 */
        f = vector<int>(n);
        for (int i = 0; i < n; i++)
            f[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (isappeared.count(accounts[i][j])) {
                    /* 邮箱已经出现过，合并 */
                    merge(father[accounts[i][j]], i);
                } else {
                    /* 邮箱第一次出现，加入isappeared, 记录第一次出现该邮箱的人名的位置 */
                    isappeared.insert(accounts[i][j]);
                    father[accounts[i][j]] = i;
                }
            }
        }

        /*
         * 遍历accouts中每个人名，寻找每个人名的父辈，并将该人名下所有邮箱保存在一起
         * 存在重复邮箱，且要保持顺序，用set<string>存储自动排序
         */
        unordered_map<int, set<string>> accmail;
        for (int i = 0; i < n; i++) {
            int t = find(i);
            //cout << t << endl;
            for (int j = 1; j < accounts[i].size(); j++) {
                accmail[t].insert(accounts[i][j]);
            }
        }

        /* 遍历accmail，每一项为<人名位置，名下邮箱>，构建结果并返回 */
        vector<vector<string>> res;
        for (auto &acc : accmail) {
            vector<string> ans;
            ans.push_back(accounts[acc.first][0]);
            for (auto &mail : acc.second)
                ans.push_back(mail);
            res.push_back(ans);
        }

        return res;
    }
};
