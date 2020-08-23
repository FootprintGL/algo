

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, len = s.length();
        int cnt0 = 0, cnt1 = 0;

        s[0] == '0' ? cnt0++ : cnt1++;
        for (int i = 1; i < len; i++) {
            if (s[i] == s[i - 1]) {
                s[i] == '0' ? cnt0++ : cnt1++;
            } else {
                res += min(cnt0, cnt1);
                s[i] == '0' ? (cnt0 = 1) : (cnt1 = 1);
            }
        }
        res += min(cnt0, cnt1);

        return res;
    }
};
