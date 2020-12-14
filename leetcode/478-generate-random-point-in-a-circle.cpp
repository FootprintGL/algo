

class Solution {
public:
    double r;
    double xc;
    double yc;

    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
    }

    vector<double> randPoint() {
        /* 方形拒绝采样 - 圆形外加一正方形 */
        double tx = 2.0;
        double ty = 2.0;
        do {
            /*
             * tx = 2 * (double)rand() / RAND_MAX - 1相当与在[-1,1]之间随机取一个double
             * rand() -> [0, RAND_MAX], rand()/RAND_MAX范围是[0,1]
             */
            tx = 2 * (double)rand() / RAND_MAX - 1;
            ty = 2 * (double)rand() / RAND_MAX - 1;
        } while(tx * tx + ty * ty > 1);

        return {xc + tx * r, yc + ty * r};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
