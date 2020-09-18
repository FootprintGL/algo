

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> tbl;
        vector<int> res;
        int i, j, cnt = 0;
        /* 计算和保存每行1的个数和行号 */
        for (i = 0; i < m; i++) {
            cnt = 0;
            for (j = 0; j < n; j++) {
                if (mat[i][j])
                    cnt++;
                else
                    break;
            }
            tbl.push_back(make_pair(i, cnt));
        }

        /* 排序 */
        sort(tbl.begin(), tbl.end(), comp);

        /* 取前k个 */
        for (i = 0; i < m && k > 0; i++) {
            res.push_back(tbl[i].first);
            k--;
        }

        return res;
    }
};
