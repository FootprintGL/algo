

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        /* 二分法 */
        int m = grid.size();
        int n = grid[0].size();
        int i, j, ans = 0, prev = n - 1;
        int l, r, mid;

        for (i = 0; i < m; i++) {
            if (grid[i][n - 1] >= 0)
                continue;

            l = 0;
            r = prev;

            while (l < r) {
                mid = l + (r - l) / 2;
                if (grid[i][mid] < 0) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            ans += n - l;
            prev = l;
            //cout << l << " " << r << " "<< ans << endl;
        }

        return ans;
    }
};
