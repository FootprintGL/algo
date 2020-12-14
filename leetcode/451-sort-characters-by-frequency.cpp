

class Solution {
public:
    string frequencySort(string s) {
        /* 先统计每个字符出现个数 - 再重构字符串 */
        unordered_map<char, int> freq;

        /* 统计字符个数放入哈希表 */
        for (auto &c : s)
            freq[c]++;

        /* 放入数组并按字符出现频率排序 */
        vector<pair<char, int>> tmp (freq.begin(), freq.end());
        sort(tmp.begin(), tmp.end(), [](const pair<char, int> &l, const pair<char, int> &r){
            /* 降序排列 */
            return l.second > r.second;
        });

        /* 构造结果 */
        string res;
        for (auto &[c, cnt] : tmp)
            for (int i = 0; i < cnt; i++)
                res += c;

        return res;
    }
};
