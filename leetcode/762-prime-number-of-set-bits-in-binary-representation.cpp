

class Solution {
public:
    /* 判断质数 */
    bool isprime(int n) {
        if (n == 1)
            return false;

        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    /* 统计bit1的个数 */
    int countone(int n) {
        int cnt = 0;
        while (n) {
            n &= n - 1;
            cnt++;
        }
        return cnt;
    }

    int countPrimeSetBits(int L, int R) {
        int cnt = 0;

        for (int i = L; i <= R; i++) {
            if (isprime(countone(i)))
                cnt++;
        }

        return cnt;
    }
};
