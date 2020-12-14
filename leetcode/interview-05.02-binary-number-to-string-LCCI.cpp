


class Solution {
public:
    string printBin(double num) {
        /* 十进制小数转二进制小数 */
        string res = "0.";
        int i = 30;

        while (num && i--) {
            num *= 2;
            if (num >= 1) {
                res += '1';
                num -= 1;
            } else {
                res += '0';
            }
        }

        return num == 0 ? res : "ERROR";
    }
};
