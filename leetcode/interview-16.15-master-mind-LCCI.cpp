

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int> res (2, 0);
        unordered_map<char, int> tbl;

        /* 哈希表 */
        for (int i = 0; i < solution.length(); i++) {
            if (solution[i] == guess[i]) {
                res[0]++;
                continue;
            }
            tbl[solution[i]]++;
        }

        for (int i = 0; i < solution.length(); i++) {
            if (solution[i] != guess[i]) {
                if (tbl[guess[i]] > 0) {
                    res[1]++;
                    tbl[guess[i]]--;
                }
            }
        }

        return res;
    }
};
