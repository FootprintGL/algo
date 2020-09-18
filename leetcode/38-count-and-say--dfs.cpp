

class Solution {
public:
    string res;

    void dfs(string& cur, int k, int n) {
        if (k == n) {
            res = cur;
            return;
        }
        string ans;
        int l = 0;
        int r = l;
        int len = cur.length();

        while (r < len) {
            r = l + 1;
            while (r < len && cur[r] == cur[l])
                r++;
            ans += to_string(r - l);
            ans += cur[l];
            l = r;
        }
        dfs(ans, k + 1, n);
    }

    string countAndSay(int n) {
        string cur(1, '1');
        dfs(cur, 1, n);
        return res;
    }
};
