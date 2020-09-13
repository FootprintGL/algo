
class Solution {
public:
    bool buddyStrings(string A, string B) {
        unordered_set<int> tbl;
        int m = A.length();
        int n =  B.length();
        int l = 0;
        int r = m - 1;
        bool same = false;

        if (m != n || m < 2 || n < 2)
            return false;
        
        /* 
         * 两种情况
         * 1. 找到2个不同处，交换看字符串是否相同
         * 2. 字符串相同且存在相同字符
         */
        while (l < r) {
            while (l < m && A[l] == B[l]) {
                if (tbl.count(A[l]))
                    same = true;
                else
                    tbl.insert(A[l]);

                l++;
            }

            if (l == m)
            /* 字符串相同 */
                return same;

            while (r > l && A[r] == A[l])
                r--;

            if (r == l)
                return false;

            /* 找到2出不同，交换 */
            char c = A[l];
            A[l] = A[r];
            A[r] = c;
            break;
        }

        return A.compare(B) == 0;
    }
};
