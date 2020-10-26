

/* 二分法 */
class Solution {
public:
    int search(vector<vector<int>> &increase, int i, int target) {
        int left = 0, right = increase.size() - 1, mid;

        if (target == 0)
            return 0;

        if (target > increase[right][i])
            return -1;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (increase[mid][i] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left + 1;
    }

    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int m = increase.size();
        int n = requirements.size();
        vector<int> res(n, -1);
        int i;

        /*
         * 二分法
         * 每一个属性相互独立，单独看每个属性的trigger时间
         * 结果为三个属性最大值
         */
        int x = 0, y = 0, z = 0;

        /* increase前缀和递增 */
        for (i = 0; i < m; i++) {
            x += increase[i][0];
            y += increase[i][1];
            z += increase[i][2];
            //cout << i << " " << x << " " << y << " " << z << endl;
            increase[i][0] = x;
            increase[i][1] = y;
            increase[i][2] = z;
        }

        for (i = 0; i < n; i++) {
            x = search(increase, 0, requirements[i][0]);
            y = search(increase, 1, requirements[i][1]);
            z = search(increase, 2, requirements[i][2]);
            //cout << i << " - " << x << " " << y << " " << z << endl;
            if (x == -1 || y == -1 || z == -1)
                continue;
            res[i] = max(x, max(y, z));
        }

        return res;
    }
};


/* 暴力超时 */
class Solution {
public:
    void helper(int x, int y, int z, int index, vector<vector<int>> &requirements, vector<int> &res) {
        for (int i = 0; i < requirements.size(); i++) {
            if (res[i] != -1)
                continue;
            if (requirements[i][0] == 0 && requirements[i][1] == 0 && requirements[i][2] == 0) {
                res[i] = 0;
                continue;
            }
            if (x >= requirements[i][0] && y >= requirements[i][1] && z >= requirements[i][2])
                res[i] = index;
        }
    }

    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        /* 暴力模拟 */
        int n = requirements.size();
        vector<int> res(n, -1);
        int x = 0, y = 0, z = 0;

        for (int i = 0; i < increase.size(); i++) {
            x += increase[i][0];
            y += increase[i][1];
            z += increase[i][2];
            helper(x, y, z, i + 1, requirements, res);
        }

        return res;
    }
};
