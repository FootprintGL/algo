class Solution {
public:
    int findLUSlength(string a, string b) {
        int na = a.length();
        int nb = b.length();

        /* 如果长度不同，返回长度大的长度，如果长度相同，字符串相等返回1，不等返回长度 */
        if (a != b)
            return max(na, nb);
        
        return -1;
    }
};

class Solution {
public:
    int helper(string a, string b) {
        int res = -1;
        int na = a.length();

        for (int i = 0; i < na; i++) {
            for (int j = i; j < na; j++) {
                if (b.find(a.substr(i, j - i + 1)) == string::npos && j - i + 1 > res)
                    res = j - i + 1;
            }
        }

        return res;
    }

    int findLUSlength(string a, string b) {
        int res = 0;
        int na = a.length();
        int nb = b.length();

        /* 长串不是短串的子序列 */
        if (na != nb)
            return max(na, nb);

        return max(helper(a, b), helper(b, a));
    }
};
