
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double ratio;
        int n = coordinates.size();

        /* 斜率dy1/dx1 = dy2/dx2 -> 转换为乘法解决分母为0的情况都dy1 * dx2 = dx1 * dy2 */
        double dx1 = (double)coordinates[1][0] - (double)coordinates[0][0];
        double dy1 = (double)coordinates[1][1] - (double)coordinates[0][1];

        for (int i = 2; i < n; i++) {
            double dx2 = (double)coordinates[i][0] - (double)coordinates[i - 1][0];
            double dy2 = (double)coordinates[i][1] - (double)coordinates[i - 1][1];

            if (dx1 * dy2 != dx2 * dy1)
                return false;
        }

        return true;
    }
};
