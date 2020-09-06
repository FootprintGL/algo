
class Solution {
public:
    unordered_map<string, int> map;
    vector<string> res;

    /* 域名解析 */
    void parser(string cpdomain) {
        /* 找空格 - 提取访问次数 */
        int i = 0, count;
        int len = cpdomain.length();
        string domain;
        while (i < len) {
            if (cpdomain[i] == ' ') {
                count = stoi(cpdomain.substr(0, i - 0));
                i++;
                break;
            } else {
                i++;
            }
        }

        /* 更新域名信息 */
        domain = cpdomain.substr(i, len - i + 1);
        map[domain] += count;

        /* 更新父域名信息 */
        while (i < cpdomain.length()) {
            if (cpdomain[i] == '.') {
                i++;
                domain = cpdomain.substr(i, len - i + 1);
                map[domain] += count;
            } else {
                i++;
            }
        }    
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (auto cpdomain : cpdomains) {
            parser(cpdomain);
        }

        for (auto str : map) {
            res.push_back(to_string(str.second) + " " + str.first);
        }

        return res;
    }
};


class Solution {
public:
    unordered_map<string, int> map;
    vector<string> res;

    /* 域名解析 */
    void parser(string cpdomain) {
        /* 找空格 - 提取访问次数 */
        int i = 0, count;
        int len = cpdomain.length();
        string domain;
        while (i < len) {
            if (cpdomain[i] == ' ') {
                count = stoi(cpdomain.substr(0, i - 0));
                i++;
                break;
            } else {
                i++;
            }
        }

        /* 更新域名信息 */
        domain = cpdomain.substr(i, len - i + 1);
        if (map.count(domain) == 0) {
            res.push_back(domain);
        }
        map[domain] += count;

        /* 更新父域名信息 */
        while (i < cpdomain.length()) {
            if (cpdomain[i] == '.') {
                i++;
                domain = cpdomain.substr(i, len - i + 1);
                if (map.count(domain) == 0) {
                    res.push_back(domain);
                }
                map[domain] += count;
            } else {
                i++;
            }
        }
    }

    /* 基于res和map更新结果 */
    void prepareresults() {
        string ans;
        for (int i = 0; i < res.size(); i++) {
            ans = to_string(map[res[i]]);
            ans += " ";
            res[i].insert(0, ans);
        }
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (auto cpdomain : cpdomains) {
            parser(cpdomain);
        }
        prepareresults();
        return res;
    }
};
