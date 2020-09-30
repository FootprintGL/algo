

class Solution {
public:
    bool samepoint(vector<int> &p1, vector<int> &p2) {
        return (p1[0] == p2[0] && p1[1] == p2[1]);
    }

    bool sameline(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
        double delta1 = ((double)p2[1] - p1[1]) / ((double)p2[0] - p1[0]);
        double delta2 = ((double)p3[1] - p1[1]) / ((double)p3[0] - p1[0]);
        return delta1 == delta2;
    }

    bool isBoomerang(vector<vector<int>>& points) {
        return (!samepoint(points[0], points[1]) &&
            !samepoint(points[0], points[2]) &&
            !samepoint(points[1], points[2]) &&
            !sameline(points[0], points[1], points[2]));
    }
};
