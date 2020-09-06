
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.length();
        int len2 = second.length();
        string tmp;
        int i;

        if (first.compare(second) == 0)
            return true;

        if (abs(len1 - len2) >= 2)
            return false;

        /* 保证second更长 */
        if (len1 > len2)
            return oneEditAway(second, first);

        for (i = 0; i < len1; i++) {
            if (first[i] != second[i]) {
                /* 如果长度相同就比较下一个，如果不同就从当前开始比较 */
                if (second.substr(i + 1, len2 - i).compare(first.substr(i + (len1 == len2 ? 1 : 0), len2 - i)) == 0)
                    return true;
                else
                    return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.length();
        int len2 = second.length();
        string tmp;
        int i;

        if (first.compare(second) == 0)
            return true;

        if (abs(len1 - len2) >= 2)
            return false;

        if (len1 == len2) {
            int cnt = 0;
            for (i = 0; i < len1; i++) {
                if (first[i] != second[i]) {
                    cnt++;
                    if (cnt == 2)
                    /* 2个不同字母 */
                        return false;
                }
            }
            return true;
        } else {
            if (len1 < len2) {
                for (i = 0; i < len2; i++) {
                    tmp = second;
                    if (first.compare(tmp.erase(i, 1)) == 0)
                        return true;
                }
                return false;
            } else {
                for (i = 0; i < len1; i++) {
                    tmp = first;
                    if (second.compare(tmp.erase(i, 1)) == 0)
                        return true;
                }
                return false;
            }
        }

        return true;
    }
};
