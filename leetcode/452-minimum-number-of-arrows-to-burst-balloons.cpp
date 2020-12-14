


/* 排序比较函数 - 升序 */
bool compare(vector<int> &p1, vector<int> &p2) {
    return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
}

class Solution {
public:
    bool overlap(vector<int> &p1, vector<int> &p2) {
        /* p1在p2左边 */
        return p1[1] >= p2[0];
    }

    /* 合并两个相交的气球 */
    void merge(vector<int> &p1, vector<int> &p2) {
        p1[0] = max(p1[0], p2[0]);
        p1[1] = min(p1[1], p2[1]);
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        /*
         * 排序 + 贪心
         * 先对points从左向右按起始位置升序排列
         * 从左向右依次求交集合并，如果合并后和后面的气球不相交
         * 则需要一根新的箭
         */
        if (points.size() == 0)
            return 0;

        int cnt = 1, start = 0;
        sort(points.begin(), points.end(), compare);

        vector<int> cur = points[0];
        for (int i = 0; i < points.size(); i++) {
            if (overlap(cur, points[i])) {
                //cout << start << " " << i << endl;
                merge(cur, points[i]);
            } else {
                cur = points[i];
                cnt++;
            }
        }

        return cnt;
    }
};
