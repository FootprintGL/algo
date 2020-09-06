

class Solution {
public:
    /* 计算两点的距离 */
    int distance(vector<int> &x, vector<int> &y) {
        return (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        /* key是一个点到其他点的距离，value是距离想等点的个数 */
        unordered_map<int, int> map;
        int ans = 0;
        /* points为所有点的坐标 */
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j)
                    continue;
                int dis = distance(points[i], points[j]);
                map[dis]++;
            }
            /* 统计回旋镖数量 */
            for (auto &[dis, cnt] : map)
                ans += cnt * (cnt - 1);
            map.clear();
        }

        return ans;
    }
};
