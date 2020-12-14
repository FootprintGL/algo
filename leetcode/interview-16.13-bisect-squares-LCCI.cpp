

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        /* 几何题 - 经过中心点的直线把正方形分成面积相同的两半 */
        vector<double> cent1 = {(double)square1[0] + (double)square1[2] / 2, (double)square1[1] + (double)square1[2] / 2};
        vector<double> cent2 = {(double)square2[0] + (double)square2[2] / 2, (double)square2[1] + (double)square2[2] / 2};

        double x1, x2, y1, y2;

        if (cent1[0] == cent2[0]) {
            /* 斜率无穷大 */
            x1 = x2 = cent1[0];
            y1 = (double)min(square1[1], square2[1]);
            y2 = (double)max(square1[1] + square1[2], square2[1] + square2[2]);
        } else {
            double k = (cent2[1] - cent1[1]) / (cent2[0] - cent1[0]);
            if (abs(k) < 1) {
                /* 斜率小于1 - 直线交左右两条边 */
                x1 = (double)min(square1[0], square2[0]);
                x2 = (double)max(square1[0] + square1[2], square2[0] + square2[2]);
                y1 = cent1[1] - k * (cent1[0] - x1);
                y2 = cent1[1] + k * (x2 - cent1[0]);
            } else {
                /* 斜率大于等于1 - 直线交上下两条边 */
                y1 = (double)min(square1[1], square2[1]);
                y2 = (double)max(square1[1] + square1[2], square2[1] + square2[2]);
                x1 = cent1[0] - (cent1[1] - y1) / k;
                x2 = cent1[0] + (y2 - cent1[1]) / k;
                if (x1 > x2) {
                    swap(x1, x2);
                    swap(y1, y2);
                }
            }
        }

        return {x1, y1, x2, y2};
    }
};
