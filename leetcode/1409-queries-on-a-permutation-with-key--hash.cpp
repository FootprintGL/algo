




class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> nums(m);
        int n = queries.size();
        vector<int> res(n);
        /* 存放数字到下标的映射 */
        unordered_map<int, int> tbl;

        for (int i = 0; i < m; i++) {
            nums[i] = i + 1;
            tbl[i + 1] = i;
        }

        for (int i = 0; i < n; i++) {
            int val = queries[i];
            res[i] = tbl[val];
            for (auto &[num, idx] : tbl)
            /* 前面的数坐标右移 */
                if (idx < tbl[val])
                    idx++;
            /* 当前数坐标置0 */
            tbl[val] = 0;
        }

        return res;
    }
};
