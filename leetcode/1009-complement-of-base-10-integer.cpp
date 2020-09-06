

class Solution {
public:
    int bitwiseComplement(int N) {
        /* 反码为N ^ (11..11), 题目转换为球N有几个有效位 */
        if (N == 0)
            return 1;

        int cnt = 0;
        int tmp = N;

        while (tmp) {
            tmp >>= 1;
            cnt++;
        }

        /* 减法的优先级比移位高 */
        return (N ^ ((1 << cnt) - 1));
    }
};
