
class Solution {
public:
    /* 鞋带公式 */
    double area(vector<int> &P, vector<int> &Q, vector<int> &R) {
        return 0.5 * abs(P[0]*Q[1] + Q[0]*R[1] + R[0]*P[1]
                             -P[1]*Q[0] - Q[1]*R[0] - R[1]*P[0]);
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        vector<double> len;
        int i, j, k;

        for (i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    ans = max(ans, area(points[i], points[j], points[k]));
                }
            }
        }

        return ans;
    }
};
