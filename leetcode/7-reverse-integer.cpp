

class Solution {
public:
    int reverse(int x) {

        /*
         * INT_MAX - 2147483647
         * INT_MIN - -2147483648
         * 逐位反转，注意一出
         * 如果temp = 10 * res + pop溢出，则必有res >= INT_MAX / 10
         * 如果res > INT_MAX / 10, 必溢出
         * 如果res == INT_MAX / 10, 如果pop > 7会溢出
         */
        int res = 0;
        //cout << INT_MAX << " " << INT_MIN << endl;

        while (x) {
            int pop = x % 10;
            if (res == INT_MAX / 10 && pop > 7 || res > INT_MAX / 10)
                return 0;
            if (res == INT_MIN / 10 && pop < -8 || res < INT_MIN / 10)
                return 0;

            res = res * 10 + pop;
            x /= 10;
        }

        return res;
    }
};
