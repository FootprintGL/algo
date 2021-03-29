

class Solution {
    int cnt[26] = {0};
    int res;

public:
    void dfs() {
        /* 终止条件 - 所有字符都使用完毕 */
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0)
            /* 当前字符已用完 */
                continue;
            cnt[i]--;
            /* 更新结果 */
            res++;
            dfs();
            /* 回溯 */
            cnt[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        res = 0;
        /* 统计每个字母频数 */
        for (int i = 0; i < tiles.size(); i++) {
            cnt[tiles[i] - 'A']++;
        }
        dfs();

        return res;
    }
};
