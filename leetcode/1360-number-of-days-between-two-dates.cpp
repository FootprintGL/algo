

class Solution {
public:
    void convert(string date, int &y, int &m, int &d) {
        y = stoi(date.substr(0, 4));
        m = stoi(date.substr(5, 2));
        d = stoi(date.substr(8, 2));
        //cout << y << " " << m << " " << d << endl;
    }

    bool leap(int y) {
        /* 润年：被4整除不被100整除或能被400整除 */
        return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
    }

    int daysBetweenDates(string date1, string date2) {
        int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = 0;
        int y1, m1, d1, y2, m2, d2;

        if (date1 > date2) {
            string tmp = date1;
            date1 = date2;
            date2 = tmp;
        }
        convert(date1, y1, m1, d1);
        convert(date2, y2, m2, d2);
        int y, m, i;

        int year = 0;

        for (i = 0; i < 12; i++)
            year += month[i];

        int cnt = 0;
        /* 计算 y1 -> y2 - 1 */
        for (y = y1; y < y2; y++) {
            days += year;
            if (leap(y)) {
                days += 1;
                cnt++;
            }
        }

        /* 加上 y2年到m2-d2 */
        for (m = 0; m < m2 - 1; m++) {
            days += month[m];
            if (leap(y2) && m == 1)
                days += 1;
        }
        days += d2;

        /* 减去 y1到m1-d1 */
        for (m = 0; m < m1 - 1; m++) {
            days -= month[m];
            if (leap(y1) && m == 1)
                days -= 1;
        }
        days -= d1;

        return days;
    }
};
