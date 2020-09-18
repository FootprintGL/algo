

class Solution {
public:
    /* 反转l到r */
    void reverse(string &s, int start, int end) {
        //cout << "rev " << start << " " << end << endl;
        int l = start, r = end;
        while (l <= r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }

    void dfs(string &s, int start, int k) {
        int n = s.length();
        //cout << start << " " << n << endl;
        if (n - start + 1 <= k) {
            /* 剩下少于等于k个，全部反转 */
            reverse(s, start, n - 1);
            return;
        }

        if (n - start + 1 <= 2 * k) {
            /* 剩下(k, 2k], 反转k个，其余的保持不变 */
            reverse(s, start, start + k - 1);
            return;
        }

        /* 反转k个，跳过k个，递归处理剩下的 */
        reverse(s, start, start + k - 1);
        dfs(s, start + 2 * k, k);
    }

    string reverseStr(string s, int k) {
        dfs(s, 0, k);
        return s;
    }
};
