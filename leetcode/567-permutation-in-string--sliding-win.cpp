

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
         * 滑动窗口
         * 维护一个s1.size()大小的窗口从左向右滑动，统计每个字母的次数
         * 如果窗口内字母及个数相同，则返回true
         */
        int m = s1.size();
        int n = s2.size();

        if (m > n)
            return false;

        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);

        for (int i = 0; i < m; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        for (int i = m; i < n; i++) {
            if (cnt1 == cnt2)
                return true;
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - m] - 'a']--;
        }

        return cnt1 == cnt2;
    }
};
