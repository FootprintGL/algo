

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
         * 贪心算法
         * 实际是求交替最大和最下值
         * prevdiff记录前面是上升还是下降，转弯处cnt++
         * 边遍历边更新
         */
        int n = nums.size();
        if (n < 2)
            return n;

        int prevdiff, diff, cnt;
        int i, j;

        prevdiff = nums[1] - nums[0];
        cnt = prevdiff != 0 ? 2 : 1;
        for (i = 2; i < n; i++) {
            diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                cnt++;
                prevdiff = diff;
            }
        }

        return cnt;
    }
};


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
         * 动态规划
         * up[i] - 以nums[i]结尾的最长上升摆动序列的长度
         * down[i] - 以nums[i]结尾的最长下降摆动序列的长度
         * nums[i]和前一个元素nums[i - 1]有3中关系
         * 如果nums[i] > nums[i - 1]: up[i] = down[i - 1] + 1, down[i] = down[i - 1]
         * 如果nums[i] < nums[i - 1]: down[i] = up[i - 1] + 1, up[i] = up[i - 1]
         * 如果nums[i] == nums[i - 1]: down[i] = down[i - 1], up[i] = up[i - 1]
         * 结果为max{up[n - 1], down[n - 1]}
         */
        int n = nums.size();
        if (n < 2)
            return n;

        vector<int> up(n, 1);
        vector<int> down(n, 1);
        int i, j;

        for (i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }

        return max(up[n - 1], down[n - 1]);
    }
};


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
         * 动态规划
         * up[i] - 以nums[i]结尾的最长上升摆动序列的长度
         * down[i] - 以nums[i]结尾的最长下降摆动序列的长度
         * up[i] = max{down[j] + 1}, j: 0 -> i - 1并且nums[j] < nums[i]
         * down[i] = max{up[j] + 1}, j: 0 -> i - 1并且nums[j] > nums[i]
         * 结果为max{up[n - 1], down[n - 1]}
         */
        int n = nums.size();
        if (n < 2)
            return n;

        vector<int> up(n, 1);
        vector<int> down(n, 1);
        int i, j;

        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    up[i] = max(up[i], down[j] + 1);
                if (nums[j] > nums[i])
                    down[i] = max(down[i], up[j] + 1);
            }
        }

        return max(up[n - 1], down[n - 1]);
    }
};
