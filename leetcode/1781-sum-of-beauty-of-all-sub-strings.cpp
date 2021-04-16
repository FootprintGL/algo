

class Solution {
public:
    int beautySum(string s) {
        /*
         * 滑动窗口
         * 依次检测长度为3 ～ n - 1的字串
         * len == 1 -> 美丽值为0
         * len == 2 -> 美丽值为0 (不管相等还是不等美丽值都为0)
         */
        int res = 0;
        int n = s.length();

        for (int len = 3; len <= n; len++) {
            /* 枚举子串长度 */
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            while (r < n) {
                cnt[s[r] - 'a']++;
                r++;
                if (r - l == len) {
                    int cmax = INT_MIN, cmin = INT_MAX;
                    for (int i = 0; i < 26; i++) {
                        if (cnt[i] > 0) {
                            cmax = max(cmax, cnt[i]);
                            cmin = min(cmin, cnt[i]);
                        }
                    }
                    //cout << len << " " << l << " " << r << " " << cmax << " " << cmin << " ";
                    res += cmax - cmin;
                    //cout << res << endl;
                    cnt[s[l] - 'a']--;
                    l++;
                }
            }
        }

        return res;
    }
};
