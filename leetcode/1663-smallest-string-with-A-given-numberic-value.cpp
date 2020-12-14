

class Solution {
public:
    string getSmallestString(int n, int k) {
        /*
         * 贪心
         * 从左往右依次尽量填入数值小的字符
         * 假设当前还剩下n'个位置，并且这些位置之和为k', 如果放入字母c
         * 剩下的n' - 1个位置以及k' - c的数值之和，必满足
         * n' - 1 <= k' - c <= 26 * (k' - 1) ==> k' - 26 * (n' - 1) <= c <= k' - (n' - 1)
         * c的取值下限为k' - 26 * (n' - 1)
         *      1 如果k' - 26 * (n' - 1) <= 0, 取a
         *      2 如果k' - 26 * (n' - 1) > 0, 取该数值对应的字符
         */
        string res;
        while (n >= 1) {
            int bound = k - 26 * (n - 1);
            if (bound <= 0) {
                res += 'a';
                k -= 1;
            } else {
                res += 'a' + bound - 1;
                k -= bound;
            }
            n--;
        }

        return res;
    }
};




class Solution {
public:
    string getSmallestString(int n, int k) {
        /* 贪心 - 从左往右依次尽量填入前面的字符 */
        string res;

        while (n >= 1) {
            if (26 * (n - 1) >= k) {
                /* 后面n - 1为可以用z填充，该位可以填a */
                res += 'a';
                k -= 1;
            } else {
                /* 后面n - 1不能用z填充，该位填k - 26 * (n - 1) */
                int d = k - 26 * (n - 1);
                res += 'a' + d - 1;
                k -= d;
            }
            n--;
        }

        return res;
    }
};
