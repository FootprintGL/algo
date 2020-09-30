

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int car = 0, cur;
        int start = digits.size() - 1;

        /* 加法模拟 - 注意进位和溢出处理 */
        do {
            if (start < 0) {
                /* 溢出 */
                digits.insert(digits.begin(), 1);
                break;
            }
            cur = digits[start] + 1;
            if (cur == 10) {
                cur = 0;
                car = 1;
            } else {
                car = 0;
            }
            digits[start] = cur;
            start--;
        }while (car);

        return digits;
    }
};
