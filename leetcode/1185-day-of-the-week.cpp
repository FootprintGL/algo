

class Solution {
public:
    bool leap(int year) {
        return ((year % 4 == 0 && year % 100) || year % 400 == 0);
    }

    string dayOfTheWeek(int day, int month, int year) {
        string week[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        /* 1971.01.01 Friday - 计算距离天数再转化为星期 */
        int days = 0;

        for (int y = 1971; y < year; y++) {
            days += leap(y) ? 366 : 365 ;
        }

        for (int m = 0; m < month - 1; m++) {
            days += months[m];
            if (leap(year) && m == 1)
                days += 1;
        }

        days += day;
        days %= 7;

        return week[days];
    }
};
