

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> sdic;
        int cnt1 = 0, cnt2 = 0;

        /* 哈希表 */
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i])
                cnt1++;
            sdic[secret[i]]++;
        }

        for (int i = 0; i < secret.length(); i++) {
            char c = guess[i];
            if (sdic[c]) {
                sdic[c]--;
                cnt2++;
            }
        }

        //cout << cnt1 << " " << cnt2 << endl;

        return to_string(cnt1) + "A" + to_string(cnt2 - cnt1) + "B";
    }
};
