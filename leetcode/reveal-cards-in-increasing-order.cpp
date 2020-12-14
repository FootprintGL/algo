

class Solution {
public:
    int n;

    /* 从start开始搜索下一个空格 */
    int next(vector<bool> &filled, int start) {
        for (int i = start; i < n; i++)
            if (filled[i] == false)
                return i;

        for (int i = 0; i < start; i++)
            if (filled[i] == false)
                return i;

        return -1;
    }

    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        /*
         * 约瑟夫问题: N个数字围成一圈，从0开始出圈，往后每次跳过一个出一个，求出圈序列
         * 本题: N个数字围成一圈，从0开始出圈，往后每次跳一个出一个，已知出圈序列递增，求原序列
         * 跳过空位找空位
         */
        n = deck.size();
        vector<int> res(n);
        vector<bool> filled(n, false);
        int index = 0;
        int p = 0;

        sort(deck.begin(), deck.end());
        while (1) {
            res[index] = deck[p++];
            filled[index] = true;
            index = next(filled, next(filled, index + 1) + 1);
            if (index == -1)
                break;
        }

        return res;
    }
};
