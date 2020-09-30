

class Solution {
public:
    int commondivisor(int m, int n) {
        /*
        * 等值算法 - 九章算术
        * 1. 如果为偶数，用2约减
        * 2. 用较大的数，减较小的数
        * 3. 重复第二步，只到所得的简述和差相等为止
        */
        int factor = 1;
        while (m % 2 == 0 && n % 2 == 0) {
            factor *= 2;
            m /= 2;
            n /= 2;
        }

        while (m != n) {
            if (m > n)
                m = m - n;
            else if (m < n)
                n = n - m;
        }

        return m * factor;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> tbl;

        /* 所有元素出现频次的最大公约数大于等于2 */
        if (deck.size() < 2)
            return false;

        for (auto d : deck)
            tbl[d]++;

        int comm = -1;
        for (auto [c, cnt] : tbl) {
            if (comm != -1) {
                comm = commondivisor(comm, cnt);
            } else {
                comm = cnt;
            }
        }

        return comm >= 2;
    }
};
