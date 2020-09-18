
class Solution {
public:
    bool know(string word, unordered_map<char, int> &tbl) {
        unordered_map<char, int> wtbl;

        for (auto &c : word) {
            wtbl[c]++;
        }

        for (auto &c : word) {
            if (wtbl[c] > tbl[c])
                return false;
        }

        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> tbl;
        int ans = 0;

        for (auto &c : chars)
            tbl[c]++;

        for (auto &str : words) {
            if (know(str, tbl))
                ans += str.length();
        }

        return ans;
    }
};
