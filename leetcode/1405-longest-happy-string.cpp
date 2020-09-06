

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        /*  
         * 贪心算法
         * 每次放2个剩余次数最多的，如果上次放的2个字符和当前剩余个数最多的字符相同
         * 放一个次多的
         */
        vector<pair<int, char>> tbl;
        string res;

        tbl.push_back({a, 'a'});
        tbl.push_back({b, 'b'});
        tbl.push_back({c, 'c'});

        while (res.size() < a + b + c) {
            /* 从大到小排序 - rbegin/rend */
            sort(tbl.rbegin(), tbl.rend());
            
            if (!res.empty() && res.back() == tbl[0].second) {
                if (tbl[1].first-- > 0)
                    /* 剩余最多元素和上次放置元素相同，放一个次多的 */
                    res.push_back(tbl[1].second);
                else
                    /* 没有其他元素可以放置，结束循环 */
                    break;
            } else {
                if (tbl[0].first-- > 0)
                    res.push_back(tbl[0].second);
                if (tbl[0].first-- > 0)
                    res.push_back(tbl[0].second);
            }
        }

        return res;
    }
};


/* 回溯算法 - 超时 */
class Solution {
public:
    string ans;
    string str;

    bool dfs(string &cur, vector<int> &cnt, char pre, int precnt) {
        //cout << cur << " " << pre << " " << precnt << " " << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
        if (ans.size() < cur.size())
            ans = cur;
        //cout << cur << " " << ans << endl << endl;

        if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0) {
            return true;
        }

        for (int i = 0; i < 3; i++) {
            if (cnt[i] == 0)
            /* 该字母用完 */
                continue;

            if (pre == str[i]) {
                if (precnt == 2)
                /* 该字母已经达到上限2 */
                    continue;
                cur.push_back(str[i]);
                cnt[i]--;
                if (dfs(cur, cnt, pre, precnt + 1))
                    return true;
            } else {
                /* 放入新的字符 */
                cur.push_back(str[i]);
                cnt[i]--;
                if (dfs(cur, cnt, str[i], 1))
                    return true;
            }
            /* 回溯 */
            cnt[i]++;
            cur.pop_back();
        }

        return false;
    }

    string longestDiverseString(int a, int b, int c) {
        str = "abc";
        string cur;
        vector<int> cnt (3, 0);
        cnt[0] = a;
        cnt[1] = b;
        cnt[2] = c;
        dfs(cur, cnt, ' ', 0);
        return ans;
    }
};
