

class Solution {
public:
    int primePalindrome(int N) {
        /*
         * 6步进素数判别法
         * 大于6的素数一定分布在6的倍数附近6x, 6x+1, 6x+2, 6x+3, 6x+4, 6x+5
         * 6x/6x+2/6x+3/6x+4肯定不是素数，素数只能表示成6x+1/6x+5
         * 当数字大于11的数数字个数为偶数的回文数都不是素数，11必为其质因子
         */
        int check[] = {2, 2, 2, 3, 5, 5, 7, 7, 11, 11, 11, 11};
        if (N <= 11)
            return check[N];

        while (1) {
            int mod = N % 6;
            string cs = to_string(N);

            /* 跳过偶数长度区间 */
            if (cs.length() % 2 == 0) {
                N = pow(10, cs.length()) + 1;
                continue;
            }

            if (mod == 1 || mod == 5) {
                bool isprime = true;
                bool ispalindrome = true;

                /* 检查素数 */
                for (int i = 5; i <= sqrt(N); i += 6) {
                    /* 6x+1/6x+5可能为质数 */
                    if (N % i == 0 || N % (i + 2) == 0) {
                        isprime = false;
                        break;
                    }
                }

                /* 检查回文数字 */
                if (isprime) {
                    for (int j = 0; j <= cs.length() / 2; j++) {
                        if (cs[j] != cs[cs.length() - 1 - j]) {
                            ispalindrome = false;
                            break;
                        }
                    }
                }

                if (ispalindrome && isprime)
                /* 找到结果 */
                    return N;

                /* 下一个可能的数为6x+1/6x+5 */
                N = mod == 1 ? N + 4 : N + 2;
            } else {
                /* 下一个可能的数为6x+1/6x+5 */
                N = mod == 0 ? N + 1 : N + (5 - mod);
            }
        }
    }
};
