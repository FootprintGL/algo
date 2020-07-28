

class Solution {
public:
    /* 判断T是否为S的因子 - T能除尽S */
    bool helper(string S, string T) {
        int ns = S.size();
        int nt = T.size();
        int i = 0, j = 0;

        if (ns % nt)
            return false;

        while (i < ns) {
            if (S[i] != T[j])
                return false;
            i++;
            j++;
            j %= nt;
        }

        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        string comm;
        string res;
        int n1 = str1.size();
        int n2 = str2.size();
        int i = 0, j = 0;

        /* 最大公因子必为str1和str2的公共前缀 - 检查所有的公共前缀看是否为公因子 */
        while (i < n1 && j < n2) {
            if (str1[i] == str2[j]) {
                comm.push_back(str1[i]);
                if (helper(str1, comm) && helper(str2, comm))
                    res = comm;
            } else {
                break;
            }
            i++;
            j++;
        }

        return res;
    }
};
