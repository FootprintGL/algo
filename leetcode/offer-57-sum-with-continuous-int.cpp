



class Solution {
public:
    void fillrow(vector<int> &row, int start, int end) {
        for (int i = start; i <= end; i++)
            row.push_back(i);
    }
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> row;
        int sum = 1;
        int i = 1, j = 2, k;

        if (target < 3)
            return res;

        /* 滑动窗口 */
        while (true) {
            while (j < target && sum < target) {
                /* 区间和小于target，向右扩展j++ */
                sum += j;
                j++;
            }
            if (j == target) {
                /* 延伸到最后一个元素 */
                if (sum == target) {
                    /* 找到一个有效结果，退出 */
                    fillrow(row, i, j - 1);
                    res.push_back(row);
                    row.clear();
                    break;
                } else if (sum < target) {
                    /* 区间和小于target，无法再向右扩展，退出 */
                    break;
                }
            } else {
                if (sum == target) {
                    /* 找到一个有效结果，保存结果，向右扩展一个元素 */
                    fillrow(row, i, j - 1);
                    res.push_back(row);
                    row.clear();
                    sum += j;
                    j++;
                } 
            }

            while (i < j && sum > target) {
                /* 区间和大于target，左边收缩区间 */
                sum -= i;
                i++;
            }
            if (sum == target) {
                /* 找到一个有效结果，保存结果，可能的话向右扩展一个元素 */
                fillrow(row, i, j - 1);
                res.push_back(row);
                row.clear();
                if (j < target) {
                    sum += j;
                    j++;
                }
            }
        }

        return res;
    }
};
