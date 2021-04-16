

class Solution {
public:
    bool checkPowersOfThree(int n) {
        /*
         * n表示成若干个不同的三的幂之和
         * 转换成三进制数字只有0和1
         */
        while (n > 0) {
            if (n % 3 == 2)
                return false;
            n /= 3;
        }

        return true;
    }
};
