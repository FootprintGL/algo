

/* 排序 - 按名词出现次数多少将需排序，如果名词次数相同，按字母升序排序 */
bool comp(pair<char, vector<int>> &p1, pair<char, vector<int>> &p2) {
    return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int cnt = votes[0].size();

        /* 初始化哈希表 */
        unordered_map<char, vector<int>> rank;
        for (auto &c : votes[0])
            rank[c].resize(cnt);

        /* rank存放team i第j名的次数 */
        for (auto &s : votes) {
            for (int i = 0; i < cnt; i++)
                rank[s[i]][i]++;
        }

        /* 取出键值对放入数组并排序 */
        vector<std::pair<char, vector<int>> > tmp(rank.begin(), rank.end());
        sort(tmp.begin(), tmp.end(), comp);

        /* 构建结果 */
        string res;
        for (auto &[vid, rank] : tmp)
            res += vid;

        return res;
    }
};
