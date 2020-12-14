

/* 按第一个升序排列，如果第一个元素相同，按第二个升序 */
bool compare(vector<int> &v1, vector<int> &v2) {
    return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size(), i;

        if (n == 0)
            return res;

        /* 先做升序排序 */
        sort(intervals.begin(), intervals.end(), compare);

        vector<int> cur = intervals[0];
        for (i = 1; i < n; i++) {
            if (cur[1] >= intervals[i][0]) {
                /* 有重叠 - 合并 */
                cur[1] = max(intervals[i][1], cur[1]);
            } else {
                /* 没有重叠 */
                res.push_back(cur);
                cur = intervals[i];
            }
        }

        /* 放入最后一段 */
        res.push_back(cur);

        return res;
    }
};
