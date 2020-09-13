
class Solution {
public:
    /* p1到p2的最小时间 */
    int mintime(vector<int> p1, vector<int> p2) {
        /* 对角线也是1秒，最小时间为x, y坐标delta较大的值 */
        int d1 = abs(p1[0] - p2[0]);
        int d2 = abs(p1[1] - p2[1]);

        return max(d1, d2);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        for (int i = 1; i < points.size(); i++) {
            ans += mintime(points[i - 1], points[i]);
        }

        return ans;
    }
};
