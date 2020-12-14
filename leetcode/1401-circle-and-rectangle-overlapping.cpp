

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        /*
         * 矩形区域内点离圆心最近的点的距离小于等于圆的半径
         * x_center < x1 < x2 -> min(dx) = x1 - x_center
         * x1 <= x_center <= x2 -> min(dx) = 0
         * x2 < x_center -> min(dx) = x_center - x2
         * y类似
         */
        int dx = x_center < x1 ? x1 - x_center : x2 < x_center ? x2 - x_center : 0;
        int dy = y_center < y1 ? y1 - y_center : y2 < y_center ? y2 - y_center : 0;

        return dx * dx + dy * dy <= radius * radius;
    }
};
