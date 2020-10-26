

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        /* 利用数组记录出生死亡时刻，再利用前缀和求最大值并记录index */
        int res = 0, sum = 0, maxv = 0;
        vector<int> cnt(102, 0);

        /* 统计每一年的净增加人数 */
        for (int i = 0; i < birth.size(); i++) {
            cnt[birth[i] - 1900]++;
            cnt[death[i] - 1900 + 1]--;
        }

        /* 统计每一年生存人数，求最大值并记录index */
        for (int i = 0; i < 101; i++) {
            sum += cnt[i];
            if (sum > maxv) {
                maxv = sum;
                res = i;
            }
        }

        return res + 1900;
    }
};
