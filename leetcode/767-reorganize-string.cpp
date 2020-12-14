

class Solution {
public:
    string reorganizeString(string S) {
        /* 贪心
         * 先判断所有字母出现个数都小于等于n/2可以重构
         * 选取字母多的依次放置，优先队列维护字母的个数
         */
        int n = S.length();
        int target = n % 2 ? n / 2 + 1 : n / 2;
        vector<int> cnt(26, 0);

        for (auto &c : S)
            cnt[c - 'a']++;

        for (auto &c: cnt)
            if (c > target)
                return "";

        auto cmp = [&](const char& c1, const char& c2) {
            return cnt[c1 - 'a'] < cnt[c2 - 'a'];
        };
        //错误 - priority_queue<char, vector<char>, decltype(cmp)> queue;
        priority_queue<char, vector<char>,  decltype(cmp)> qu{cmp};

/*
        auto cmp2 = [&](const pair<char, int>& c1, const pair<char, int>& c2) {
            return c1.second < c2.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>,  decltype(cmp2)> queue2{cmp2};
*/

        for (char c = 'a'; c <= 'z'; c++)
            if (cnt[c - 'a'] > 0)
                qu.push(c);

        string res;
        while (qu.size() > 1) {
            char c1 = qu.top();
            qu.pop();
            res += c1;
            char c2 = qu.top();
            qu.pop();
            res += c2;
            cnt[c1 - 'a']--;
            cnt[c2 - 'a']--;

            if (cnt[c1 - 'a'] > 0)
                qu.push(c1);

            if (cnt[c2 - 'a'] > 0)
                qu.push(c2);
        }

        if (qu.size())
            res += qu.top();

        return res;
    }
};
