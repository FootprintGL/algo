

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
         * s1 = [l1, r1], s2 = [l2, r2]
         * 1. r1 < l2 -> s1在s2的左侧
         * 2. r2 < l1 -> s1在s2的右侧
         * 3. 相交，合并区间为[min(l1, l2), max(r1, r2)]
         * 找出所有区间s重叠的区间集合X', 和s合并成一个大区间
         * 结果为不和s重叠的区间以及合并后的打区间
         */
        vector<vector<int>> res;
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;

        for (auto & interval : intervals) {
            if (interval[0] > right) {
                /* interval不相交且在右边 */
                if (!placed) {
                    res.push_back({left, right});
                    placed = true;
                }
                res.push_back(interval);
            } else if (interval[1] < left) {
                /* interval不相交且在左边 */
                res.push_back(interval);
            } else {
                /* 相交 - 合并 */
                left = min(interval[0], left);
                right = max(interval[1], right);
            }
        }

        if (!placed)
        /* 所有区间都在newInterval的左边，newInterval单独放入 */
            res.push_back({left, right});

        return res;
    }
};
