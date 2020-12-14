

class Solution {
public:
    /* 交易信息结构体 */
    struct transaction {
        int time;
        int amount;
        string city;
        transaction(int a, int b, string c) : time(a), amount(b), city(c) {}
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        unordered_map<string, vector<transaction>> tbl;

        /* 交易记录放入哈希表 */
        for (auto &tran : transactions) {
            /* 利用istringstream分割字符串 */
            istringstream iss(tran);
            string temp;
            vector<string> vt;
            while (getline(iss, temp, ','))
                vt.push_back(temp);
            tbl[vt[0]].push_back(transaction(stoi(vt[1]), stoi(vt[2]), vt[3]));
        }

        for (auto i = tbl.begin(); i != tbl.end(); i++) {
            vector<transaction> &t = (*i).second;
            /* 标记无效交易 */
            vector<bool> invalid(t.size(), false);
            for (int j = 0; j < t.size(); j++) {
                if (t[j].amount > 1000)
                /* 金额太大 - 无效交易 */
                    invalid[j] = true;
                for (int k = j + 1; k < t.size(); k++) {
                    /* 检查异地交易时间间隔 */
                    if (t[j].city == t[k].city)
                    /* 跳过同城交易 */
                        continue;
                    if (abs(t[k].time - t[j].time) <= 60)
                        /* 异地时间间隔时间太短 - 无效交易 */
                        invalid[j] = invalid[k] = true;
                }
                if (invalid[j])
                    /* 保存无效交易 */
                    res.push_back((*i).first + "," + to_string(t[j].time) + "," + to_string(t[j].amount) + "," + t[j].city);
            }
        }

        return res;
    }
};
