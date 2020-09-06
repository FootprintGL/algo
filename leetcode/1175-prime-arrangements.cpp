
class Solution {
public:
    int M;
    bool isprime(int x) {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }

    int countprimes(int n) {
        if (n < 2)
            return 0;
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (isprime(i))
                cnt++;
        }

        return cnt;
    }

    long factorial(int n) {
        /* long防止整数溢出 */
        long ans = 1;
        for (int i = 2; i <= n; i++)
            ans = (ans * i) % M;
        return ans;
    }

    int numPrimeArrangements(int n) {
        /*
         * 素数的个数为k,合数的个数为n - k
         * 结果为k! * (n - k)!
         * 取模防止溢出
         */
        M = 1000000007;
        int k = countprimes(n);
        /* long防止整数溢出 */
        long ans = (factorial(k) * factorial(n - k)) % M;
        return ans;
    }
};
