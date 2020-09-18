

class Solution {
public:
    string translate(string word, string dic[]) {
        string res;

        for (auto &c : word) {
            res += dic[c - 'a'];
        }

        return res;
    }

    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> tbl;
        string dic[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for (auto &word : words) {
            tbl.insert(translate(word, dic));
        }

        return tbl.size();
    }
};
