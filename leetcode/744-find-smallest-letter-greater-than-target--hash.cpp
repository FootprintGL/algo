
class Solution {
public:
    char next(char c) {
        if (c == 'z')
            return 'a';
        else
            return c + 1;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        /* 哈希表 */
        unordered_set<char> dic;
        char ans;

        /* 字母循环出现，从target下一个字母开始查找 */
        for (auto c : letters)
            dic.insert(c);

        ans = next(target);
        while (dic.count(ans) == 0) {
            ans = next(ans);
        }

        return ans;
    }
};
