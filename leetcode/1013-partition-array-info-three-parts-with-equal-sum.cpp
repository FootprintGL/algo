

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        int total = 0, sum = 0;
        int div, cnt = 0;
        int i;

        for (i = 0; i < len; i++)
            total += A[i];
        if (total % 3)
            return false;

        div = total / 3;
        /*
         * 3段和分别为总和的1/3，只要能找到前2段和为div，剩下一段和必为div
         * 如果cnt大于3，说明和为0，多个子数组和为0，可以任意拼接
         */
        for (i = 0; i < len; i++) {
            sum += A[i];
            if (sum == div) {
                cnt++;
                sum = 0;
            }
        }

        return cnt >= 3;
    }
};


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        vector<int> sum(len + 1, 0);
        int div, start, cnt = 0;
        int i, j;

        /* 前缀和 */
        for (i = 0; i < len; i++)
            sum[i + 1] = sum[i] + A[i];

        if (sum[len] % 3)
            return false;
        div = sum[len] / 3;
        start = 0;
        /* 3段和分别为总和的1/3 */
        for (i = 1; i < len; i++) {
            if (sum[i] - sum[start] == div) {
                start = i;
                cnt++;
                if (cnt == 2 && sum[len] - sum[start] == div)
                    return true;
            }
        }

        return false;
    }
};

/* 暴力循环 - 超出时间限制 */
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int len = A.size();
        vector<int> sum(len + 1, 0);
        int i, j;

        /* 前缀和 */
        for (i = 0; i < len; i++)
            sum[i + 1] = sum[i] + A[i];
        /* 暴力循环 - 超时 */
        for (i = 1; i < len - 1; i++) {
            for (j = i + 1; j < len; j++) {
                if ((sum[i] - sum[0] == sum[j] - sum[i]) && (sum[j] - sum[i] == sum[len] - sum[j]))
                    return true;
            }
        }

        return false;
    }
};
