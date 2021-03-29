

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        /*
         * 按answers[i]分组放入哈希表
         *      1 answer[0] == 0, 每只兔子单独一个颜色
         *      2 (second / (first + 1) + second % (first + 1) ? 1 : 0) * first
         */
        int res = 0;
        unordered_map<int, int> group;

        /* 分组放入哈希表 */
        for (auto &t : answers) {
            group[t]++;
        }

        /* 统计结果 */
        for (auto [t, cnt] : group) {
            if (t == 0)
                res += cnt;
            else
                res += (cnt / (t + 1) + (cnt % (t + 1) ? 1 : 0)) * (t + 1);
        }

        return res;
    }
};
