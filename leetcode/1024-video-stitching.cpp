

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());

        /* 没有0开始的片段 */
        if (clips[0][0] > 0)
            return -1;

        if (clips[0][1] >= T)
            return 1;

        int n = clips.size();
        int i, r, pre, cnt = 1;

        pre = clips[0][1];
        i = 1;

        /* 选找0开始的最长片段 */
        while (i < n && clips[i][0] == 0 && clips[i][1] > pre) {
            if (clips[i][1] >= T)
                return cnt;
            pre = clips[i][1];
            i++;
        }

        /* 处理后续片段 */
        while (i < n) {
            r = pre;
            while (i < n && clips[i][0] <= pre) {
                if (clips[i][1] >= T)
                    return cnt + 1;

                if (clips[i][1] > r)
                    r = clips[i][1];
                i++;
            }

            /* 找不到下一个可连接片段 */
            if (r <= pre)
                return -1;

            cnt++;
            pre = r;
        }

        return -1;
    }
};
