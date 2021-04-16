

class Solution {
public:
    double diff(int x, int y) {
        /* 增加一个元素，通过率的增量 */
        return (double)(x + 1) / (y + 1) - (double)x / y;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        /*
         * 最大堆
         * 班级增加学生会提高通过率，随着增加个数越来越多，所能改变的通过率变小
         * 每个班级的通过率权重相同，每次选择通过率增加最大的班级增加学生
         */
        priority_queue<tuple<double, int, int>> pq;
        double res = 0;

        for (auto &c : classes) {
            int pass = c[0];
            int total = c[1];
            res += (double)pass / total;
            pq.emplace(diff(pass, total), pass, total);
        }

        while (extraStudents > 0) {
            auto [d, x, y] = pq.top();
            pq.pop();
            res += d;
            pq.emplace(diff(x + 1, y + 1), x + 1, y + 1);
            extraStudents--;
        }

        return res / classes.size();
    }
};
