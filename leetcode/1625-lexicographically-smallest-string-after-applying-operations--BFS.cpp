

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        /*
         * 数据量小 - BFS暴力记忆化搜索
         */
        unordered_set<string> vis;
        queue<string> qu;
        string res = s;
        int n = s.length();

        qu.push(s);
        vis.insert(s);
        while (!qu.empty()) {
            auto cur = qu.front();
            qu.pop();

            string cc = cur;
            /* 累加：奇数位+a */
            for (int i = 1; i < n; i += 2) {
                cc[i] = (cc[i] - '0' + a) % 10 + '0';
            }
            //cout << "op1: " << cur << " " << cc << endl;
            if (!vis.count(cc)) {
                if (res > cc)
                    res = cc;
                qu.push(cc);
                vis.insert(cc);
            }

            /* 轮转：向右轮转b */
            string con = cur.substr(n - b) + cur.substr(0, n - b);
            //cout << "op2: " << cur << " " << con << endl;
            if (!vis.count(con)) {
                if (res > con)
                    res = con;
                qu.push(con);
                vis.insert(con);
            }
        }
/*
        for (auto &t : vis)
            cout << t << endl;
*/
        return res;
    }
};
