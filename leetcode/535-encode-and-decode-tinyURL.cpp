

class Solution {
public:
    /*
     * 每一个URL建议一个6为随机数到URL的映射
     * 如果生成的随机数已经出现，则重新长生一个
     */

    /* 加密后的固定长度为6位，可加密的URL数目非常大(10 + 26 * 2) ^ len */
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int len = 6;
    unordered_map<string, string> tbl;

    string getrand() {
        string res;
        for (int i = 0; i < len; i++) {
            res.push_back(alphabet[rand() % 62]);
        }
        return res;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getrand();
        while (tbl.count(key)) {
            key = getrand();
        }
        tbl[key] = longUrl;

        return "http://tinurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tbl[shortUrl.erase(0, 18)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
