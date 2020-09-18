
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        /* 暴力 - m * k个一组检测 */
        int n = arr.size();
        int i, j;

        for (i = 0; i <= n - m * k; i++) {
            for (j = i + m; j < i + m * k; j++) {
                if (arr[j] != arr[j - m])
                    break;
            }
            if (j == i + m * k )
                return true;
        }

        return false;
    }
};


class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int x, y, z;
        int n = arr.size();
        int cnt = 1;

        /* 暴力 */
        for (z = 0; z < n - m; z++) {
            cnt = 1;
            for (x = z; x + 2 * m - 1 < n; x += m) {
                for (y = 0; y < m; y++) {
                    if (arr[x + y] != arr[x + y + m])
                        break;
                }
                if (y == m) {
                    cnt++;
                    if (cnt == k)
                        return true;
                } else {
                    cnt = 1;
                    break;
                }
            }
        }

        return false;
    }
};
