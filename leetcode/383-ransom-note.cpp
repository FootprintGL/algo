

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letcnt[26] = {0};

        for (auto &c : magazine)
            letcnt[c - 'a']++;

        for (auto &c : ransomNote) {
            if (letcnt[c - 'a']-- == 0)
                return false;
        }

        return true;
    }
};
