

class Solution {
public:
    bool isprime(int x) {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }

    int countPrimes(int n) {
        if (n < 3)
            return 0;

        int cnt = 0;
        for (int i = 2; i < n; i++)
            if (isprime(i)) {
                //cout << i << endl;
                cnt++;
            }
        return cnt;
    }
};

/* 超出时间限制 - 499979 */
class Solution {
public:
    bool isprime(int x) {
        for (int i = 2; i <= x / 2; i++)
            if (x % i == 0)
                return false;
        return true;
    }

    int countPrimes(int n) {
        if (n < 3)
            return 0;

        int cnt = 0;
        for (int i = 2; i < n; i++)
            if (isprime(i)) {
                //cout << i << endl;
                cnt++;
            }
        return cnt;
    }
};
