

class Solution {
public:
    bool checkRecord(string s) {
        /* cnt1记录A出现次数，cnt2记录L连续出现的次数 */
        int cnt1 = 0, cnt2 = 0;;

        for (auto c : s) {
            if (c == 'A') {
                cnt1++;
                cnt2 = 0;
                if (cnt1 > 1)
                    return false;
            } else if (c == 'L') {
                cnt2++;
                if (cnt2 == 3)
                    return false;
            } else {
                cnt2 = 0;
            }
        }

        return true;
    }
};
