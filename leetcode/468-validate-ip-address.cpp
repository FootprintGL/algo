

class Solution {
public:
    void split(string &s, vector<string> &vs, const char delim = ' ') {
        istringstream iss(s);
        string temp;
        while (getline(iss, temp, delim)) {
            /* 分割字符串 */
            vs.push_back(temp);
        }

        if (!s.empty() && s.back() == delim)
        /* delim结尾的情况，比如0.0.0.0., 0:0:0:0:0:0:0:0:0: */
            vs.push_back({});
    }

    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    bool validivp4(string &IP) {
        vector<string> vs;
        split(IP, vs, '.');

        if (vs.size() != 4)
        /* 有效的ipv4地址有四段 */
            return false;

        for (auto &v : vs) {
            if (v.empty() || (v.size() > 1 && v[0] == '0') || v.size() > 3)
            /* 不能空段，不能有前导0，不能超过255 */
                return false;

            for (auto &c : v)
                if (!isdigit(c))
                /* 只能是数字 */
                    return false;

            int num = stoi(v);
            if (num > 255)
            /* 0 ~ 255 */
                return false;
        }

        return true;
    }

    bool validipv6(string &IP) {
        vector<string> vs;
        split(IP, vs, ':');

        if (vs.size() != 8)
        /* ipv6八段 */
            return false;

        for (auto &v : vs) {
            if (v.empty() || v.size() > 4)
            /* 不能出现空段和长度大于4的段 */
                return false;
            for (auto &c : v) {
                if (!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                /* 只能含有数字和a/A ~ f/F */
                    return false;
            }
        }

        return true;
    }

    string validIPAddress(string IP) {
        if (validivp4(IP))
            return "IPv4";

        if (validipv6(IP))
            return "IPv6";

        return "Neither";
    }
};
