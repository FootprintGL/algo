
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        /* 实际是求ops中行列坐标的最小值 */
        int minrow = m + 1, mincol = n + 1;

        for (int i = 0; i < ops.size(); i++) {
            minrow = min(minrow, ops[i][0]);
            mincol = min(mincol, ops[i][1]);
        }

        return minrow == m + 1 ? m * n : minrow * mincol;
    }
};
