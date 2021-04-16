

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        /*
         * 两行通过翻转相同则两行完全相同，或两行相同位置异或为1，如010 和 101
         * a ^ b = c, c全1，第一位0代表a，第一位1代表b，归一操作如下
         * 如果第一位是0的话，直接做key放入哈希表
         * 如果第一位是1的话，和全1异或后做key放入哈希表
         * 遍历哈希表，取最大的value
         */
        unordered_map<string, int> tbl;

        /* 异或运算归一 */
        for (auto &r : matrix) {
            string tmp;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (r[0] == 0) {
                    tmp += r[j] + '0';
                } else {
                    tmp += (r[j] ^ 1) + '0';
                }
            }
            tbl[tmp]++;
        }

        /* 找最大的cnt */
        int res = 0;
        for (auto &[key, cnt] : tbl)
            if (cnt > res)
                res = cnt;

        return res;
    }
};
