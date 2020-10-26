

class Solution {
public:
    vector<int> partitionLabels(string S) {
        /*
         * 贪心 - 双指针
         * 先统计每个字母最后出现的位置，然后从头开始遍历字符串
         * 每遇到一个字母，当前字母所在的区间最远会延伸到这个字母最后出现的位置即bound
         * 继续遍历会不断刷新bound，如果遍历指针达到bound，表明区间结束，开始计算下一个区间
         */
        vector<int> res;
        int pos[26] = {0}, i;
        int start = 0, end = 0;

        /* 记录每个字符最后出现的位置坐标 */
        for (i = 0; i < S.length(); i++)
            pos[S[i] - 'a'] = i;

        for (i = 0; i < S.length(); i++) {
            /* 更新区间最远边界 */
            end = max(end, pos[S[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return res;
    }
};
