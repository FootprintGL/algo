

class Solution {
public:
    string originalDigits(string s) {
        /*
         * 找规律
         * zero, one, two, three, four, five, six, seven, eight, nine
         * 偶数标志性字符z - zero, w - two, u - four, x - six, g - eight
         * three/eight共有一个h, eight去掉之后，h - three
         * five/four共有一个f，four去掉以后，f - five
         * seven/six共有一个s，six去掉以后，s - seven
         * one/zero/two/four共有o, zero/two/four去掉以后，o - one
         * nine/five/six/eight共有i, five/six/eight去掉以后，i - nine
         */
        vector<int> cnt(26, 0);
        vector<int> out(10, 0);

        for (auto &c : s)
            cnt[c - 'a']++;

        out[0] = cnt['z' - 'a'];
        out[2] = cnt['w' - 'a'];
        out[4] = cnt['u' - 'a'];
        out[6] = cnt['x' - 'a'];
        out[8] = cnt['g' - 'a'];
        out[3] = cnt['h' - 'a'] - out[8];
        out[5] = cnt['f' - 'a'] - out[4];
        out[7] = cnt['s' - 'a'] - out[6];
        out[1] = cnt['o' - 'a'] - out[0] - out[2] - out[4];
        out[9] = cnt['i' - 'a'] - out[5] - out[6] - out[8];

        string res;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < out[i]; j++)
                res.push_back(i + '0');
        }

        return res;
    }
};
