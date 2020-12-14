
class Solution {
public:
    /*
     * 汉明距离是两个数字的二进制数对应位不同的数量
     * 可以逐位考虑 - 假设第i位有k个1，则有n - k个0，汉明距离为k * (n - k)
     * 把所有位的汉明距离求和就是结果
     */
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        /* 保存每一位上1的个数 */
        int n = nums.size(), i;
        int cnt[32] = {0};

        /* 统计每位上1的个数 */
        for (auto &num : nums) {
            i = 0;
            while (num) {
                if (num & 1)
                    cnt[i]++;
                num >>= 1;
                i++;
            }
        }

        /* 计算并统计汉明距离 */
        for (i = 0; i < 32; i++) {
            res += cnt[i] * (n - cnt[i]);
        }

        return res;
    }
};


/* 暴力 - 超时*/
class Solution {
public:
    /* 统计n中1的个数 */
    int cntone(int n) {
        int cnt = 0;

        while (n) {
            cnt++;
            n &= n - 1;
        }

        return cnt;
    }

    int totalHammingDistance(vector<int>& nums) {
        /* 异或运算之后1的个数为汉明距离 */
        int n = nums.size();
        int i, j, res = 0;

        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                res += cntone(nums[i] ^ nums[j]);
            }
        }

        return res;
    }
};
