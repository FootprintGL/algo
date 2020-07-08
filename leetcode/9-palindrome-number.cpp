class Solution {
public:
    bool isPalindrome(int x) {
        int div = 1;
        int l, r;

        /* 特殊情况 - x为负数或x为0结尾的数字（数字开始没有0） */
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        /* 找到最高位数 */
        while (x / div >= 10)
            div = div * 10;

        /* 从数字两边往中间位逐一比较，不相等则不是回文 */
        //while (div != 0) { -> 100000000001 会出现很多多余处理
        while (x > 0) {
            l = x / div;
            r = x % 10;
            if (l != r)
                return false;
            x = x % div / 10;
            div = div / 100;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        int div = 1;
        int l, r;

        /* 特殊情况 - x为负数或x为0结尾的数字（数字开始没有0） */
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        /* 找到最高位数 */
        while (x / div >= 10)
            div = div * 10;

        /* 从数字两边往中间位逐一比较，不相等则不是回文 */
        while (div != 0) {
            l = x / div;
            r = x % 10;
            if (l != r)
                return false;
            x = x % div / 10;
            div = div / 100;
        }

        return true;
    }
};
