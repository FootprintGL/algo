

class Solution {
public:
    string intToRoman(int num) {
        /* 贪心 */
        int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[14] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        int idx = 0;

        /* 尽量选择大的数字进行转换 */
        while (idx < 13) {
            while (num >= nums[idx]) {
                res += roman[idx];
                num -= nums[idx];
            }
            idx++;
        }

        return res;
    }
};
