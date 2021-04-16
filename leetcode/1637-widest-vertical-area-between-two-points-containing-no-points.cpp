

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        /* 先按横坐标x排序，再求最大间隔 */
        int res = 0;

        /* 排序 */
        sort(points.begin(), points.end());

        /* 求最大间隔 */
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] - points[i - 1][0] > res)
                res = points[i][0] - points[i - 1][0];
        }

        return res;
    }
};
