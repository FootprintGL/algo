

class Solution {
public:
    int countOdds(int low, int high) {
        /*
         * 找规律
         * 1. low, high都为奇数，2 + (high - low) / 2 - 1
         * 2. low, high都为偶数，2 + (high - 1 - (low + 1)) / 2 - 1 - 头尾偶数去掉转化为情况1
         * 3. 一奇一偶，2 + (high - 1 - low) / 2 - 1 - 去掉一个偶数转化为情况1
         */
        if (low == high)
            return low % 2 ? 1 : 0;

        if (low + 1 == high)
            return 1;

        if (low % 2 && high % 2)
            return 2 + (high - low) / 2 - 1;

        if (low % 2 || high % 2)
            return 2 + (high - low - 1) / 2 - 1;

        return 2 + (high - low - 2) / 2 - 1;
    }
};
