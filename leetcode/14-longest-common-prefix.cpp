class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        int len, minlen;
        int i, j;

        /* return null string if strs is empty */
        if (n == 0)
            return res;

        /*find length for the shortest string in strs */
        minlen = strs[0].size();
        for (i = 1; i < n; i++) {
            len = strs[i].size();

            if (minlen > len)
                minlen = len;
        }

        /* find the longest substr's index */
        for (i = 0; i < minlen; i++) {
            for (j = 1; j < n; j++) {
                if (strs[j][i] != strs[0][i])
                    break;
            }

            if (j != n) {
                break;
            }
        }

        /* return the longest substr */
        return strs[0].substr(0, i);
    }
};
