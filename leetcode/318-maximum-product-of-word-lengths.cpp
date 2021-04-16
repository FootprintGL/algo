

class Solution {
public:
    int maxProduct(vector<string>& words) {
        /*
         * 怎么判断两个单词没有公共字母
         * 位元算，a - 0, b - 1用一个32为整型标记每个单词中出现的字母
         * 不相同同，两个位值的与为0
         */
        int n = words.size();
        vector<int> len(n);
        vector<int> mask(n);
        int tmask;

        for (int i = 0; i < n; i++) {
            tmask = 0;
            for (auto &c : words[i]) {
                tmask |= 1 << (c - 'a');
            }
            mask[i] = tmask;
            len[i] = words[i].length();
        }
        //cout << len.size() << " " << mask.size() << endl;

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j < n; j++) {
                if ((mask[i] & mask[j]) == 0)
                    res = max(res, len[i] * len[j]);
            }
        }

        return res;
    }
};
