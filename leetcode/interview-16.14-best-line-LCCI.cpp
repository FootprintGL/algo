

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        vector<int> res(2, 0);
        int i, j, k, n = points.size();
        /* long long防止溢出 */
        long long x1, y1, x2, y2;
        int maxn = 0, num;

        /* 先确定2个点，在遍历后面的点看是否在一条直线 */
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                num = 2;
                if (n - j + 1 <= maxn)
                /* 剩下点数小于maxn，退出循环 */
                    break;
                x1 = points[j][0] - points[i][0];
                y1 = points[j][1] - points[i][1];
                for (k = j + 1; k < n; k++) {
                    x2 = points[k][0] - points[i][0];
                    y2 = points[k][1] - points[i][1];
                    if (x1 * y2 == x2 * y1)
                    /* 斜率相同点数加1 */
                        num++;
                }
                /* 更新最大值和结果 */
                if (num > maxn) {
                    maxn = num;
                    res[0] = i;
                    res[1] = j;
                }
            }
        }

        return res;
    }
};
