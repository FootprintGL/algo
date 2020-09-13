

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> res;
        int i, j, k = 0, l = 0;
        int m = nums.size(), n = nums[0].size();
        vector<int> cur(c, 0);

        if (r * c != m * n)
            return nums;

        /* 逐行填充即可 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cur[k++] = nums[i][j];
                if (k == c) {
                    res.push_back(cur);
                    k = 0;
                    l++;
                    /* 矩阵元素个数相等，不需要特别break
                    if (l == r)
                        break;*/
                }
                /*
                if (l == r)
                    break;
                    */
            }
        }

        return res;
    }
};
