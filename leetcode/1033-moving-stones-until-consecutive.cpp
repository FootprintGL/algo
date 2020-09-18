

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans(2, 0);

        /*
         * 1. 先排序
         * 2. 最大次数 - max - min - 2
         * 3. 最小次数
         *      a. 已经连续，0
         *      b. 两数之差为1或2，1
         *      c. 其他情况，2
         */
        int x = min(a, min(b, c));
        int z = max(a, max(b, c));
        int y = a + b + c - x - z;

        ans[1] = z - x - 2;
        if (x + 1 == y && y + 1 == z) {
            ans[0] = 0;
        } else if (y - x <= 2 || z - y <= 2) {
            ans[0] = 1;
        } else {
            ans[0] = 2;
        }

        return ans;
    }
};
