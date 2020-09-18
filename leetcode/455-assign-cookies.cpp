
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /* 贪心算法 */
        int ans = 0;

        /* 先排序 */
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i = 0, j = 0; i < g.size(); i++) {
            while (j < s.size() && s[j] < g[i])
                j++;

            if (j == s.size())
                break;

            ans++;
            j++;
        }

        return ans;
    }
};
