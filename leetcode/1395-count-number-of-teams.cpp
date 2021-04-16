

class Solution {
public:
    int numTeams(vector<int>& rating) {
        /*
         * 遍历中间的元素，统计 左边/右边 比它 大/小的rating的个数
         * 结果为 leftless * rightmore + leftmore * rightless
         */
        int n = rating.size();
        vector<vector<int>> left(n, vector<int> (2, 0));
        vector<vector<int>> right(n, vector<int> (2, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (rating[i] < rating[j])
                    left[i][0]++;
                else
                    left[i][1]++;
            }

            for (int k = i + 1; k < n; k++) {
                if (rating[i] < rating[k])
                    right[i][0]++;
                else
                    right[i][1]++;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += left[i][0] * right[i][1] + left[i][1] * right[i][0];
        }

        return res;
    }
};



/* 暴力 - 超时 */
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int n = rating.size();

        /* 暴力循环 */
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                bool assending = rating[i] < rating[j];
                for (int k = j + 1; k < n; k++) {
                    if (assending) {
                        if (rating[j] < rating[k])
                            res++;
                    } else {
                        if (rating[j] > rating[k])
                            res++;
                    }
                }
            }
        }

        return res;
    }
};
