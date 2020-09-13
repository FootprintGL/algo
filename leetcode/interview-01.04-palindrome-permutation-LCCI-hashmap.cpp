

class Solution {
public:
    bool canPermutePalindrome(string s) {
        /* 所有字母最多有一个出现奇数次 */
        unordered_map<char, int> mymap;

        for (auto c : s)
            mymap[c]++;

        int oddcnt = 0;
        for (auto &[c, cnt] : mymap)
            if (cnt % 2)
                oddcnt++;

        return oddcnt < 2 ? true : false;
    }
};
