

class Solution {
public:
    bool goodnumber(int n) {
        bool ans = false;
        while (n) {
            int cur = n % 10;
            if (cur == 3 || cur == 4 || cur == 7) {
                ans = false;
                break;
            }
            if (cur == 2 || cur == 5 || cur == 6 || cur == 9)
                ans = true;
            n /= 10;
        }

        return ans;
    }

    int rotatedDigits(int N) {
        /* 好数 - 有2，5，6，9且没有3，4，7 */
        int cnt = 0;

        for (int i = 1; i <= N; i++)
            if (goodnumber(i))
                cnt++;

        return cnt;
    }
};
