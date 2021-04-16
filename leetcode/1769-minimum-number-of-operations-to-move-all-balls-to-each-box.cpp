

class Solution {
public:
    vector<int> minOperations(string boxes) {
        /*
         * 一个球从i移到j，需要abs(i - j)步
         * 每个盒子i，每个球box j移动过去需要abs(i - j)步
         */
        int n = boxes.length();
        /* 统计有球的盒子位置 */
        vector<int> onepos;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
            if (boxes[i] == '1')
            /* 统计有球的盒子的坐标 */
                onepos.push_back(i);

        for (int i = 0; i < n; i++) {
            for (auto &t : onepos) {
                /* 一个一个球移到位置i */
                ans[i] += abs(t - i);
            }
        }

        return ans;
    }
};
