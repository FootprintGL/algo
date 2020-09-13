
class Solution {
public:
    int dayOfYear(string date) {
        int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 0;
        int y, m, d;

        y = stoi(date.substr(0, 4), nullptr, 10);
        m = stoi(date.substr(5, 2), nullptr, 10);
        d = stoi(date.substr(8, 2), nullptr, 10);

        /* 润年2月29天 - 能整除4不能整除100或能整除400 */
        if ((y % 4 == 0 && y % 100) || (y % 400 == 0))
            month[1]++;

        for (int i = 0; i < m - 1; i++) {
            res += month[i];
        }

        res += d;

        return res;
    }
};
